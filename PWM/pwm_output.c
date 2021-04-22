#include"pwm_output.h"

static void TIM_GPIO_Config(void)
{
	  GPIO_InitTypeDef GPIO_InitStructure;
 
  // 输出比较通道 GPIO 初始化PB0  PB1
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
    GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0; 			
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_1; 			
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
 
}
 
static void TIM3_Mode_Config(void)
{
  TIM_OCInitTypeDef TIM_OCInitStructure;
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);	// 开启定时器时钟,即内部时钟CK_INT=72M
 
    /*--------------------时基结构体初始化-------------------------*/
	
	TIM_TimeBaseStructure.TIM_Period= (2000-1);	  // 自动重装载寄存器的值，累计TIM_Period+1个频率后产生一个更新或者中断
	TIM_TimeBaseStructure.TIM_Prescaler= (720-1);  // 驱动CNT计数器的时钟 = Fck_int/(psc+1)	分频
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;  // 时钟分频因子 ，用于配置死区时间，没用到，随意			
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;	// 计数器计数模式，设置为向上计数		
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	// 重复计数器的值，没用到，可以随意设置
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);	   // 初始化定时器
 
	/*--------------------输出比较结构体初始化-------------------*/		
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;  // 配置为PWM模式1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	// 输出使能
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;  // 互补输出使能	
	TIM_OCInitStructure.TIM_Pulse = 0;	  // 设置占空比大小
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;	// 输出通道电平极性配置	
	//TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;	  // 互补输出通道电平极性配置	
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	 // 输出通道空闲电平极性配置
	//TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;	 // 互补输出通道空闲电平极性配置
	
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);   //通道3配置
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);   //通道2配置
	
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);   //使能通道3
	TIM_OC4PreloadConfig(TIM3,TIM_OCPreload_Enable);	  //使能通道4
		
	TIM_Cmd(TIM3, ENABLE);	// 使能计数器	
	TIM_CtrlPWMOutputs(TIM3, ENABLE);  // 主输出使能，当使用的是通用定时器时，这句不需要
}
 
void TIM_Init(void)
{
	TIM_GPIO_Config();
	TIM3_Mode_Config();
}


