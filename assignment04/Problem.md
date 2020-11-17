# Problem 1  
Follow the same steps as we did in the class to blink LED1 (PA5) at a visible rate using the bitband region to enable the clock to Port A, then answer the following:  

**Question A**: What instructions does the compiler produce in assembly for “writing” to the GPIO bit when using bit-band address?  

**Answer** The compliler produces the 'STR' instruction which tells the CPU to store the value in *R0* (our clock enable toggle) immediately into the address at *R1* (the Bit-Band Alias address for RCC_AHB2ENR)

<p align="center">
  <img src="https://github.com/dendsl/embsys310/blob/main/assignment04/project_bit_band/debug_bit_band.JPG">
</p>

**Question B**: What were the instructions produced when writing to the GPIOx_ODR without using bit-banding?  

**Answer** Unlike in Bit-Banding, the compliler generates three instructions to write to RCC_AHB2ENR. First, it must load the value stored at the address of RCC_AHB2ENR (represented by the *LDR* instruction). Second, it performs a logical or operation (denoted by the *ORRS.W* instruction) on the value of the RCC_AHB2ENR register, and our clock enable toggle and stores that operation back into Register *R1*. Finally, it stores the value of Register *R1* back into the address of RCC_AHB2ENR.

<p align="center">
  <img src="https://github.com/dendsl/embsys310/blob/main/assignment04/project_bit_band/debug_register_manipulation.JPG">
</p>


# Problem 2 
Create a function “func1” with 5 arguments and call “func1” from within another function “func2”. Trace thru the assembler and note:  

    void func1(int param1, int param2, int param3, int param4, int param5)
    {
        int temp1 = param1;
        int temp2 = param2;
        int temp3 = param3;
        int temp4 = param4;
        int temp5 = param5;
        
        return;
    }
     
    void func2(void)
    {
        func1(1,2,3,4,5);
        
        return;
    }

**Question A**: How does the **calling** function “func2” pass the values to the **called** function “func1”?

**Answer** The values passed into "func1" within the calling function "func2" are moved (using MOVs) into the CPU's general purpose Registers R0-R3. Note that there are five variables and only 4 general purpose registers use, the compiler pushed the extra value onto the stack using the STR operation. "func1" then moves the values stored on the general purpose registers R0-R4 into the R5-R7, R12 general purpose registers. What this is doing is essentially making *copies* of the values of "func2" for "func1" to use.

**Question B**: What extra code did the compiler generate before calling the function “func1” with the multiple arguments?

**Answer** The compiler pushed R7 and LR onto the stack. The compiler then moved the values-to-be-passed into the CPU's general purpose Registers R0-R3. Note that there are five variables and only 4 general purpose registers use, the compiler pushed the extra value onto the stack using the STR operation. Once the moving operations were completed, the compiler branched to "func1".

**Question C**: What extra code did the compiler generate inside the called function “funct1” with the multiple list of arguments?

**Answer** The compiler pushed R4-R7 and LR onto the stack and also popped the value of *param1* off the Stack Pointer and moved it into R4. The compiler then moved (copied) the values of Registers   R0-R4 into Registers R5-R7, R12, and LR for "func1"'s use.

**Question D**: Any other observations?

**Answer**
- the values passed to "func1" were moved in reverse order (i.e. param5, then param4, etc.)
- Param5 was stored onto Register R0, then stored on the Stack Pointer. It was then overwritten by Param4 being moved into R0.
- Param5 was then loaded into R4 from the Stack Pointer once entering "func1". I don't understand why the values while in "func2" weren't loaded into R0-R4 to begin with (versus: R0, R0-R3). Seems a bit redudant.
- The values were copied from R0-R4 into R5-R7, R12, and LR. Why were they not copied into R5-R9?
- Once exiting "func1", Registers R4-R7 were popped. R0-R3 remained with values
- Once exiting "func2", R0 was popped (with a value of 1; value of param1) therefore revertting back to a value of 5 (value of param5)


