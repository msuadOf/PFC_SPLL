#include "PID_Controller.h"
#include <stdint.h>
#include "spll_sogi.h"
//typedef struct {
//    float A0;        /**< The derived gain, A0 = Kp + Ki + Kd . */
//    float A1;        /**< The derived gain, A1 = -Kp - 2Kd. */
//    float A2;        /**< The derived gain, A2 = Kd . */
//    float state[3];  /**< The state array of length 3. */
//    float Kp;        /**< The proportional gain. */
//    float Ki;        /**< The integral gain. */
//    float Kd;        /**< The derivative gain. */
//} PID_t;
//void arm_pid_init_f32(PID_t *S) {
//    /* Derived coefficient A0 */
//    S->A0 = S->Kp + S->Ki + S->Kd;
//    /* Derived coefficient A1 */
//    S->A1 = (-S->Kp) - ((float) 2.0f * S->Kd);
//    /* Derived coefficient A2 */
//    S->A2 = S->Kd;
//
//}
//float arm_pid_f32(PID_t * S, float in) {
//    arm_pid_init_f32(S);
//    float out;
//
//    /* u[t] = u[t - 1] + A0 * e[t] + A1 * e[t - 1] + A2 * e[t - 2]  */
//    out = (S->A0 * in) +
//      (S->A1 * S->state[0]) + (S->A2 * S->state[1]) + (S->state[2]);
//
//    /* Update state */
//    S->state[1] = S->state[0];
//    S->state[0] = in;
//    S->state[2] = out;
//
//    /* return to application */
//    return (out);
//}



float pid_process(PID_t* pid,float aim,float current){
    pid->error_last=pid->error;
    pid->error=aim-current;

    pid->error_sum+=pid->error;
    pid->error_div=pid->error-pid->error_last;

    pid->out+=(pid->Kp)*(pid->error_div)+(pid->Ki)*(pid->error)+(pid->Kd)*(pid->error_sum);
    if(pid->out>1000){
        pid->out=1000;
    }
    if(pid->out<0){
        pid->out=0;
    }
    return pid->out;
}

float DCDC_pid_process_with_limit(PID_t *pid, float aim, float current, float max, float min)
{
    //float out = arm_pid_f32(pid, aim - current);
    float out=pid_process(pid,aim,current);
    if (out > max)
        out = max;
    if (out < min)
        out = min;
    return out;
}
float PFC_outVol_pid_process_with_limit(PID_t *pid, float aim, float current, float max, float min)
{
    //float out = arm_pid_f32(pid, aim - current);
    float out=pid_process(pid,aim,current);
    if (out > max)
        out = max;
    if (out < min)
        out = min;
    return out;
}

PID_t pid_i_Cur={
    .Kp=2.5,
    .Ki=0.1,
    .Kd=0
};
PID_t pid_o_Vol={
    .Kp=2.5,
    .Ki=0.1,
    .Kd=0
};
float duty;
void PFC_Controller(float i_Vol,float i_Cur,float o_Vol,float* out){
    float Cur_pfc_out,Cur_ref,theta;
    float a;
    float *p=&a;
    float k=1;
    spll_Outputs_wrapper(&i_Vol,
                                  &theta,
                                  &Cur_pfc_out);
    //k=PFC_outVol_pid_process_with_limit(&pid_o_Vol,20,o_Vol,1,0);
    Cur_ref=k*Cur_pfc_out;
    *out=DCDC_pid_process_with_limit(&pid_i_Cur,Cur_ref,i_Cur,100,-100);


   //DCDC_HAL_setPWMout(duty);
}
