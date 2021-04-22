#ifndef      __BSP_ILI9341_LCD_H
#define	     __BSP_ILI9341_LCD_H


#include "stm32f10x.h"
#include "./font/fonts.h"

/******************************* ILI9341 显示屏8080通讯引脚定义 ***************************/
/******控制信号线******/
//片选
#define      ILI9341_CS_CLK                RCC_APB2Periph_GPIOC   
#define      ILI9341_CS_PORT               GPIOC
#define      ILI9341_CS_PIN                GPIO_Pin_4

//DC引脚
#define      ILI9341_DC_CLK                RCC_APB2Periph_GPIOC   
#define      ILI9341_DC_PORT               GPIOC
#define      ILI9341_DC_PIN                GPIO_Pin_7

//写使能
#define      ILI9341_WR_CLK                RCC_APB2Periph_GPIOC   
#define      ILI9341_WR_PORT               GPIOC
#define      ILI9341_WR_PIN                GPIO_Pin_6

//读使能
#define      ILI9341_RD_CLK                RCC_APB2Periph_GPIOC   
#define      ILI9341_RD_PORT               GPIOC
#define      ILI9341_RD_PIN                GPIO_Pin_5

//复位引脚直接使用NRST，开发板复位的时候会使液晶复位


//背光引脚
#define      ILI9341_BK_CLK                RCC_APB2Periph_GPIOD    
#define      ILI9341_BK_PORT               GPIOD
#define      ILI9341_BK_PIN                GPIO_Pin_2

/********数据信号线***************/
#define      ILI9341_DATA_CLK                RCC_APB2Periph_GPIOB   
#define      ILI9341_DATA_PORT               GPIOB
#define      ILI9341_DATA_PIN                GPIO_Pin_All

/********信号线控制相关的宏***************/
#define	ILI9341_CS_SET  	ILI9341_CS_PORT->BSRR=ILI9341_CS_PIN    //片选端口  		
#define	ILI9341_DC_SET		ILI9341_DC_PORT->BSRR=ILI9341_DC_PIN    //数据/命令 	  
#define	ILI9341_WR_SET		ILI9341_WR_PORT->BSRR=ILI9341_WR_PIN    //写数据			
#define	ILI9341_RD_SET		ILI9341_RD_PORT->BSRR=ILI9341_RD_PIN    //读数据			
								    
#define	ILI9341_CS_CLR  	ILI9341_CS_PORT->BRR=ILI9341_CS_PIN     //片选端口  		
#define	ILI9341_DC_CLR		ILI9341_DC_PORT->BRR=ILI9341_DC_PIN     //数据/命令		     
#define	ILI9341_WR_CLR		ILI9341_WR_PORT->BRR=ILI9341_WR_PIN     //写数据			
#define	ILI9341_RD_CLR		ILI9341_RD_PORT->BRR=ILI9341_RD_PIN     //读数据			

//数据线输入输出
#define DATAOUT(x) 	ILI9341_DATA_PORT->ODR=x; //数据输出
#define DATAIN     	ILI9341_DATA_PORT->IDR;   //数据输入	


/*************************************** 调试预用 ******************************************/
#define      DEBUG_DELAY()       ILI9341_Delay(0xFFFF)         

/***************************** ILI934 显示区域的起始坐标和总行列数 ***************************/
#define      ILI9341_DispWindow_X_Star		    0     //起始点的X坐标
#define      ILI9341_DispWindow_Y_Star		    0     //起始点的Y坐标

#define 			ILI9341_LESS_PIXEL	  							240			//液晶屏较短方向的像素宽度
#define 			ILI9341_MORE_PIXEL	 								320			//液晶屏较长方向的像素宽度

//根据液晶扫描方向而变化的XY像素宽度
//调用ILI9341_GramScan函数设置方向时会自动更改
extern uint16_t LCD_X_LENGTH,LCD_Y_LENGTH; 

//液晶屏扫描模式
//参数可选值为0-7
extern uint8_t LCD_SCAN_MODE;

/******************************* 定义 ILI934 显示屏常用颜色 ********************************/
#define      BACKGROUND		                BLACK   //默认背景颜色

#define      WHITE		 		                  0xFFFF	   //白色
#define      BLACK                         0x0000	   //黑色 
#define      GREY                          0xF7DE	   //灰色 
#define      BLUE                          0x001F	   //蓝色 
#define      BLUE2                         0x051F	   //浅蓝色 
#define      RED                           0xF800	   //红色 
#define      MAGENTA                       0xF81F	   //红紫色，洋红色 
#define      GREEN                         0x07E0	   //绿色 
#define      CYAN                          0x7FFF	   //蓝绿色，青色 
#define      YELLOW                        0xFFE0	   //黄色 
#define      BRED                          0xF81F
#define      GRED                          0xFFE0
#define      GBLUE                         0x07FF



/******************************* 定义 ILI934 常用命令 ********************************/
#define      CMD_SetCoordinateX		 		    0x2A	     //设置X坐标
#define      CMD_SetCoordinateY		 		    0x2B	     //设置Y坐标
#define      CMD_SetPixel		 		          0x2C	     //填充像素




/********************************** 声明 ILI934 函数 ***************************************/
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


