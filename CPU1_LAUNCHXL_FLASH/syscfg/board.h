/*
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef BOARD_H
#define BOARD_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//
// Included Files
//

#include "driverlib.h"
#include "device.h"

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************

//
// ANALOG -> myANALOGPinMux0 Pinmux
//

//
// EPWM1 -> myEPWM0 Pinmux
//
//
// EPWM1_A - GPIO Settings
//
#define GPIO_PIN_EPWM1_A 0
#define myEPWM0_EPWMA_GPIO 0
#define myEPWM0_EPWMA_PIN_CONFIG GPIO_0_EPWM1_A
//
// EPWM1_B - GPIO Settings
//
#define GPIO_PIN_EPWM1_B 1
#define myEPWM0_EPWMB_GPIO 1
#define myEPWM0_EPWMB_PIN_CONFIG GPIO_1_EPWM1_B

//
// EPWM2 -> myEPWM1 Pinmux
//
//
// EPWM2_A - GPIO Settings
//
#define GPIO_PIN_EPWM2_A 2
#define myEPWM1_EPWMA_GPIO 2
#define myEPWM1_EPWMA_PIN_CONFIG GPIO_2_EPWM2_A
//
// EPWM2_B - GPIO Settings
//
#define GPIO_PIN_EPWM2_B 3
#define myEPWM1_EPWMB_GPIO 3
#define myEPWM1_EPWMB_PIN_CONFIG GPIO_3_EPWM2_B

//
// EPWM4 -> myEPWM3 Pinmux
//
//
// EPWM4_A - GPIO Settings
//
#define GPIO_PIN_EPWM4_A 6
#define myEPWM3_EPWMA_GPIO 6
#define myEPWM3_EPWMA_PIN_CONFIG GPIO_6_EPWM4_A
//
// EPWM4_B - GPIO Settings
//
#define GPIO_PIN_EPWM4_B 23
#define myEPWM3_EPWMB_GPIO 23
#define myEPWM3_EPWMB_PIN_CONFIG GPIO_23_EPWM4_B
//
// GPIO20 - GPIO Settings
//
#define LED_onboard_R_GPIO_PIN_CONFIG GPIO_20_GPIO20
//
// GPIO22 - GPIO Settings
//
#define LED_onboard_G_GPIO_PIN_CONFIG GPIO_22_GPIO22

//
// SCIA -> mySCI0 Pinmux
//
//
// SCIA_RX - GPIO Settings
//
#define GPIO_PIN_SCIA_RX 28
#define mySCI0_SCIRX_GPIO 28
#define mySCI0_SCIRX_PIN_CONFIG GPIO_28_SCIA_RX
//
// SCIA_TX - GPIO Settings
//
#define GPIO_PIN_SCIA_TX 29
#define mySCI0_SCITX_GPIO 29
#define mySCI0_SCITX_PIN_CONFIG GPIO_29_SCIA_TX

//*****************************************************************************
//
// ADC Configurations
//
//*****************************************************************************
#define myADC0_BASE ADCA_BASE
#define myADC0_RESULT_BASE ADCARESULT_BASE
#define myADC0_SOC8 ADC_SOC_NUMBER8
#define myADC0_FORCE_SOC8 ADC_FORCE_SOC8
#define myADC0_SAMPLE_WINDOW_SOC8 8.333333333333334
#define myADC0_TRIGGER_SOURCE_SOC8 ADC_TRIGGER_EPWM4_SOCA
#define myADC0_CHANNEL_SOC8 ADC_CH_ADCIN6
#define myADC0_SOC9 ADC_SOC_NUMBER9
#define myADC0_FORCE_SOC9 ADC_FORCE_SOC9
#define myADC0_SAMPLE_WINDOW_SOC9 8.333333333333334
#define myADC0_TRIGGER_SOURCE_SOC9 ADC_TRIGGER_EPWM4_SOCA
#define myADC0_CHANNEL_SOC9 ADC_CH_ADCIN7
#define myADC0_SOC10 ADC_SOC_NUMBER10
#define myADC0_FORCE_SOC10 ADC_FORCE_SOC10
#define myADC0_SAMPLE_WINDOW_SOC10 75
#define myADC0_TRIGGER_SOURCE_SOC10 ADC_TRIGGER_EPWM4_SOCA
#define myADC0_CHANNEL_SOC10 ADC_CH_ADCIN4
#define myADC0_SOC11 ADC_SOC_NUMBER11
#define myADC0_FORCE_SOC11 ADC_FORCE_SOC11
#define myADC0_SAMPLE_WINDOW_SOC11 8.333333333333334
#define myADC0_TRIGGER_SOURCE_SOC11 ADC_TRIGGER_EPWM4_SOCA
#define myADC0_CHANNEL_SOC11 ADC_CH_ADCIN5
#define myADC0_SOC12 ADC_SOC_NUMBER12
#define myADC0_FORCE_SOC12 ADC_FORCE_SOC12
#define myADC0_SAMPLE_WINDOW_SOC12 75
#define myADC0_TRIGGER_SOURCE_SOC12 ADC_TRIGGER_EPWM4_SOCA
#define myADC0_CHANNEL_SOC12 ADC_CH_ADCIN0
#define myADC0_SOC13 ADC_SOC_NUMBER13
#define myADC0_FORCE_SOC13 ADC_FORCE_SOC13
#define myADC0_SAMPLE_WINDOW_SOC13 75
#define myADC0_TRIGGER_SOURCE_SOC13 ADC_TRIGGER_EPWM4_SOCA
#define myADC0_CHANNEL_SOC13 ADC_CH_ADCIN1
#define myADC0_SOC14 ADC_SOC_NUMBER14
#define myADC0_FORCE_SOC14 ADC_FORCE_SOC14
#define myADC0_SAMPLE_WINDOW_SOC14 75
#define myADC0_TRIGGER_SOURCE_SOC14 ADC_TRIGGER_EPWM4_SOCA
#define myADC0_CHANNEL_SOC14 ADC_CH_ADCIN2
#define myADC0_SOC15 ADC_SOC_NUMBER15
#define myADC0_FORCE_SOC15 ADC_FORCE_SOC15
#define myADC0_SAMPLE_WINDOW_SOC15 75
#define myADC0_TRIGGER_SOURCE_SOC15 ADC_TRIGGER_EPWM4_SOCA
#define myADC0_CHANNEL_SOC15 ADC_CH_ADCIN3
void myADC0_init();


//*****************************************************************************
//
// ASYSCTL Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
#define myEPWM0_BASE EPWM1_BASE
#define myEPWM0_TBPRD 2500
#define myEPWM0_COUNTER_MODE EPWM_COUNTER_MODE_UP
#define myEPWM0_TBPHS 0
#define myEPWM0_CMPA 1000
#define myEPWM0_CMPB 0
#define myEPWM0_CMPC 0
#define myEPWM0_CMPD 0
#define myEPWM0_DBRED 30
#define myEPWM0_DBFED 30
#define myEPWM0_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define myEPWM0_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define myEPWM0_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define myEPWM1_BASE EPWM2_BASE
#define myEPWM1_TBPRD 2500
#define myEPWM1_COUNTER_MODE EPWM_COUNTER_MODE_UP
#define myEPWM1_TBPHS 0
#define myEPWM1_CMPA 1000
#define myEPWM1_CMPB 0
#define myEPWM1_CMPC 0
#define myEPWM1_CMPD 0
#define myEPWM1_DBRED 30
#define myEPWM1_DBFED 30
#define myEPWM1_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define myEPWM1_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define myEPWM1_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define myEPWM3_BASE EPWM4_BASE
#define myEPWM3_TBPRD 2399
#define myEPWM3_COUNTER_MODE EPWM_COUNTER_MODE_UP
#define myEPWM3_TBPHS 0
#define myEPWM3_CMPA 1200
#define myEPWM3_CMPB 0
#define myEPWM3_CMPC 0
#define myEPWM3_CMPD 0
#define myEPWM3_DBRED 0
#define myEPWM3_DBFED 0
#define myEPWM3_TZA_ACTION EPWM_TZ_ACTION_HIGH_Z
#define myEPWM3_TZB_ACTION EPWM_TZ_ACTION_HIGH_Z
#define myEPWM3_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
#define LED_onboard_R 20
void LED_onboard_R_init();
#define LED_onboard_G 22
void LED_onboard_G_init();

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************

// Interrupt Settings for INT_myADC0_1
#define INT_myADC0_1 INT_ADCA1
#define INT_myADC0_1_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void INT_myADC0_1_ISR(void);

//*****************************************************************************
//
// SCI Configurations
//
//*****************************************************************************
#define mySCI0_BASE SCIA_BASE
#define mySCI0_BAUDRATE 115200
#define mySCI0_CONFIG_WLEN SCI_CONFIG_WLEN_8
#define mySCI0_CONFIG_STOP SCI_CONFIG_STOP_ONE
#define mySCI0_CONFIG_PAR SCI_CONFIG_PAR_NONE
void mySCI0_init();

//*****************************************************************************
//
// SYNC Scheme Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void	Board_init();
void	ADC_init();
void	ASYSCTL_init();
void	EPWM_init();
void	GPIO_init();
void	INTERRUPT_init();
void	SCI_init();
void	SYNC_init();
void	PinMux_init();

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif  // end of BOARD_H definition
