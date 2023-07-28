//#############################################################################
//
// FILE:   empty_driverlib_main.c
//
//! \addtogroup driver_example_list
//! <h1>Empty Project Example</h1> 
//!
//! This example is an empty project setup for Driverlib development.
//!
//
//#############################################################################
//
//
// $Copyright:
// Copyright (C) 2023 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//#############################################################################

//
// Included Files
//
#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "c2000ware_libraries.h"

#include "spll_sogi.h"
#include "pfc_hal.h"

#include "stdio.h"
#include "stdlib.h"
#include "stdarg.h"

#include "bsp/bsp.h"
#define _INT_ON
#define ADC_Vref 2.5f
int a=1250-500;
int b=1250+500;
int c=2500;

#define RESULTS_BUFFER_SIZE     256
uint16_t myADC0Results[4][RESULTS_BUFFER_SIZE];   // Buffer for results
uint16_t index;                              // Index into result buffer

float32_t ADCA_Vol[8];

float32_t ADC_Vol[4];
float32_t out,theta;
float32_t acValue;
float i_Vol,i_Cur,o_Vol;
__interrupt void INT_myADC0_1_ISR(void)
{
    GPIO_writePin(LED_onboard_R,0);
#ifdef _INT_ON
    //
    // Add the latest result to the buffer
    //
    //myADC_result=ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER0);
    ADCA_Vol[0] = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER12)*ADC_Vref/4096.0f;
    ADCA_Vol[1] = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER13)*ADC_Vref/4096.0f;
    ADCA_Vol[2] = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER14)*ADC_Vref/4096.0f;
    ADCA_Vol[3] = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER15)*ADC_Vref/4096.0f;
    ADCA_Vol[4] = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER8)*ADC_Vref/4096.0f;
    ADCA_Vol[5] = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER9)*ADC_Vref/4096.0f;
    ADCA_Vol[6] = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER10)*ADC_Vref/4096.0f;
    ADCA_Vol[7] = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER11)*ADC_Vref/4096.0f;

    int i=0;
    for(i=0;i<4;i++){
        ADC_Vol[i]=ADCA_Vol[i*2+1]-ADCA_Vol[i*2];
    }
//    myADC0Results[0][index] = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER0);
//    myADC0Results[1][index] = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER1);
//    myADC0Results[2][index] = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER2);
//    myADC0Results[3][index] = ADC_readResult(ADCARESULT_BASE, ADC_SOC_NUMBER3);


    acValue=ADCA_Vol[0]-1.25f;
    float32_t duty;
    PFC_Controller(acValue, i_Cur, o_Vol,&duty);
    duty=(0.5f*(out+100))/100;
    duty=0.4;
    PFC_hal_epwm_set_duty(duty);
#endif

//    //
//    // Set the bufferFull flag if the buffer is full
//    //
//
//    if(index<(RESULTS_BUFFER_SIZE-1))
//    {
//        index++;
//    }
//    else
//    {
//        index=0;
//    }

    //
    // Clear the interrupt flag
    //
    ADC_clearInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1);

    //
    // Check if overflow has occurred
    //
    if(true == ADC_getInterruptOverflowStatus(myADC0_BASE, ADC_INT_NUMBER1))
    {
        ADC_clearInterruptOverflowStatus(myADC0_BASE, ADC_INT_NUMBER1);
        ADC_clearInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1);
    }

    //
    // Acknowledge the interrupt
    //
    Interrupt_clearACKGroup(INT_myADC0_1_INTERRUPT_ACK_GROUP);
    GPIO_writePin(LED_onboard_R,1);
}
//uint16_t myADC_result;


uint8_t tx_buff[200];
extern SPLL_1PH_SOGI spll1;
//
// Main
//
void main(void)
{

    //
    // Initialize device clock and peripherals
    //
    Device_init();

    //
    // Disable pin locks and enable internal pull-ups.
    //
    Device_initGPIO();

    //
    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    //
    Interrupt_initModule();

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();


    // Disable sync(Freeze clock to PWM as well). GTBCLKSYNC is applicable
    // only for multiple core devices. Uncomment the below statement if
    // applicable.
    //
    // SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_GTBCLKSYNC);
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);


    //
    // PinMux and Peripheral Initialization
    //
    Board_init();


    //
    // Enable sync and clock to PWM
    //
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

    //
    // C2000Ware Library initialization
    //
    C2000Ware_libraries_init();

    //
    // Enable Global Interrupt (INTM) and real time interrupt (DBGM)
    //
    EINT;
    ERTM;

//    HWREGH(myEPWM0_BASE + EPWM_O_TBCTR)=0;
//    HWREGH(myEPWM1_BASE + EPWM_O_TBCTR)=0;

    //
    // Start ePWM1, enabling SOCA and putting the counter in up-count mode
    //
    //EPWM_enableADCTrigger(EPWM1_BASE, EPWM_SOC_A);
    float pi=(float)1.0f;
    float a=cos(pi);  // FPU32
    float b=__sin((float)(3.14/4));   // TMU
    float c=a*b;
    SFO_runtime();
    spll_Start_wrapper();
    bsp_DebugSCI_init();
    while(1)
    {
#ifdef _INT_ON
        printf("sin:%d,%d,%d\n",(int)(spll1.sine*1000),(int)(acValue*1000),(int)(spll1.theta*1000));
        //SCI_write(tx_buff,50);
        //UART_printf("45\n");
        //DEVICE_DELAY_US(1000000/2);
        //GPIO_togglePin(LED_onboard_R);
        //EPWM_setTimeBasePeriod(myEPWM0_BASE,c);
        //EPWM_setCounterCompareValue(myEPWM0_BASE,EPWM_COUNTER_COMPARE_A,a);
        //EPWM_setCounterCompareValue(myEPWM1_BASE,EPWM_COUNTER_COMPARE_A,b);
        //PFC_hal_epwm_set_duty(0.4567);

        /*
        GPIO_writePin(LED_onboard_R,GPIO_readPin(21));
        */
        SFO_runtime();
#endif
    }
}





//
// End of File
//
