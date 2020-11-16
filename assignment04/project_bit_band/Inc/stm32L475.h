
// File Name: stm32l475.h



#include <stdint.h>


typedef struct
{
  volatile uint32_t CR;          /* clock control register */
  volatile uint32_t ICSCR;       /* internal clock sources calibration register */
  volatile uint32_t CFGR;        /* clock configuration register */
  volatile uint32_t PLLCFGR;     /* system PLL configuration register */
  volatile uint32_t PLLSAI1CFGR; /* PLL SAI1 configuration register */
  volatile uint32_t PLLSAI2CFGR; /* PLL SAI2 configuration register */
  volatile uint32_t CIER;        /* clock interrupt enable register */
  volatile uint32_t CIFR;        /* clock interrupt flag register */
  volatile uint32_t CICR;        /* clock interrupt clear register */
  volatile uint32_t RESERVED0;   /* Reserved */
  volatile uint32_t AHB1RSTR;    /* AHB1 peripheral reset register */
  volatile uint32_t AHB2RSTR;    /* AHB2 peripheral reset register */
  volatile uint32_t AHB3RSTR;    /* AHB3 peripheral reset register */
  volatile uint32_t RESERVED1;   /* Reserved */
  volatile uint32_t APB1RSTR1;   /* APB1 peripheral reset register 1 */
  volatile uint32_t APB1RSTR2;   /* APB1 peripheral reset register 2 */
  volatile uint32_t APB2RSTR;    /* APB2 peripheral reset register */
  volatile uint32_t RESERVED2;   /* Reserved */
  volatile uint32_t AHB1ENR;     /* AHB1 peripheral clocks enable register */
  volatile uint32_t AHB2ENR;     /* AHB2 peripheral clocks enable register */
  volatile uint32_t AHB3ENR;     /* AHB3 peripheral clocks enable register */
  volatile uint32_t RESERVED3;   /* Reserved */
  volatile uint32_t APB1ENR1;    /* APB1 peripheral clocks enable register 1 */
  volatile uint32_t APB1ENR2;    /* APB1 peripheral clocks enable register 2 */
  volatile uint32_t APB2ENR;     /* APB2 peripheral clocks enable register */
  volatile uint32_t RESERVED4;   /* Reserved */
  volatile uint32_t AHB1SMENR;   /* AHB1 peripheral clocks enable in sleep and stop modes register */
  volatile uint32_t AHB2SMENR;   /* AHB2 peripheral clocks enable in sleep and stop modes register */
  volatile uint32_t AHB3SMENR;   /* AHB3 peripheral clocks enable in sleep and stop modes register */
  volatile uint32_t RESERVED5;   /* Reserved */
  volatile uint32_t APB1SMENR1;  /* APB1 peripheral clocks enable in sleep mode and stop modes register 1 */
  volatile uint32_t APB1SMENR2;  /* APB1 peripheral clocks enable in sleep mode and stop modes register 2 */
  volatile uint32_t APB2SMENR;   /* APB2 peripheral clocks enable in sleep mode and stop modes register */
  volatile uint32_t RESERVED6;   /* Reserved */
  volatile uint32_t CCIPR;       /* peripherals independent clock configuration register */
  volatile uint32_t RESERVED7;   /* Reserved */
  volatile uint32_t BDCR;        /* backup domain control register */
  volatile uint32_t CSR;         /* clock control & status register  */
} RCC_TypeDef;


typedef struct
{
  volatile uint32_t MODER;	/* Port Mode Register */
  volatile uint32_t OTYPER;	/* Output Type Register */
  volatile uint32_t OSPEEDR;	/* Output Speed Register */
  volatile uint32_t PUPDR;	/* Pull-up/Pull-down Register */
  volatile uint32_t IDR;	/* Input Data Register */
  volatile uint32_t ODR; 	/* Output Data Register */
  volatile uint32_t BSRR; 	/* Bit Set/Reset Register */
  volatile uint32_t LCKR;	/* Configuration Lock Register */
  volatile uint32_t AFRL;	/* Alternate Function Low Register */
  volatile uint32_t AFRH;	/* Alternate Function High Register */
  volatile uint32_t BRR;	/* Bit Reset Register */
  volatile uint32_t ASCR;	/* Analog Switch Control Register */
} GPIO_TypeDef;

// ----------------------------------------------------------------------------
// Base Address Definitions
// ----------------------------------------------------------------------------
#define RCC_BASE 	0x40021000
#define GPIOA_BASE      0x48000000
#define GPIOB_BASE 	0x48000400

// ----------------------------------------------------------------------------
// TypeDef Mapping to Base-Address Definitions
// ----------------------------------------------------------------------------
#define RCC   ((RCC_TypeDef *)  RCC_BASE)
#define GPIOA ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *) GPIOB_BASE)


