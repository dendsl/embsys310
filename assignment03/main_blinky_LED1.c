
#include "stm32L475.h"
#include "stm32l475_discovery.h"

void RCC_Init(void);
void GPIO_Init(void);

int main()
{
  RCC_Init();
  GPIO_Init();

  while(1)
  {
    for (int i = 0; i < 100000; i++){}
    
    GPIOA->ODR ^= (1 <<LED1_PIN);   
  }
  
  return 0;
}


void RCC_Init(void)
{
  RCC->AHB2ENR |= (1 << 0); // Enable Port A Clock
}


void GPIO_Init(void)
{
  GPIOA->MODER |=  (1 << (LED1_PIN * 2));
  GPIOA->MODER &= ~(1 << (LED1_PIN * 2) + 1);
}


