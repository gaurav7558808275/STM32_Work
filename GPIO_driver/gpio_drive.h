
#include "stm32f10x.h"

#define RCC_APB1ENR 							(*((volatile unsigned long *)(0x40021000 + 0x1C)))	// APB1 enable register
#define RCC_AHBENR 							(*((volatile unsigned long *)(0x40021000 + 0x14)))  // AHB BUS enable register
#define RCC_APB2ENR 							(*((volatile unsigned long *)(0x40021000 + 0x18)))  // APB2 register pointer initilaised

void GPIO_SET(GPIO_TypeDef* port, int pin, int mode);   // set the Pin
int READ_STATUS(GPIO_TypeDef* port , int pin);          // IDR manipulation 
void GPIO_Write_Pin(GPIO_TypeDef* port, int pin, int mode);
void GPIO_Read_pin(GPIO_TypeDef* port, int pin, int mode);


// ALL GPIOA REGISTER ADDRESSES
/*
*	#define GPIO_A_CRL 										(*((volatile unsigned long *)(0x40010800 + 0x00 )))
	#define GPIO_A_CRH 										(*((volatile unsigned long *)(0x40010800 + 0x04 )))
	#define GPIO_A_IDR 										(*((volatile unsigned long *)(0x40010800 + 0x08 )))	
	#define GPIO_A_ODR 										(*((volatile unsigned long *)(0x40010800 + 0x0C )))
	#define GPIO_A_BSSR 									(*((volatile unsigned long *)(0x40010800 + 0x10 )))
	#define GPIO_A_BRR 										(*((volatile unsigned long *)(0x40010800 + 0x14 )))	
	#define GPIO_A_LCKR										(*((volatile unsigned long *)(0x40010800 + 0x18 )))
	
	#define GPIO_B_CRL 										(*((volatile unsigned long *)(0x40010C00 + 0x00 )))
	#define GPIO_B_CRH 										(*((volatile unsigned long *)(0x40010C00 + 0x04 )))
	#define GPIO_B_IDR 										(*((volatile unsigned long *)(0x40010C00 + 0x08 )))	
	#define GPIO_B_ODR 										(*((volatile unsigned long *)(0x40010C00 + 0x0C )))
	#define GPIO_B_BSSR 									(*((volatile unsigned long *)(0x40010C00 + 0x10 )))
	#define GPIO_B_BRR 										(*((volatile unsigned long *)(0x40010C00 + 0x14 )))	
	#define GPIO_B_LCKR										(*((volatile unsigned long *)(0x40010C00 + 0x18 )))
	
*/

				// MODEy configuration // 

#define INPUT_MODE  						(uint32_t)0x00   // Input Mode
#define OUTPUT_MODE_10					0b0001	 // Output Mode max speed 10Mhz
#define OUTPUT_MODE_2						0b0010   // Output Mode max speed 2Mhz
#define OUTPUT_MODE_50					0b0011	 // Output Mode max speed 50Mhz
	
				// CNFy conifig	uration //
						// INPUT MODE //
				
#define AN_IN_MODE  						0b0000
#define FLOAT_IN_MODE 					0b0100
#define IN_PU_PD								0b1000

				 // OUTPUT MODE //
				 
			
#define GEN_P_OUT_PP						(uint32_t)0x00   
#define GEN_P_OUT_OD						(uint32_t)0x01
#define ALT_F_OUT_PP						(uint32_t)0x02
#define ALT_F_OUT_OD						(uint32_t)0x03






	



