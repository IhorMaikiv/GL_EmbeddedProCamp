/*=============================================================================
* Global Logic Embedded ProCamp
* Lecture #04
* Homework Ex. #01
* Develop "Blink LED" application
*=============================================================================*/
#include "stm32f30x.h"

/*----------------------------------------------------------------------------*/
int main(void)
{		
	// Initialization PE8 pin as alternative function output
	// Enable the clock to GPIO Port E
	RCC->AHBENR |= RCC_AHBENR_GPIOEEN;
	// Set PE8 as alternative function mode
	GPIOE->MODER &= ~(3UL << 16);
	GPIOE->MODER |=  (2UL << 16);
	// Set PE8 output type as no pull-up no pull-down
	GPIOE->PUPDR &= ~(3UL << 16);		
	// Set PE8 output speed as LOW
	GPIOE->OSPEEDR &= ~(3UL << 16);
	// Set PE8 output type as push-pull
	GPIOE->OTYPER &= ~(0x100);
	// Select alternative function 01 (TIM1_CH1N)
	GPIOE->AFR[1] &= ~(0xF);
	GPIOE->AFR[1] |= 2UL;
/*----------------------------------------------------------------------------*/
	// Initialization TIM1 timer as PWM
	// Enable the clock to TIMER#1	
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	// Counting direction
	TIM1->CR1 &= ~TIM_CR1_DIR;
	// Clock prescaller
	TIM1->PSC =300;
	// Auto-reload value
	TIM1->ARR = 65534;
	// CCR register value
	TIM1->CCR1 = 1000;
	// Main output enable (MOE)
	TIM1->BDTR |= TIM_BDTR_MOE;
	// Clear output compare mode bits for channel #1
	TIM1->CCMR1 &= ~TIM_CCMR1_OC1M;
	// Select toggle mode
	TIM1->CCMR1 |= TIM_CCMR1_OC1M_0 | TIM_CCMR1_OC1M_1; // (0011)
	// Select output polarit: active HIGH
	TIM1->CCER &= ~TIM_CCER_CC1NP;
	// Enable output for channel #1 complementary output
	TIM1->CCER |= TIM_CCER_CC1NE;
	// Enable timer #1
	TIM1->CR1 |= TIM_CR1_CEN;

  // Begin main loop
  while(1);
}		
/*----------------------------------------------------------------------------*/

