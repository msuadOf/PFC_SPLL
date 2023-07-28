/*
 * pfc.h
 *
 *  Created on: 2023��7��26��
 *      Author: Lsuad
 */

#ifndef PFC_HAL_H_
#define PFC_HAL_H_
#define CLAMP(x,max,min) ((x<max)?((x>min)?x:min):max)
#include "driverlib.h"
#include "device.h"
#include "board.h"
#include "c2000ware_libraries.h"
inline void HAL_epwm_set_period(uint32_t base,float Freq_khz){
    uint16_t periodCount=120.0f*1000.0f/Freq_khz;
    EPWM_setTimeBasePeriod(base,periodCount);
}
inline void PFC_hal_epwm_set_period(float Freq_khz){
    HAL_epwm_set_period(EPWM1_BASE,Freq_khz);
    HAL_epwm_set_period(EPWM2_BASE,Freq_khz);
}
inline void HAL_pwm_set_duty(uint32_t base,float duty){

        duty=CLAMP(duty,1,0);

            //float count = ((duty*100) * (float)(EPWM_TIMER_TBPRD << 8))/100;
//            float count = ((duty*100) * (float)(EPWM_TIMER_TBPRD << 8))/100;
        unsigned long ARR=EPWM_getTimeBasePeriod(base);
        float count = duty*(float)( (ARR) << 8) ;

            uint32_t compCount = (count);
            HRPWM_setCounterCompareValue(base, HRPWM_COUNTER_COMPARE_A, compCount);
            //HRPWM_setCounterCompareValue(EPWM2_BASE, HRPWM_COUNTER_COMPARE_B, compCount);

}
inline void PFC_hal_epwm_set_duty(float duty){
    CLAMP(duty,0.95,0.05);
    HAL_pwm_set_duty(EPWM1_BASE,duty);
    HAL_pwm_set_duty(EPWM2_BASE,duty);
}
#endif /* PFC_HAL_H_ */
