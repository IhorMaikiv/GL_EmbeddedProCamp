/*----------------------------------------------------------------------------
 * Name:    main.c
 * Purpose: LED Flasher
 * Note(s):
 *----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stm32f3xx.h>

// ----------------------------------------------------------------------------
//  Functions declaration
// ----------------------------------------------------------------------------

// Delay Function
void delay ( uint32_t temp)
	{
				while(temp --);
	}
// Pin configuration function	
void Pin_Config (void)
{
	RCC -> AHBENR   |= (1 << 21);  // Enable GPIOE clock
	GPIOE -> MODER  |= (1 << 16);  // PE.8 is configured as output 
	GPIOE -> MODER  &= ~(1 << 17); 
	GPIOE -> OTYPER &= (1 << 8);  // PE.8 is configured as open-drain output
}
// ----------------------------------------------------------------------------
//  Main function
// ----------------------------------------------------------------------------
	int main (void)
{
		
		Pin_Config ();	
		
	while (1)
	{
			GPIOE -> ODR ^= 1 << 8; // PE.8 output value is changed by XOR operation 
			delay (100000);
	}
}
// ----------------------------------------------------------------------------
// End Of File 
// ----------------------------------------------------------------------------

