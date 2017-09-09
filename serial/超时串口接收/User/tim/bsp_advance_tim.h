#ifndef __ADVANCE_TIM_H
#define	__ADVANCE_TIM_H

#include "stm32f4xx.h"

#define ADVANCE_TIM           		TIM1
#define ADVANCE_TIM_CLK       		RCC_APB2Periph_TIM1

#define ADVANCE_TIM_IRQn					TIM1_UP_TIM10_IRQn
#define ADVANCE_TIM_IRQHandler    TIM1_UP_TIM10_IRQHandler

#define ADVANCE_TIM8           		TIM8
#define ADVANCE_TIM8_CLK       		RCC_APB2Periph_TIM8

#define ADVANCE_TIM8_IRQn					TIM8_UP_TIM13_IRQn
#define ADVANCE_TIM8_IRQHandler    TIM8_UP_TIM13_IRQHandler

extern uint8_t Usart1_RX_Flag, Usart2_RX_Flag,
Usart1_Current_cnt, Usart2_Current_cnt,
Usart1_REC_cnt, Usart2_REC_cnt,
Tim1_cnt, Tim8_cnt;

void TIMx_Configuration(void);

#endif /* __ADVANCE_TIM_H */

