/**
  ******************************************************************************
  * @file    main.c
  * @author  LYC
  * @version V1.0
  * @date    2014-04-22
  * @brief   ����MPU6050 DMP��ʾ����
  ******************************************************************************
  * @attention
  * ʵ��ƽ̨:���� F103-MINI STM32 ������ 
  ******************************************************************************
  */
  
#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "./systick/bsp_SysTick.h"
#include "./usart/bsp_usart.h"
#include "./i2c/bsp_i2c.h"
#include "./exti/bsp_exti.h" 
#include "OLED.h"
#include "myh.h" 
#include "pwm_output.h"

/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
	
float Pitch=0,Roll=0,Yaw=0;

void bsp_init()
{
	
	SysTick_Init();
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk;

	/* ����ͨ�ų�ʼ�� */
	USART_Config();

	//MPU6050�ж�����
	EXTI_Pxy_Config();
	//I2C��ʼ��
	I2C_Bus_Init();
	
	TIM_Init();
  //TIM_SetCompare4(TIM3,40);
	TIM_SetCompare3(TIM3,45);
	
  getjd_init();
		
	OLED_Init();
  OLED_CLS();
	
	OLED_ShowCHinese(16,0,1);
	OLED_ShowCHinese(30,0,2);
	OLED_ShowCHinese(44,0,3);
	OLED_ShowCHinese(58,0,4);
	OLED_ShowCHinese(72,0,5);
	OLED_ShowCHinese(86,0,6);
	OLED_ShowCHinese(100,0,7);
	
	OLED_ShowChar(0,3,'X',8);
	OLED_ShowChar(0,5,'Y',8);
	OLED_ShowChar(0,7,'Z',8);
	
	OLED_ShowChar(9,3,':',13);
	OLED_ShowChar(9,5,':',13);
	OLED_ShowChar(9,7,':',13);
	OLED_ShowChar(56,3,'.',13);
	OLED_ShowChar(56,5,'.',13);
	OLED_ShowChar(56,7,'.',13);
	
	}
int main(void)
	{	
		bsp_init();
		while(1)
		{
     get_jd();	
  	 showjd();
		}
	}
