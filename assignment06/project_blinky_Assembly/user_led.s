/*******************************************************************************
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    EXTERN delay                    // delay() is defined outside this file

    PUBLIC control_user_led1        // Exports symbols to other modules

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : control_user_led1
Description     : - Uses Peripheral registers at base 0x4800.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint8_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint8_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/  


GPIOA_BASE  EQU 0x48000000
GPIOA_ODR   EQU 0x14
GPIOA_BIT_5 EQU 0x5
BIT_5       EQU (1 << 5)          

control_user_led1

    PUSH {LR}                                   // Push LR since we will be calling a function internally
 
 // Set the toggle state of LED1
//    LSL R0, R0, #GPIOA_BIT_5                  // Shift the Toggle input by 5 bits for use in the ODR register
    
    MOV R2, #GPIOA_BASE                         // Store the GPIO A Base value into register R2
    
    LDR R3, [R2, #GPIOA_ODR]                    // Load the value from the address held at R2, with offset GPIOA_ODR; 
    
    AND R3, R3, #(~BIT_5)                       // Clear bit-5 of GPIOA_ODR. 
                                                //      Ex: GPIOA->ODR &= ~(1 << GPIOA_BIT_5);
                                                
    ORRS R3, R3, R0, LSL #GPIOA_BIT_5           // Set bit-5 based on state parameter
                                                //      Ex: GPIOA->ODR |= (1 << GPIOA_BIT_5);
                                                // Note - R0 is Left-Shift the Toggle input by 5 bits before being OR'd with R3
                                                
    STR R3, [R2, #GPIOA_ODR]                    // Store the value of R3 into address of R2 with offset GPIOA_ODR;
    
 // Set the delay
    MOV R0, R1                                  // Move the duration value held in R1 to R0 so delay() can use the paramter in R0
    
    BL delay                                    // Call the delay function
        
    POP {LR}                                    // Pop LR since we are exiting this function
    
    BX LR                                       // Return from function, branch to LR
    
    END
