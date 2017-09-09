/**
  ******************************************************************************
  * @file    Project/STM32F4xx_StdPeriph_Templates/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V1.5.0
  * @date    06-March-2015
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2015 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_it.h"
#include "./usart/bsp_debug_usart.h"
#include "./tim/bsp_advance_tim.h"
#include "./usart/bsp_rs232_usart.h"
/** @addtogroup STM32F429I_DISCOVERY_Examples
  * @{
  */

/** @addtogroup FMC_SDRAM
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {}
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {}
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {}
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {}
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{}

/**
  * @brief  This function handles PendSV_Handler exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{}

/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f429_439xx.s).                         */
/******************************************************************************/
void DEBUG_USART_IRQHandler(void)
{
	if(USART_GetITStatus(DEBUG_USART,USART_IT_RXNE)!=RESET)
	{	
    USART_ClearITPendingBit(DEBUG_USART, USART_IT_RXNE);	
    Usart1_rx_buf[Usart1_REC_cnt] = USART_ReceiveData( DEBUG_USART );
    Usart1_REC_cnt += 1;
    TIM_ITConfig(ADVANCE_TIM, TIM_IT_Update, ENABLE);
    TIM_SetCounter(ADVANCE_TIM, 0); 
    Tim1_cnt = 0;  
	}	 
}	
  

void ADVANCE_TIM_IRQHandler(void)
{
  if(TIM_GetITStatus(ADVANCE_TIM, TIM_IT_Update) != RESET)
  {
    TIM_ClearITPendingBit(ADVANCE_TIM, TIM_IT_Update);
    if(Tim1_cnt < 100)
    {
      Tim1_cnt += 1;
    }
    if(Tim1_cnt >= 3)
    {
      TIM_ITConfig(ADVANCE_TIM, TIM_IT_Update, DISABLE);
      Usart1_RX_Flag = 1;
      Usart1_Current_cnt = Usart1_REC_cnt;
      Usart1_REC_cnt = 0;
    }
  }
}

void ADVANCE_TIM8_IRQHandler(void)
{
  if(TIM_GetITStatus(ADVANCE_TIM8, TIM_IT_Update) != RESET)
  {
    TIM_ClearITPendingBit(ADVANCE_TIM8, TIM_IT_Update);
    if(Tim8_cnt < 100)
    {
      Tim8_cnt += 1;
    }
    if(Tim8_cnt >= 3)
    {
      TIM_ITConfig(ADVANCE_TIM8, TIM_IT_Update, DISABLE);
      Usart2_RX_Flag = 1;
      Usart2_Current_cnt = Usart2_REC_cnt;
      Usart2_REC_cnt = 0;
    }
  }
}

void RS232_USART_IRQHandler(void)
{
  if(USART_GetITStatus(RS232_USART,USART_IT_RXNE)!=RESET)
	{	
    USART_ClearITPendingBit(RS232_USART, USART_IT_RXNE);	
    Usart2_rx_buf[Usart2_REC_cnt] = USART_ReceiveData( RS232_USART );
    Usart2_REC_cnt += 1;
    TIM_ITConfig(ADVANCE_TIM8, TIM_IT_Update, ENABLE);
    TIM_SetCounter(ADVANCE_TIM8, 0); 
    Tim8_cnt = 0;  
	}
}
/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
