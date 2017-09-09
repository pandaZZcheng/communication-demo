/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   串口接发测试，串口接收到数据后马上回传。
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火  STM32 F429 开发板
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f4xx.h"
#include "./usart/bsp_debug_usart.h"
#include "./usart/bsp_rs232_usart.h"
#include "./tim/bsp_advance_tim.h"



/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{	
  
  uint8_t i = 0;
  /*初始化USART 配置模式为 115200 8-N-1，中断接收*/
  Debug_USART_Config();
	RS232_USART_Config();
  TIMx_Configuration();
	/* 发送一个字符串 */
  while(1)
	{	
    if(1 == Usart1_RX_Flag)
    {
      Usart_SendStr_length(RS232_USART, Usart1_rx_buf, Usart1_Current_cnt);
      Usart1_RX_Flag = 0;
    }

    if(1 == Usart2_RX_Flag)
    {
      //Usart_SendStr_length(DEBUG_USART, Usart2_rx_buf, Usart2_Current_cnt);
      for(i = 0; i < Usart2_Current_cnt; i++)
      {
        printf("%c", Usart2_rx_buf[i]);
      }
      printf("\r\n");
      Usart2_RX_Flag = 0;
    }

	}	
}



/*********************************************END OF FILE**********************/

