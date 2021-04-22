#include"pwm_output.h"

static void TIM_GPIO_Config(void)
{
	  GPIO_InitTypeDef GPIO_InitStructure;
 
  // ����Ƚ�ͨ�� GPIO ��ʼ��PB0  PB1
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
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);	// ������ʱ��ʱ��,���ڲ�ʱ��CK_INT=72M
 
    /*--------------------ʱ���ṹ���ʼ��-------------------------*/
	
	TIM_TimeBaseStructure.TIM_Period= (2000-1);	  // �Զ���װ�ؼĴ�����ֵ���ۼ�TIM_Period+1��Ƶ�ʺ����һ�����»����ж�
	TIM_TimeBaseStructure.TIM_Prescaler= (720-1);  // ����CNT��������ʱ�� = Fck_int/(psc+1)	��Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;  // ʱ�ӷ�Ƶ���� ��������������ʱ�䣬û�õ�������			
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;	// ����������ģʽ������Ϊ���ϼ���		
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	// �ظ���������ֵ��û�õ���������������
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);	   // ��ʼ����ʱ��
 
	/*--------------------����ȽϽṹ���ʼ��-------------------*/		
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;  // ����ΪPWMģʽ1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	// ���ʹ��
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;  // �������ʹ��	
	TIM_OCInitStructure.TIM_Pulse = 0;	  // ����ռ�ձȴ�С
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;	// ���ͨ����ƽ��������	
	//TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;	  // �������ͨ����ƽ��������	
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;	 // ���ͨ�����е�ƽ��������
	//TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;	 // �������ͨ�����е�ƽ��������
	
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);   //ͨ��3����
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);   //ͨ��2����
	
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);   //ʹ��ͨ��3
	TIM_OC4PreloadConfig(TIM3,TIM_OCPreload_Enable);	  //ʹ��ͨ��4
		
	TIM_Cmd(TIM3, ENABLE);	// ʹ�ܼ�����	
	TIM_CtrlPWMOutputs(TIM3, ENABLE);  // �����ʹ�ܣ���ʹ�õ���ͨ�ö�ʱ��ʱ����䲻��Ҫ
}
 
void TIM_Init(void)
{
	TIM_GPIO_Config();
	TIM3_Mode_Config();
}


