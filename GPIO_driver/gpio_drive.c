


#include "gpio_drive.h"

void GPIO_SET(GPIO_TypeDef* port, int pin, int mode)
{	
/*_________________GPIOA selection execution_________________________*/	
	
	if (port == GPIOA)
	{
		if((mode  ==  ALT_F_OUT_PP)||(mode == ALT_F_OUT_OD))
		{
			RCC->APB2ENR |= (RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN );
		}
		else
		{
				RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN; 
		}
		
		if(pin<8)
		{
			GPIOA-> CRL |= ( (unsigned int) mode << (pin*4));
		}
		else
		{
			GPIOA-> CRH |= ((unsigned int) mode << 4*(pin-8));
		}
	}
	
/*__________________GPIOB selection exectution______________________*/
	
	else if (port == GPIOB)
	{
		if((mode  ==  ALT_F_OUT_PP)||(mode == ALT_F_OUT_OD))
		{
			RCC->APB2ENR |= (RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN );
		}
		else
		{
				RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN; 
		}
		
		if(pin<8)
		{
			GPIOB-> CRL |= ( (unsigned int) mode << (pin*4));
		}
		else
		{
			GPIOB-> CRH |= ((unsigned int) mode << 4*(pin-8));
		}
	}
/*_________________GPIOC selection execution_________________________*/
	
	else if (port == GPIOC)
	{
		if((mode  ==  ALT_F_OUT_PP)||(mode == ALT_F_OUT_OD))
		{
			RCC->APB2ENR |= (RCC_APB2ENR_IOPCEN | RCC_APB2ENR_AFIOEN );
		}
		else
		{
				RCC -> APB2ENR |= RCC_APB2ENR_IOPCEN; 
		}
		
		if(pin<8)
		{
			GPIOC-> CRL |= ( (unsigned int) mode << (pin*4));
		}
		else
		{
			GPIOC-> CRH |= ((unsigned int) mode << 4*(pin-8));
		}
	}
/*	
	else if (port == GPIOD)
	{
		if((mode  ==  ALT_F_OUT_PP)||(mode == ALT_F_OUT_OD))
		{
			RCC->APB2ENR |= (RCC_APB2ENR_IOPDEN | RCC_APB2ENR_AFIOEN );
		}
		else
		{
				RCC -> APB2ENR |= RCC_APB2ENR_IOPDEN; 
		}
		
		if(pin<8)
		{
			GPIOD-> CRL |= ( (unsigned int) mode << (pin*4));
		}
		else
		{
			GPIOD-> CRH |= ((unsigned int) mode << 4*(pin-8));
		}
	}
	else if (port == GPIOE)
	{
		if((mode  ==  ALT_F_OUT_PP)||(mode == ALT_F_OUT_OD))
		{
			RCC->APB2ENR |= (RCC_APB2ENR_IOPEEN | RCC_APB2ENR_AFIOEN );
		}
		else
		{
				RCC -> APB2ENR |= RCC_APB2ENR_IOPEEN; 
		}
		
		if(pin<8)
		{
			GPIOE-> CRL |= ( (unsigned int) mode << (pin*4));
		}
		else
		{
			GPIOE-> CRH |= ((unsigned int) mode << 4*(pin-8));
		}
	}
*/	
				
}

int READ_STATUS(GPIO_TypeDef* port , int pin)
{
			
			unsigned int status = 0x00;
			if(port == GPIOA)
			{
				 status = GPIOA ->IDR &(1<<pin);	
			}
			else 
			if(port == GPIOB)
			{
				status = GPIOB ->IDR &(1<<pin);
			}
			else if(port == GPIOC)
			{
				 status = GPIOC ->IDR &(1<<pin);
			}
			return (int)status;
			
}

