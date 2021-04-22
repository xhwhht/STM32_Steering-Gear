/**
  ******************************************************************************
  * @file    main.c
  * @author  LYC
  * @version V1.0
  * @date    2014-04-22
  * @brief   秉火MPU6050 DMP演示例程
  ******************************************************************************
  * @attention
  * 实验平台:秉火 F103-MINI STM32 开发板 
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
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
	
float Pitch=0,Roll=0,Yaw=0;

void bsp_init()
{
	
	SysTick_Init();
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk;

	/* 串口通信初始化 */
	USART_Config();

	//MPU6050中断引脚
	EXTI_Pxy_Config();
	//I2C初始化
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
