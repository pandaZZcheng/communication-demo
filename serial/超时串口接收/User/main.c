/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   ���ڽӷ����ԣ����ڽ��յ����ݺ����ϻش���
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:����  STM32 F429 ������
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f4xx.h"
#include "./usart/bsp_debug_usart.h"
#include "./usart/bsp_rs232_usart.h"
#include "./tim/bsp_advance_tim.h"



/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{	
  
  uint8_t i = 0;
  /*��ʼ��USART ����ģʽΪ 115200 8-N-1���жϽ���*/
  Debug_USART_Config();
	RS232_USART_Config();
  TIMx_Configuration();
	/* ����һ���ַ��� */
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

