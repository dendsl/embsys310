#include "stm32l475xx.h"
#include "stm32l4xx_it.h"

#define ON            1
#define OFF           0
#define PIN_5         5
#define PORT_A        0
#define LED1_PIN     (PIN_5)
#define SYS_CLOCK_HZ 4000000u   // Default clock after startup
                                // Section 3.11 in STM32L475 datasheet DS10969
#define SYSTICK_1_MILISECOND    ((SYS_CLOCK_HZ / 1000) - 1)

uint32_t g_miliDelayCounter;

void SysTick_Initialize(void);
void RCC_Init(void);
void GPIO_Init(void);

void SysTick_Set(void);
void delay(uint32_t delayInMilliseconds);
void toggle_LED1(uint8_t toggle, uint32_t counterDelay);


void main(void)
{
    RCC_Init();
    GPIO_Init();

    while(1)
    {
        toggle_LED1(ON,  1000);
        toggle_LED1(OFF, 1000);
    }
    
    return;
}


void toggle_LED1(uint8_t toggle, uint32_t counterDelay)
{
    // Clear the current LED1 Pin Bit
    GPIOA->ODR &= ~(1 << LED1_PIN);
    
    // Set the LED1 Pin bit based
    GPIOA->ODR |=  (toggle << LED1_PIN);
   
    // Delay for counterDelay mili-seconds
    delay(counterDelay);
}


void delay(uint32_t delayInMilliseconds)
{   
    // TimeDelay     = (SysTick->LOAD +1) / ClockFrequency
    // SysTick->LOAD = (TimeDelay * ClockFrequency) - 1
    g_miliDelayCounter = delayInMilliseconds;
    SysTick_Set();
    
    // Wait for the global delay counter to reach 0
    while(g_miliDelayCounter != 0);
    
    SysTick->CTRL = 0; // Disable SysTick
}


// Interrupt Handler for SysTick. Decrements the g_miliDelayCounter every 1 ms
void SysTick_Handler(void)
{
    __disable_irq();
    
    g_miliDelayCounter--;
    
    __enable_irq();
}


// SysTick set function. Sets SysTick to generare an interrupt every 1 ms. 
void SysTick_Set()
{ 
    SysTick->CTRL = 0;                    // Disable SysTick during set up
    SysTick->LOAD = SYSTICK_1_MILISECOND; // Load the SysTick reload value  
    SysTick->VAL  = 0;                    // Clear the current counter value
    SysTick->CTRL |= 0x7;                 // Enable the SysTick Counter and Interrupt
}


void RCC_Init(void)
{
  RCC->AHB2ENR |= (1 << PORT_A);
}


void GPIO_Init(void)
{
  GPIOA->MODER |=  (1 << (LED1_PIN * 2));
  GPIOA->MODER &= ~(1 << (LED1_PIN * 2) + 1);
}

