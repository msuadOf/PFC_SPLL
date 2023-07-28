/*
 * PID_Controller.h
 *
 *  Created on: 2023年7月27日
 *      Author: Lsuad
 */

#ifndef PID_CONTROLLER_H_
#define PID_CONTROLLER_H_

typedef struct {
    float A0;        /**< The derived gain, A0 = Kp + Ki + Kd . */
    float A1;        /**< The derived gain, A1 = -Kp - 2Kd. */
    float A2;        /**< The derived gain, A2 = Kd . */
    float state[3];  /**< The state array of length 3. */
    float Kp;        /**< The proportional gain. */
    float Ki;        /**< The integral gain. */
    float Kd;        /**< The derivative gain. */
    float error_sum;
    float error;
    float error_last;
    float error_div;
    float out;
} PID_t;

void PFC_Controller(float i_Vol,float i_Cur,float o_Vol,float* Duty);
#endif /* PID_CONTROLLER_H_ */
