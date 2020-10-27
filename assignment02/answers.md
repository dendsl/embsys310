1. Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program only once to increment “counter”.
    * Part A - **Question**: What is the value of the “counter” from the “Locals” window?\
    **Answer**: -2147483648
    
    * Part B - **Question**: What is the value of the “counter” in the “Registers” window?\
    **Answer**: 0x80000000
    
    * Part C - **Question**: Please note down if the N and/or V flags are set in the APSR register. And explain why.\
    **Answers**:  
      N = 1 - The *Negative* condition flag was set because the incrementing of a positive-signed variable caused the MSB to become
      *1*, causing the *counter* variable to become negative, triggering the flag.   
      V = 1 - The *Overflow* condition flag was set because the MSB was changed while adding two numbers (in this case: 1 and
      2147483647) that shared the same sign (MSBs were the same).  
      
2. If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program once to increment “counter”.
    * Part A - **Question**: What happens to the value of “counter” in the “Locals” window?\
    **Answer**: counter = 0
    
    * Part B - **Question**: Please note down if the N and/or V flags are set in the APSR register. And explain why.\
    **Answer**:  
      N = 0 - The *Negative* condition flag *not* was set because the incrementing of the negative-signed variable caused the MSB to
      become *0*, causing the *counter* variable to become positive, therefore the negative flag is false.   
      V = 0 - The *Overflow* condition flag was *not* set because the sign of the two numbers (in this case: -1 and 1) are not the
      same. In these cases, overflow never occurs.
    
3. Change the “counter” variable type in your code to “unsigned int”. Inject the values “0x7FFFFFFF” then step thru the program to increment the “counter” once.
    * Part A - **Question**: What is the value of “counter” in the “Locals” window after incrementing for each value?\
    **Answer**: 2147483648
    
    * Part B - **Question**: Please note down if the N and/or V flags are set in the APSR register. And explain why.\
    **Answer**:  
      N = 1 - The *Negative* condition flag was set for the same reasons as Part 1, C. However, we can ignore the result of this
      flag because our variable is *unsigned*. The CPU instruction for setting this flag is the same, regardless if the variable is
      unsigned or signed because the CPU does not know the distinction.   
      V = 1 - The *Overflow* condition flag was set for the same reason as Part 1, C. However, for the reason above - we can ignore
      this flag. 
 
4. Change the “counter” variable type in your code to “unsigned”. Inject the values “0xFFFFFFFF” then step thru the program to increment the “counter” once.
    * Part A - **Question**: What is the value of “counter” in the “Locals” window after incrementing for each value?\
    **Answer**: 0
    
    * Part B - **Question**: Please note down if the N and/or V flags are set in the APSR register. And explain why.\
    **Answer**:  
      N = 0 - The *Negative* condition flag was *not* set because the incrementation resulted in a positive output.   
      V = 0 - The *Overflow* condition flag was *not* set because the incrementation took place between two numbers with different
      MSBs. 
    
5. Move the “counter’ variable outside of main (at the top of the file):
    * Part A - **Question**: What is the scope of the variable “counter”?\
    **Answer**: Global
    
    * Part B - **Question**: Is it still visible in the “Locals” view?\
    **Answer**: No
    
    * Part C - **Question**: In which window view can we track “counter” now?\
    **Answer**: The 'Watch' window
    
    * Part D - **Question** What is the address of the “counter” variable in memory?\
    **Answer**: 0x20000000
    
6. Change the source code to the following, then run the program in the simulator:

        int counter = 0x0;
        int main() {
            int *p_int = (int *)0x20000000;
            ++(*p_int);
            ++(*p_int);
            ++(*p_int);
            counter ++;
            return 0;
        }
        
   * Part A - **Question**: What is the value of “counter” at the end of the program (halting at the return 0 statement)\
    **Answer**: 4
    
    * Part B - **Question**: Explain why the counter value has changed?\
    **Answer**: The pointer accesses the memory location where *counter* is stored. The pointer is then dereferenced to acess the
    value at the memory location of *counter*. Once it has access to the value, it can manipulate it (in this case, increment it). 
    
7. Run the same program on the evaluation board:
    * Part A - **Question**: What is the address where “counter” is stored?\
    **Answer**: 0x20000000
    
    * Part B - **Question**: Is the “counter” variable stored in RAM or ROM?\
    **Answer**: RAM
    
    * Part C - **Question**: What is the value of “counter” at the end of the program (halting at the return 0 statement)?\
    **Answer**: 4
    
    
    
 
    
