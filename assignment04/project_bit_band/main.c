
#include "stm32L475.h"
#include "stm32l475_discovery.h"

#define BIT_BAND_PERIPH_BASE            0x40000000
#define BIT_BAND_PERIPH_ALIAS_BASE      0x42000000
#define BIT_BAND_PERIPH_ADDR(x, y)      (BIT_BAND_PERIPH_ALIAS_BASE + ((x - BIT_BAND_PERIPH_BASE) * 0x20) + (y * 0x4))

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
  //Use bit-banding to Enable Port A Clock using RCC and AHB2ENR.
  //    AHB2ENR Offset  = 0x4C;
  //    GPIOAEN         = Bit 0
  *((volatile unsigned int *) BIT_BAND_PERIPH_ADDR(RCC_BASE + 0x4C, 0x0)) = 0x1; 
}


void GPIO_Init(void)
{
  GPIOA->MODER |=  (1 << (LED1_PIN * 2));
  GPIOA->MODER &= ~(1 << (LED1_PIN * 2) + 1);
}


