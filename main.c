#include "stm32f4xx.h"                  // Device header

int main()
{

	RCC->AHB1ENR|=0x09; // RCC signal for GPIOD and GPIOA port
	
	// Led
	GPIOD->MODER|=0x55000000; //PD12,PD13,PD14,PD15 Output; speed, pupdr,otyper etc. doesn't necessary for a led 
	
	// Button
	GPIOA->MODER&=~(0x03); // PA0 input
	GPIOA->OTYPER&=~(0x01);
	GPIOA->PUPDR|=0x02;
	
	while(1)
	{
		
		if(GPIOA->IDR & GPIO_IDR_IDR_0) //if the button pressed
		{	
			GPIOD->ODR|=0xF000; //1111 0000 0000 0000
		}
		
		else
		{			
			GPIOD->ODR&=~(0xF000); // 0000 0000 0000 0000
		}
	} 	
	
}
