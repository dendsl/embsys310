/*
    File Name:  main.c
    Program:    Morse Code LED
    Author:     Devon Endsley
    Date:       11/08/20
*/

//--------------------------------------------
// Program Description
//--------------------------------------------
// The Morse Code Representations of the Letters 
// is built by using the following building blocks:
//      - a 'DOT' is represented by 0x1
//      - a 'DASH' is represented by 0x2
// since Morse Code letters are represented by a 
// series of dot and dashes, we concatenate the 
// numerical values by shifting the previous
// DOT or DASH by a BYTE to the left and OR'ing 
// the LSB by the new DOT or DASH. Therefore,
// a letter is built by a combination of bytes
// where 1 byte represents a DOT or DASH. 

// Morse Code Letters are built using a 'Tree'
// methodoloy where lower branches are built upon 
// previous letters (branches) and either appended
// with DOTs or DASHs. The left-child of the parent node
// appends the previous letter with a DOT and the right-child 
// appends the previous letter with a DASH. This pattern continues


#include <stdio.h> 
#include "morsecode.h"
#include "stm32L475.h"
#include "stm32l475_discovery.h"


// Function Prototypes
void RCC_Init(void);
void GPIO_Init(void);
void ledBurst(void);


int main()
{
  int letter = 0; // temp value of arr[i]
  int lsb =    0; // temp value of the LSB of letter
  int time =   0; // time unit value of the lsb's DASH/DOT
  
  int arr[] = {D,E,V,O,N};
  int length = sizeof(arr)/sizeof(arr[0]);
  
  RCC_Init();
  GPIO_Init();
  
  // Infinite Loop
  while(1)
  {
    
    // Iterate through array of letters
    for(int i = 0; i < length; i++)
    {
      letter = arr[i];
      
      // Iterate while there are still bytes of DOTs/DASHs
      while(letter)
      {
        // Obtain the next DOT/DASH
        lsb = letter & 0xF;
        
        switch(lsb)
        {
            case DOT:
                time = DOT_TIME;
                break;
                
            case DASH:
                time = DASH_TIME;
                break;
                
            default:
                break;
        }
        
        // Turn ON LED1
        GPIOA->ODR |= (1 <<LED1_PIN);  
        
        // Delay duration of 'time' units
        for(int j = 0; j < time; j++);
        
        // Turn OFF LED1
        GPIOA->ODR &= ~(1 <<LED1_PIN); 
        
        // Delay duration of time between letters
        for(int j = 0; j < TIME_BETWEEN_LETTER; j++);
        
        // Update the letter for next LSB reading
        letter = letter >> BYTE;
        
      } // while(letter)
      
    } // for(length...)
    
    // Delay duration of time between words
    for(int i = 0; i < TIME_BETWEEN_WORDS; i++);
          
  } // while(1)
    
     
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
