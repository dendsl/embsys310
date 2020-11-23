/*******************************************************************************
File name       : swapCharsAsm.s
Description     : Assembly language function for swapping char-values
*******************************************************************************/   

    EXTERN PrintString  // PrintString is defined outside this file.
    EXTERN myCstr       // myCstr defined outside this file.
    
    PUBLIC swapCharsAsm // Exports symbols to other modules
                        // Making divAsm available to other modules.
    
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
Function Name   : swapCharsAsm
Description     : Calls C code to print a string; 
                  swaps the values of its input, char arguments
C Prototype     : void divAsm(char *a, char *b)
                : Where the inputs are pointers to char variables
Parameters      : R0: pointer to char variable, 'a'
                : R1: pointer to char variable, 'b'
Return value    : N/A
*******************************************************************************/  
  
swapCharsAsm

// Initial assumptions - Before swapCharsAsm is called - the inputs are stored on the stack.
// The address of the values residing on the stack are stored/moved onto the input
// argument registers R0 and R1 where:
//      R0 -> pointing to the Stack address of char 'a'
//      R1 -> pointing to the Stack address of char 'z'

/*
    (1) char temp = *a;
    (2) *a = *b;
    (3) *b = temp;
*/
    
    // (1) "C" code translation step: 
    //          char temp = *a;
    LDRB R2, [R0]       // Load the byte value at the address held by R0 into R2 where.
                        // Note - we use LDRB because a char is a byte, therefore we must load
						// the whole byte data into R2. 
						
    
    // (2) "C" code translation step:
    //          *a = *b;
    LDRB R3, [R1]       // Load the byte value at the address held by R1 into R3 where.
                        // Note - we use LDRB because a char is a byte, therefore we must load
						// the whole byte data into R3.    
                       
    STRB R3, [R0]       // Store the byte value held by R3 into the address held by R0
                        
    // (3) "C" code translation step: 
    //          *b = temp;
    STRB R2, [R1]       // Store the byte value held by R2 into the address held by R1
                                          
    BX LR

    END
