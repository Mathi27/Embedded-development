/**
 ******************************************************************************
 * @file           : main.c
 * @author         : MathiYuvarajan
 * @Program          :Basic Led Blinking using GPIO
 *****************************************************************************
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "gpio.h"

int main(void)
{
	// Initialization
	AHB1_ENR |= (1<<1); // GPIOBLP_ENR
	AHB1_ENR |= (1<<2); // GPIOCLP_ENR

	//Clear the GPIOB MODER Register
	GPIOB_MODER &= ~(3<<26); // 13th PIN so MODER13
    GPIOB_MODER &= ~(3<<28); //14th PIN so MODER 14
    GPIOB_MODER &= ~(3<<30); //15th PIN so MODER 15
    GPIOC_MODER &= ~(3<<12); //6th PIN so MODER 6
    //Buzzer
    // GPIOC_MODER &= ~(3<<18); // Buzzer using PC9

	//Set the GPIOB MODER Register
	GPIOB_MODER |= (1<<26);
	GPIOB_MODER |= (1<<28);
	GPIOB_MODER |= (1<<30);
	GPIOC_MODER |= (1<<12);
	// Buzzer
	// GPIOC_MODER |= (1<<18);


	GPIOB_ODR &= ~(1<<13); // 13th PIN Led OFF
	GPIOB_ODR &= ~(1<<14);  // 14th PIN Led OFF
	GPIOB_ODR &= ~(1<<15);  //15th PIN Led OFF
    GPIOC_ODR &= ~(1<<6);
    // Buzzer MODER.
   // GPIOC_ODR &= ~(1<<9);

	/* Loop forever */
	for(;;){
		GPIOB_ODR ^= (1<<13);
        GPIOB_ODR ^= (1<<14);
        GPIOB_ODR ^= (1<<15);
        GPIOC_ODR ^= (1<<6);
        //
        GPIOC_ODR ^= (1<<9);
		//Random Delay
		for(uint32_t x=0;x<100000;x++);
	}
}
