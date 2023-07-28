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

#include "board.h"

//*****************************************************************************
//
// Board Configurations
// Initializes the rest of the modules. 
// Call this function in your application if you wish to do all module 
// initialization.
// If you wish to not use some of the initializations, instead of the 
// Board_init use the individual Module_inits
//
//*****************************************************************************
void Board_init()
{
	EALLOW;

	PinMux_init();
	SYNC_init();
	ASYSCTL_init();
	ADC_init();
	EPWM_init();
	GPIO_init();
	SCI_init();
	INTERRUPT_init();

	EDIS;
}

//*****************************************************************************
//
// PINMUX Configurations
//
//*****************************************************************************
void PinMux_init()
{
	//
	// PinMux for modules assigned to CPU1
	//
	
	//
	// ANALOG -> myANALOGPinMux0 Pinmux
	//
	// Analog PinMux for A0/B15/C15/DACA_OUT
	GPIO_setPinConfig(GPIO_231_GPIO231);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(231, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A1/B7/DACB_OUT
	GPIO_setPinConfig(GPIO_232_GPIO232);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(232, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A2/B6/C9
	GPIO_setPinConfig(GPIO_224_GPIO224);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(224, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A3, C7/B9
	GPIO_setPinConfig(GPIO_229_GPIO229);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(229, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A4/B8
	GPIO_setPinConfig(GPIO_225_GPIO225);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(225, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A5
	GPIO_setPinConfig(GPIO_249_GPIO249);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(249, GPIO_ANALOG_ENABLED);
	// Analog PinMux for A6
	GPIO_setPinConfig(GPIO_228_GPIO228);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(228, GPIO_ANALOG_ENABLED);
	// Analog PinMux for B0/C11
	GPIO_setPinConfig(GPIO_253_GPIO253);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(253, GPIO_ANALOG_ENABLED);
	// Analog PinMux for C3/A7
	GPIO_setPinConfig(GPIO_245_GPIO245);
	// AIO -> Analog mode selected
	GPIO_setAnalogMode(245, GPIO_ANALOG_ENABLED);
	//
	// EPWM1 -> myEPWM0 Pinmux
	//
	GPIO_setPinConfig(myEPWM0_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(myEPWM0_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(myEPWM0_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(myEPWM0_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(myEPWM0_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(myEPWM0_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM2 -> myEPWM1 Pinmux
	//
	GPIO_setPinConfig(myEPWM1_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(myEPWM1_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(myEPWM1_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(myEPWM1_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(myEPWM1_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(myEPWM1_EPWMB_GPIO, GPIO_QUAL_SYNC);

	//
	// EPWM4 -> myEPWM3 Pinmux
	//
	GPIO_setPinConfig(myEPWM3_EPWMA_PIN_CONFIG);
	GPIO_setPadConfig(myEPWM3_EPWMA_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(myEPWM3_EPWMA_GPIO, GPIO_QUAL_SYNC);

	GPIO_setPinConfig(myEPWM3_EPWMB_PIN_CONFIG);
	GPIO_setPadConfig(myEPWM3_EPWMB_GPIO, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(myEPWM3_EPWMB_GPIO, GPIO_QUAL_SYNC);

	// B5, GPIO20 -> LED_onboard_R Pinmux
	GPIO_setPinConfig(GPIO_20_GPIO20);
	// AGPIO -> GPIO mode selected
	// On 100PZ package for F28003x, if "B5, GPIO20" is used in 
	// GPIO mode, then "B5" can be used for ADC
	// On 100PZ package for F28003x, if "B11, GPIO21" is used in 
	// GPIO mode, then "B11" can be used for ADC
	GPIO_setAnalogMode(20, GPIO_ANALOG_DISABLED);
	// GPIO22 -> LED_onboard_G Pinmux
	GPIO_setPinConfig(GPIO_22_GPIO22);
	//
	// SCIA -> mySCI0 Pinmux
	//
	GPIO_setPinConfig(mySCI0_SCIRX_PIN_CONFIG);
	GPIO_setPadConfig(mySCI0_SCIRX_GPIO, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(mySCI0_SCIRX_GPIO, GPIO_QUAL_ASYNC);

	GPIO_setPinConfig(mySCI0_SCITX_PIN_CONFIG);
	GPIO_setPadConfig(mySCI0_SCITX_GPIO, GPIO_PIN_TYPE_STD | GPIO_PIN_TYPE_PULLUP);
	GPIO_setQualificationMode(mySCI0_SCITX_GPIO, GPIO_QUAL_ASYNC);


}

//*****************************************************************************
//
// ADC Configurations
//
//*****************************************************************************
void ADC_init(){
	myADC0_init();
}

void myADC0_init(){
	//
	// ADC Initialization: Write ADC configurations and power up the ADC
	//
	// Configures the ADC module's offset trim
	//
	ADC_setOffsetTrimAll(ADC_REFERENCE_INTERNAL,ADC_REFERENCE_2_5V);
	//
	// Configures the analog-to-digital converter module prescaler.
	//
	ADC_setPrescaler(myADC0_BASE, ADC_CLK_DIV_1_0);
	//
	// Sets the timing of the end-of-conversion pulse
	//
	ADC_setInterruptPulseMode(myADC0_BASE, ADC_PULSE_END_OF_CONV);
	//
	// Powers up the analog-to-digital converter core.
	//
	ADC_enableConverter(myADC0_BASE);
	//
	// Delay for 1ms to allow ADC time to power up
	//
	DEVICE_DELAY_US(5000);
	//
	// SOC Configuration: Setup ADC EPWM channel and trigger settings
	//
	// Enables SOC burst mode.
	//
	ADC_enableBurstMode(myADC0_BASE);
	//
	// Set SOC burst mode.
	//
	ADC_setBurstModeConfig(myADC0_BASE, ADC_TRIGGER_EPWM4_SOCA, 8);
	//
	// Sets the priority mode of the SOCs.
	//
	ADC_setSOCPriority(myADC0_BASE, ADC_PRI_THRU_SOC7_HIPRI);
	//
	// Start of Conversion 8 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 8
	//	  	Trigger			: ADC_TRIGGER_EPWM4_SOCA
	//	  	Channel			: ADC_CH_ADCIN6
	//	 	Sample Window	: 1 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC0_BASE, ADC_SOC_NUMBER8, ADC_TRIGGER_EPWM4_SOCA, ADC_CH_ADCIN6, 1U);
	ADC_setInterruptSOCTrigger(myADC0_BASE, ADC_SOC_NUMBER8, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 9 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 9
	//	  	Trigger			: ADC_TRIGGER_EPWM4_SOCA
	//	  	Channel			: ADC_CH_ADCIN7
	//	 	Sample Window	: 1 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC0_BASE, ADC_SOC_NUMBER9, ADC_TRIGGER_EPWM4_SOCA, ADC_CH_ADCIN7, 1U);
	ADC_setInterruptSOCTrigger(myADC0_BASE, ADC_SOC_NUMBER9, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 10 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 10
	//	  	Trigger			: ADC_TRIGGER_EPWM4_SOCA
	//	  	Channel			: ADC_CH_ADCIN4
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC0_BASE, ADC_SOC_NUMBER10, ADC_TRIGGER_EPWM4_SOCA, ADC_CH_ADCIN4, 9U);
	ADC_setInterruptSOCTrigger(myADC0_BASE, ADC_SOC_NUMBER10, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 11 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 11
	//	  	Trigger			: ADC_TRIGGER_EPWM4_SOCA
	//	  	Channel			: ADC_CH_ADCIN5
	//	 	Sample Window	: 1 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC0_BASE, ADC_SOC_NUMBER11, ADC_TRIGGER_EPWM4_SOCA, ADC_CH_ADCIN5, 1U);
	ADC_setInterruptSOCTrigger(myADC0_BASE, ADC_SOC_NUMBER11, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 12 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 12
	//	  	Trigger			: ADC_TRIGGER_EPWM4_SOCA
	//	  	Channel			: ADC_CH_ADCIN0
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC0_BASE, ADC_SOC_NUMBER12, ADC_TRIGGER_EPWM4_SOCA, ADC_CH_ADCIN0, 9U);
	ADC_setInterruptSOCTrigger(myADC0_BASE, ADC_SOC_NUMBER12, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 13 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 13
	//	  	Trigger			: ADC_TRIGGER_EPWM4_SOCA
	//	  	Channel			: ADC_CH_ADCIN1
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC0_BASE, ADC_SOC_NUMBER13, ADC_TRIGGER_EPWM4_SOCA, ADC_CH_ADCIN1, 9U);
	ADC_setInterruptSOCTrigger(myADC0_BASE, ADC_SOC_NUMBER13, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 14 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 14
	//	  	Trigger			: ADC_TRIGGER_EPWM4_SOCA
	//	  	Channel			: ADC_CH_ADCIN2
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC0_BASE, ADC_SOC_NUMBER14, ADC_TRIGGER_EPWM4_SOCA, ADC_CH_ADCIN2, 9U);
	ADC_setInterruptSOCTrigger(myADC0_BASE, ADC_SOC_NUMBER14, ADC_INT_SOC_TRIGGER_NONE);
	//
	// Start of Conversion 15 Configuration
	//
	//
	// Configures a start-of-conversion (SOC) in the ADC and its interrupt SOC trigger.
	// 	  	SOC number		: 15
	//	  	Trigger			: ADC_TRIGGER_EPWM4_SOCA
	//	  	Channel			: ADC_CH_ADCIN3
	//	 	Sample Window	: 9 SYSCLK cycles
	//		Interrupt Trigger: ADC_INT_SOC_TRIGGER_NONE
	//
	ADC_setupSOC(myADC0_BASE, ADC_SOC_NUMBER15, ADC_TRIGGER_EPWM4_SOCA, ADC_CH_ADCIN3, 9U);
	ADC_setInterruptSOCTrigger(myADC0_BASE, ADC_SOC_NUMBER15, ADC_INT_SOC_TRIGGER_NONE);
	//
	// ADC Interrupt 1 Configuration
	// 		SOC/EOC number	: 15
	// 		Interrupt Source: enabled
	// 		Continuous Mode	: disabled
	//
	ADC_setInterruptSource(myADC0_BASE, ADC_INT_NUMBER1, ADC_SOC_NUMBER15);
	ADC_enableInterrupt(myADC0_BASE, ADC_INT_NUMBER1);
	ADC_clearInterruptStatus(myADC0_BASE, ADC_INT_NUMBER1);
	ADC_disableContinuousMode(myADC0_BASE, ADC_INT_NUMBER1);
}

//*****************************************************************************
//
// ASYSCTL Configurations
//
//*****************************************************************************
void ASYSCTL_init(){
	//
	// asysctl initialization
	//
	// Disables the temperature sensor output to the ADC.
	//
	ASysCtl_disableTemperatureSensor();
	//
	// Set the analog voltage reference selection to internal.
	//
	ASysCtl_setAnalogReferenceInternal( ASYSCTL_VREFHI );
	//
	// Set the internal analog voltage reference selection to 2.5V.
	//
	ASysCtl_setAnalogReference2P5( ASYSCTL_VREFHI);
}
//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
void EPWM_init(){
    HRPWM_enableGlobalLoad(myEPWM0_BASE);	
    HRPWM_setGlobalLoadEventPrescale(myEPWM0_BASE, 1);	
    HRPWM_setClockPrescaler(myEPWM0_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(myEPWM0_BASE, 2500);	
    HRPWM_setTimeBaseCounter(myEPWM0_BASE, 0);	
    HRPWM_setTimeBaseCounterMode(myEPWM0_BASE, EPWM_COUNTER_MODE_UP);	
    HRPWM_disablePhaseShiftLoad(myEPWM0_BASE);	
    HRPWM_setPhaseShift(myEPWM0_BASE, 0);	
    EPWM_enableSyncOutPulseSource(myEPWM0_BASE, EPWM_SYNC_OUT_PULSE_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(myEPWM0_BASE, EPWM_COUNTER_COMPARE_A, 1000);	
    HRPWM_setCounterCompareShadowLoadMode(myEPWM0_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(myEPWM0_BASE, EPWM_COUNTER_COMPARE_B, 0);	
    HRPWM_setCounterCompareShadowLoadMode(myEPWM0_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    HRPWM_setActionQualifierAction(myEPWM0_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    HRPWM_setActionQualifierAction(myEPWM0_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    HRPWM_setActionQualifierAction(myEPWM0_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    HRPWM_setActionQualifierAction(myEPWM0_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    HRPWM_setActionQualifierAction(myEPWM0_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    HRPWM_setActionQualifierAction(myEPWM0_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    HRPWM_setActionQualifierAction(myEPWM0_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    HRPWM_setActionQualifierAction(myEPWM0_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    HRPWM_setActionQualifierAction(myEPWM0_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    HRPWM_setActionQualifierAction(myEPWM0_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    HRPWM_setActionQualifierAction(myEPWM0_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    HRPWM_setActionQualifierAction(myEPWM0_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    HRPWM_setFallingEdgeDeadBandDelayInput(myEPWM0_BASE, EPWM_DB_INPUT_EPWMB);	
    HRPWM_setRisingEdgeDelayCount(myEPWM0_BASE, 30);	
    HRPWM_setFallingEdgeDelayCount(myEPWM0_BASE, 30);	
    HRPWM_setDeadBandCounterClock(myEPWM0_BASE, EPWM_DB_COUNTER_CLOCK_HALF_CYCLE);	
    HRPWM_enableADCTrigger(myEPWM0_BASE, EPWM_SOC_A);	
    HRPWM_setADCTriggerSource(myEPWM0_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_ZERO);	
    HRPWM_setADCTriggerEventPrescale(myEPWM0_BASE, EPWM_SOC_A, 1);	
    HRPWM_enableAutoConversion(myEPWM0_BASE);	
    HRPWM_setMEPEdgeSelect(myEPWM0_BASE, HRPWM_CHANNEL_A, HRPWM_MEP_CTRL_FALLING_EDGE);	
    HRPWM_setHiResCounterCompareValueOnly(myEPWM0_BASE, HRPWM_COUNTER_COMPARE_A, 50);	
    HRPWM_setMEPEdgeSelect(myEPWM0_BASE, HRPWM_CHANNEL_B, HRPWM_MEP_CTRL_FALLING_EDGE);	
    HRPWM_setHiResCounterCompareValueOnly(myEPWM0_BASE, HRPWM_COUNTER_COMPARE_B, 50);	
    HRPWM_setDeadbandMEPEdgeSelect(myEPWM0_BASE, HRPWM_DB_MEP_CTRL_RED_FED);	
    HRPWM_setChannelBOutputPath(myEPWM0_BASE, HRPWM_OUTPUT_ON_B_INV_A);	
    HRPWM_enableGlobalLoad(myEPWM1_BASE);	
    HRPWM_setGlobalLoadEventPrescale(myEPWM1_BASE, 1);	
    HRPWM_setupEPWMLinks(myEPWM1_BASE, EPWM_LINK_WITH_EPWM_1, EPWM_LINK_GLDCTL2);	
    HRPWM_setClockPrescaler(myEPWM1_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(myEPWM1_BASE, 2500);	
    HRPWM_setupEPWMLinks(myEPWM1_BASE, EPWM_LINK_WITH_EPWM_1, EPWM_LINK_TBPRD);	
    HRPWM_setTimeBaseCounter(myEPWM1_BASE, 0);	
    HRPWM_setTimeBaseCounterMode(myEPWM1_BASE, EPWM_COUNTER_MODE_UP);	
    HRPWM_disablePhaseShiftLoad(myEPWM1_BASE);	
    HRPWM_setPhaseShift(myEPWM1_BASE, 0);	
    EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, 1000);	
    HRPWM_setCounterCompareShadowLoadMode(myEPWM1_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    HRPWM_setupEPWMLinks(myEPWM1_BASE, EPWM_LINK_WITH_EPWM_1, EPWM_LINK_COMP_A);	
    EPWM_setCounterCompareValue(myEPWM1_BASE, EPWM_COUNTER_COMPARE_B, 0);	
    HRPWM_setCounterCompareShadowLoadMode(myEPWM1_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    HRPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    HRPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    HRPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    HRPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    HRPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    HRPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    HRPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    HRPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    HRPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    HRPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    HRPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    HRPWM_setActionQualifierAction(myEPWM1_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    HRPWM_setFallingEdgeDeadBandDelayInput(myEPWM1_BASE, EPWM_DB_INPUT_EPWMB);	
    HRPWM_setRisingEdgeDelayCount(myEPWM1_BASE, 30);	
    HRPWM_setFallingEdgeDelayCount(myEPWM1_BASE, 30);	
    HRPWM_setDeadBandCounterClock(myEPWM1_BASE, EPWM_DB_COUNTER_CLOCK_HALF_CYCLE);	
    HRPWM_enableAutoConversion(myEPWM1_BASE);	
    HRPWM_setMEPEdgeSelect(myEPWM1_BASE, HRPWM_CHANNEL_A, HRPWM_MEP_CTRL_RISING_AND_FALLING_EDGE);	
    HRPWM_setHiResCounterCompareValueOnly(myEPWM1_BASE, HRPWM_COUNTER_COMPARE_A, 50);	
    HRPWM_setDeadbandMEPEdgeSelect(myEPWM1_BASE, HRPWM_DB_MEP_CTRL_RED_FED);	
    HRPWM_setChannelBOutputPath(myEPWM1_BASE, HRPWM_OUTPUT_ON_B_INV_A);	
    EPWM_setClockPrescaler(myEPWM3_BASE, EPWM_CLOCK_DIVIDER_1, EPWM_HSCLOCK_DIVIDER_1);	
    EPWM_setTimeBasePeriod(myEPWM3_BASE, 2399);	
    EPWM_setTimeBaseCounter(myEPWM3_BASE, 0);	
    EPWM_setTimeBaseCounterMode(myEPWM3_BASE, EPWM_COUNTER_MODE_UP);	
    EPWM_disablePhaseShiftLoad(myEPWM3_BASE);	
    EPWM_setPhaseShift(myEPWM3_BASE, 0);	
    EPWM_setSyncInPulseSource(myEPWM3_BASE, EPWM_SYNC_IN_PULSE_SRC_DISABLE);	
    EPWM_setCounterCompareValue(myEPWM3_BASE, EPWM_COUNTER_COMPARE_A, 1200);	
    EPWM_setCounterCompareShadowLoadMode(myEPWM3_BASE, EPWM_COUNTER_COMPARE_A, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setCounterCompareValue(myEPWM3_BASE, EPWM_COUNTER_COMPARE_B, 0);	
    EPWM_setCounterCompareShadowLoadMode(myEPWM3_BASE, EPWM_COUNTER_COMPARE_B, EPWM_COMP_LOAD_ON_CNTR_ZERO);	
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_HIGH, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_LOW, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_A, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_ZERO);	
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_PERIOD);	
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPA);	
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPA);	
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_UP_CMPB);	
    EPWM_setActionQualifierAction(myEPWM3_BASE, EPWM_AQ_OUTPUT_B, EPWM_AQ_OUTPUT_NO_CHANGE, EPWM_AQ_OUTPUT_ON_TIMEBASE_DOWN_CMPB);	
    EPWM_enableADCTrigger(myEPWM3_BASE, EPWM_SOC_A);	
    EPWM_setADCTriggerSource(myEPWM3_BASE, EPWM_SOC_A, EPWM_SOC_TBCTR_ZERO);	
    EPWM_setADCTriggerEventPrescale(myEPWM3_BASE, EPWM_SOC_A, 1);	
}

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
void GPIO_init(){
	LED_onboard_R_init();
	LED_onboard_G_init();
}

void LED_onboard_R_init(){
	GPIO_writePin(LED_onboard_R, 0);
	GPIO_setPadConfig(LED_onboard_R, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(LED_onboard_R, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(LED_onboard_R, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(LED_onboard_R, GPIO_CORE_CPU1);
}
void LED_onboard_G_init(){
	GPIO_writePin(LED_onboard_G, 0);
	GPIO_setPadConfig(LED_onboard_G, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(LED_onboard_G, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(LED_onboard_G, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(LED_onboard_G, GPIO_CORE_CPU1);
}

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************
void INTERRUPT_init(){
	
	// Interrupt Setings for INT_myADC0_1
	Interrupt_register(INT_myADC0_1, &INT_myADC0_1_ISR);
	Interrupt_enable(INT_myADC0_1);
}
//*****************************************************************************
//
// SCI Configurations
//
//*****************************************************************************
void SCI_init(){
	mySCI0_init();
}

void mySCI0_init(){
	SCI_clearInterruptStatus(mySCI0_BASE, SCI_INT_RXFF | SCI_INT_TXFF | SCI_INT_FE | SCI_INT_OE | SCI_INT_PE | SCI_INT_RXERR | SCI_INT_RXRDY_BRKDT | SCI_INT_TXRDY);
	SCI_clearOverflowStatus(mySCI0_BASE);
	SCI_disableFIFO(mySCI0_BASE);
	SCI_resetChannels(mySCI0_BASE);
	SCI_setConfig(mySCI0_BASE, DEVICE_LSPCLK_FREQ, mySCI0_BAUDRATE, (SCI_CONFIG_WLEN_8|SCI_CONFIG_STOP_ONE|SCI_CONFIG_PAR_NONE));
	SCI_disableLoopback(mySCI0_BASE);
	SCI_performSoftwareReset(mySCI0_BASE);
	SCI_enableModule(mySCI0_BASE);
}

//*****************************************************************************
//
// SYNC Scheme Configurations
//
//*****************************************************************************
void SYNC_init(){
	SysCtl_setSyncOutputConfig(SYSCTL_SYNC_OUT_SRC_EPWM1SYNCOUT);
	//
	// SOCA
	//
	SysCtl_enableExtADCSOCSource(0);
	//
	// SOCB
	//
	SysCtl_enableExtADCSOCSource(0);
}
