#ifndef __SERVO_H_
#define __SERVO_H_

#include "time.h"
#include <stm32f4xx.h>
#include "sys.h"

//void TIM4_PWM_Init(u16 arr,u16 psc);
void TIM2_PWM_Init(u32 arr,u32 psc);

#endif