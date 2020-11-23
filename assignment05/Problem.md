# Problem 1  
Create a function in “C” that allows swapping of two pointers 

**Question A**: Explain what the “main” function does in order to setup the input arguments prior to calling the swap_pointer() function?  

**Answer:** First, "main" initializes the variables by performing instructions to load, add, and store the variables onto the stack. Before "swap_pointer" is called, all the variables are located on the stack. 



**Question B**: What are the values in R0 & R1 when swap_pointer() is called?   

**Answer:** When "swap_pointer() is called, the location (address) values of xPtr and yPtr are stored in R0 and R1 using the Stack Pointer. The locations of xPtr and yPtr are used because swap_pointers() is using a pointer-to-a-pointer call, therefore the address of the pointers are the input arguments (i.e. their locations on the stack). 

<p align="center">
  <img src="https://github.com/dendsl/embsys310/blob/main/assignment05/swapPointers/Answer 1B.JPG">
</p>

**Question C**: Share a screen shot of the local variables inside of “main” after the function swap_pointer() returns showing the values of the pointers and what they are pointing to.   

**Answer:**

<p align="center">
  <img src="https://github.com/dendsl/embsys310/blob/main/assignment05/swapPointers/postSwap.JPG">
</p>

# Problem 2
Create a new file divAsm.s. Start with the Assembly demo code shared in class. Write the assembly code to take an input argument, divide it by 2, and return the result.
Invoke the function “PrintString” from within divAsm before doing the division computation. Add a comment for every statement in your assembly function code. Invoke divAsm() inside of your main function in main.c Run your program on the board and capture a snapshot image of the output from TeraTerm showing the result of the divAsm.

Image of Function *divAsm()*
<p align="center">
  <img src="https://github.com/dendsl/embsys310/blob/main/assignment05/divAsm/divAsm Function.JPG">
</p>


Image of Terra Term output of program
<p align="center">
  <img src="https://github.com/dendsl/embsys310/blob/main/assignment05/divAsm/Terra_Term_Output.JPG">
</p>

# Problem 3
Implement a swap function in assembly and call it “swapCharsAsm”:  
(A) It takes as input two variables of char data type each and swaps the two chars.  
(B) Add a comment for every statement in your assembly function code.  
(C) **Bonus:** Return 0 if the two chars are identical; otherwise, return 1.  
         
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

             }





