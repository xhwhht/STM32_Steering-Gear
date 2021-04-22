#ifndef      __BSP_ILI9341_LCD_H
#define	     __BSP_ILI9341_LCD_H


#include "stm32f10x.h"
#include "./font/fonts.h"

/******************************* ILI9341 ��ʾ��8080ͨѶ���Ŷ��� ***************************/
/******�����ź���******/
//Ƭѡ
#define      ILI9341_CS_CLK                RCC_APB2Periph_GPIOC   
#define      ILI9341_CS_PORT               GPIOC
#define      ILI9341_CS_PIN                GPIO_Pin_4

//DC����
#define      ILI9341_DC_CLK                RCC_APB2Periph_GPIOC   
#define      ILI9341_DC_PORT               GPIOC
#define      ILI9341_DC_PIN                GPIO_Pin_7

//дʹ��
#define      ILI9341_WR_CLK                RCC_APB2Periph_GPIOC   
#define      ILI9341_WR_PORT               GPIOC
#define      ILI9341_WR_PIN                GPIO_Pin_6

//��ʹ��
#define      ILI9341_RD_CLK                RCC_APB2Periph_GPIOC   
#define      ILI9341_RD_PORT               GPIOC
#define      ILI9341_RD_PIN                GPIO_Pin_5

//��λ����ֱ��ʹ��NRST�������帴λ��ʱ���ʹҺ����λ


//��������
#define      ILI9341_BK_CLK                RCC_APB2Periph_GPIOD    
#define      ILI9341_BK_PORT               GPIOD
#define      ILI9341_BK_PIN                GPIO_Pin_2

/********�����ź���***************/
#define      ILI9341_DATA_CLK                RCC_APB2Periph_GPIOB   
#define      ILI9341_DATA_PORT               GPIOB
#define      ILI9341_DATA_PIN                GPIO_Pin_All

/********�ź��߿�����صĺ�***************/
#define	ILI9341_CS_SET  	ILI9341_CS_PORT->BSRR=ILI9341_CS_PIN    //Ƭѡ�˿�  		
#define	ILI9341_DC_SET		ILI9341_DC_PORT->BSRR=ILI9341_DC_PIN    //����/���� 	  
#define	ILI9341_WR_SET		ILI9341_WR_PORT->BSRR=ILI9341_WR_PIN    //д����			
#define	ILI9341_RD_SET		ILI9341_RD_PORT->BSRR=ILI9341_RD_PIN    //������			
								    
#define	ILI9341_CS_CLR  	ILI9341_CS_PORT->BRR=ILI9341_CS_PIN     //Ƭѡ�˿�  		
#define	ILI9341_DC_CLR		ILI9341_DC_PORT->BRR=ILI9341_DC_PIN     //����/����		     
#define	ILI9341_WR_CLR		ILI9341_WR_PORT->BRR=ILI9341_WR_PIN     //д����			
#define	ILI9341_RD_CLR		ILI9341_RD_PORT->BRR=ILI9341_RD_PIN     //������			

//�������������
#define DATAOUT(x) 	ILI9341_DATA_PORT->ODR=x; //�������
#define DATAIN     	ILI9341_DATA_PORT->IDR;   //��������	


/*************************************** ����Ԥ�� ******************************************/
#define      DEBUG_DELAY()       ILI9341_Delay(0xFFFF)         

/***************************** ILI934 ��ʾ�������ʼ������������� ***************************/
#define      ILI9341_DispWindow_X_Star		    0     //��ʼ���X����
#define      ILI9341_DispWindow_Y_Star		    0     //��ʼ���Y����

#define 			ILI9341_LESS_PIXEL	  							240			//Һ�����϶̷�������ؿ��
#define 			ILI9341_MORE_PIXEL	 								320			//Һ�����ϳ���������ؿ��

//����Һ��ɨ�跽����仯��XY���ؿ��
//����ILI9341_GramScan�������÷���ʱ���Զ�����
extern uint16_t LCD_X_LENGTH,LCD_Y_LENGTH; 

//Һ����ɨ��ģʽ
//������ѡֵΪ0-7
extern uint8_t LCD_SCAN_MODE;

/******************************* ���� ILI934 ��ʾ��������ɫ ********************************/
#define      BACKGROUND		                BLACK   //Ĭ�ϱ�����ɫ

#define      WHITE		 		                  0xFFFF	   //��ɫ
#define      BLACK                         0x0000	   //��ɫ 
#define      GREY                          0xF7DE	   //��ɫ 
#define      BLUE                          0x001F	   //��ɫ 
#define      BLUE2                         0x051F	   //ǳ��ɫ 
#define      RED                           0xF800	   //��ɫ 
#define      MAGENTA                       0xF81F	   //����ɫ�����ɫ 
#define      GREEN                         0x07E0	   //��ɫ 
#define      CYAN                          0x7FFF	   //����ɫ����ɫ 
#define      YELLOW                        0xFFE0	   //��ɫ 
#define      BRED                          0xF81F
#define      GRED                          0xFFE0
#define      GBLUE                         0x07FF



/******************************* ���� ILI934 �������� ********************************/
#define      CMD_SetCoordinateX		 		    0x2A	     //����X����
#define      CMD_SetCoordinateY		 		    0x2B	     //����Y����
#define      CMD_SetPixel		 		          0x2C	     //�������




/********************************** ���� ILI934 ���� ***************************************/
void                     ILI9341_Init                    ( void );
void                     ILI9341_Rst                     ( void );
void                     ILI9341_BackLed_Control         ( FunctionalState enumState );
void                     ILI9341_GramScan                ( uint8_t ucOtion );
void                     ILI9341_OpenWindow              ( uint16_t usX, uint16_t usY, uint16_t usWidth, uint16_t usHeight );
void                     ILI9341_Clear                   ( uint16_t usX, uint16_t usY, uint16_t usWidth, uint16_t usHeight );
void                     ILI9341_SetPointPixel           ( uint16_t usX, uint16_t usY );
uint16_t                 ILI9341_GetPointPixel           ( uint16_t usX , uint16_t usY );
void                     ILI9341_DrawLine                ( uint16_t usX1, uint16_t usY1, uint16_t usX2, uint16_t usY2 );
void                     ILI9341_DrawRectangle           ( uint16_t usX_Start, uint16_t usY_Start, uint16_t usWidth, uint16_t usHeight,uint8_t ucFilled );
void                     ILI9341_DrawCircle              ( uint16_t usX_Center, uint16_t usY_Center, uint16_t usRadius, uint8_t ucFilled );
void                     ILI9341_DispChar_EN             ( uint16_t usX, uint16_t usY, const char cChar );
void                     ILI9341_DispStringLine_EN      ( uint16_t line, char * pStr );
void                     ILI9341_DispString_EN      			( uint16_t usX, uint16_t usY, char * pStr );
void 											ILI9341_DispString_EN_YDir 		(   uint16_t usX,uint16_t usY ,  char * pStr );

void 											LCD_SetFont											(sFONT *fonts);
sFONT 										*LCD_GetFont											(void);
void 											LCD_ClearLine										(uint16_t Line);
void 											LCD_SetBackColor								(uint16_t Color);
void 											LCD_SetTextColor								(uint16_t Color)	;
void 											LCD_SetColors										(uint16_t TextColor, uint16_t BackColor);
void 											LCD_GetColors										(uint16_t *TextColor, uint16_t *BackColor);
uint16_t 								ILI9341_Read_ID									(void);


#endif /* __BSP_ILI9341_ILI9341_H */


