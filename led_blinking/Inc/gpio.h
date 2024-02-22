/*
 * gpio.h
 *
 *  Created on: Feb 22, 2024
 *      Author: mathi
 */

#ifndef GPIO_H_
#define GPIO_H_


#define RCC 0x40023800UL
#define AHB1_ENR *(volatile uint32_t*)(RCC+0x30U) // AHB1 ENR
#define GPIOB 0x40020400UL
#define GPIOB_MODER *(volatile uint32_t*)(GPIOB+0x00U) // GPIOB MODER
#define GPIOB_ODR *(volatile uint32_t*)(GPIOB+0x14U) // GPIOB ODR

#define GPIOC 0x40020800UL
#define GPIOC_MODER *(volatile uint32_t*)(GPIOC+0x00U) // GPIOC MODER
#define GPIOC_ODR *(volatile uint32_t*)(GPIOC+0x14U) // GPIOC ODR

#endif /* GPIO_H_ */
