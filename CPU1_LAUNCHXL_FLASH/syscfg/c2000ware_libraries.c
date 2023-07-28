/*
 * Copyright (c) 2021 Texas Instruments Incorporated - http://www.ti.com
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

#include "c2000ware_libraries.h"


void C2000Ware_libraries_init()
{
    HRPWM_SFO_init();
}


//
// HRWPM SFO Global Variables
//
int MEP_ScaleFactor; // Global variable used by the SFO library
                     // Result can be used for all HRPWM channels
                     // This variable is also copied to HRMSTEP
                     // register by SFO() function.


volatile uint32_t ePWM[] = {EPWM1_BASE,EPWM2_BASE,EPWM3_BASE,EPWM4_BASE,EPWM5_BASE,EPWM6_BASE,EPWM7_BASE,EPWM8_BASE};



// Initialization Function
void SFO_init(){
    //
    // Calling SFO() updates the HRMSTEP register with calibrated MEP_ScaleFactor.
    // HRMSTEP must be populated with a scale factor value prior to enabling
    // high resolution period control.
    //
    uint16_t status;
    status = SFO();
    while(status == SFO_INCOMPLETE)
    {
        status = SFO();
        if(status == SFO_ERROR)
        {
            ESTOP0;   // SFO function returns 2 if an error occurs & # of MEP
        }              // steps/coarse step exceeds maximum of 255.
    }
} 

// Run-Time Function Call
void SFO_runtime(){
     //
     // Call the scale factor optimizer lib function SFO()
     // periodically to track for any change due to temp/voltage.
     // This function generates MEP_ScaleFactor by running the
     // MEP calibration module in the HRPWM logic. This scale
     // factor can be used for all HRPWM channels. The SFO()
     // function also updates the HRMSTEP register with the
     // scale factor value.
     //
     uint16_t status;
     status = SFO(); // in background, MEP calibration module
                     // continuously updates MEP_ScaleFactor

     if (status == SFO_ERROR)
     {
         ESTOP0;   // SFO function returns 2 if an error occurs & #
                    // of MEP steps/coarse step
     }              // exceeds maximum of 255.
} 

void HRPWM_SFO_init(){
    SFO_init();       
}

