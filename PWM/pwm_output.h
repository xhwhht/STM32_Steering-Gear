#ifndef __PWM_OUTPUT_H
#define __PWM_OUTPUT_H

#include "stm32f10x.h"



//#define ADVANCE_TIM_PSC (720-1)           //周期 分频数PSC
//#define ADVANCE_TIM_PERIOD (2000-1)        //计数个数ARR
//#define ADVANCE_TIM_PULSE 150   			//占空比  与ARR相比较

void TIM_Init(void);


#endif
