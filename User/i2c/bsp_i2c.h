#ifndef __BSP_I2C_H
#define	__BSP_I2C_H

#include "stm32f10x.h"
#include "./usart/bsp_usart.h"


//MINI开发板不支持硬件IIC，不能使用这个宏
//#define HARD_IIC 

//MPU6050的AD0引脚接GND时，地址为0x68 ,接3.3V时，地址为0x69，注意要匹配。
#define MPU6050_ADDR   0x68


/*********************软件IIC使用的宏****************************/

//
#define Soft_I2C_SDA 		GPIO_Pin_3
#define Soft_I2C_SCL 		GPIO_Pin_2
#define Soft_I2C_PORT   GPIOA
//
#define Soft_I2C_SCL_0 		GPIO_ResetBits(Soft_I2C_PORT, Soft_I2C_SCL)
#define Soft_I2C_SCL_1 		GPIO_SetBits(Soft_I2C_PORT, Soft_I2C_SCL)
#define Soft_I2C_SDA_0 		GPIO_ResetBits(Soft_I2C_PORT, Soft_I2C_SDA)
#define Soft_I2C_SDA_1   	GPIO_SetBits(Soft_I2C_PORT, Soft_I2C_SDA)





/**************************I2C参数定义，I2C1或I2C2********************************/
#define             SENSORS_I2Cx                                I2C1
#define             SENSORS_I2C_APBxClock_FUN                   RCC_APB1PeriphClockCmd
#define             SENSORS_I2C_CLK                             RCC_APB1Periph_I2C1
#define             SENSORS_I2C_GPIO_APBxClock_FUN              RCC_APB2PeriphClockCmd
#define             SENSORS_I2C_GPIO_CLK                        RCC_APB2Periph_GPIOA     
#define             SENSORS_I2C_SCL_PORT                        GPIOA   
#define             SENSORS_I2C_SCL_PIN                         GPIO_Pin_2
#define             SENSORS_I2C_SDA_PORT                        GPIOA 
#define             SENSORS_I2C_SDA_PIN                         GPIO_Pin_3

/*等待超时时间*/
#define I2CT_FLAG_TIMEOUT         ((uint32_t)0x1000)
#define I2CT_LONG_TIMEOUT         ((uint32_t)(10 * I2CT_FLAG_TIMEOUT))

/*信息输出*/
#define MPU_DEBUG_ON         0
#define MPU_DEBUG_FUNC_ON    0

#define MPU_INFO(fmt,arg...)           printf("<<-MPU-INFO->> "fmt"\n",##arg)
#define MPU_ERROR(fmt,arg...)          printf("<<-MPU-ERROR->> "fmt"\n",##arg)
#define MPU_DEBUG(fmt,arg...)          do{\
                                          if(MPU_DEBUG_ON)\
                                          printf("<<-MPU-DEBUG->> [%d]"fmt"\n",__LINE__, ##arg);\
                                          }while(0)

#define MPU_DEBUG_FUNC()               do{\
                                         if(MPU_DEBUG_FUNC_ON)\
                                         printf("<<-MPU-FUNC->> Func:%s@Line:%d\n",__func__,__LINE__);\
                                       }while(0)


void I2C_Bus_Init(void);
uint8_t I2C_ByteWrite(uint8_t pBuffer, uint8_t WriteAddr);
uint8_t I2C_BufferRead(uint8_t* pBuffer, uint8_t ReadAddr, uint16_t NumByteToRead);
																					
void Set_I2C_Retry(unsigned short ml_sec);
unsigned short Get_I2C_Retry(void);
int Sensors_I2C_ReadRegister(unsigned char Address, unsigned char RegisterAddr, 
                                          unsigned short RegisterLen, unsigned char *RegisterValue);
int Sensors_I2C_WriteRegister(unsigned char Address, unsigned char RegisterAddr, 
                                           unsigned short RegisterLen, const unsigned char *RegisterValue);
																					

#endif /* __BSP_I2C_H */

																					

																					

																					

