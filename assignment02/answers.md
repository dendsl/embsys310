1. Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program only once to increment “counter”.
    * Part A - **Question**: What is the value of the “counter” from the “Locals” window?\
    **Answer**: -2147483648
    
    * Part B - **Question**: What is the value of the “counter” in the “Registers” window?\
    **Answer**: 0x80000000
    
    * Part C - **Question**: Please note down if the N and/or V flags are set in the APSR register. And explain why.\
    **Answers**: 
    N = 1 - TODO \
    C = 1 - TODO
    
2. If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program once to increment “counter”.
    * Part A - **Question**: What happens to the value of “counter” in the “Locals” window?\
    **Answer**: counter = 0
    
    * Part B - **Question**: Please note down if the N and/or V flags are set in the APSR register. And explain why.\
    **Answer**:
    N = 0 - TODO \
    C = 0 - TODO
    
3. Change the “counter” variable type in your code to “unsigned int”. Inject the values “0x7FFFFFFF” then step thru the program to increment the “counter” once.
    * Part A - **Question**: What is the value of “counter” in the “Locals” window after incrementing for each value?\
    **Answer**: 2147483648
    
    * Part B - **Question**: Please note down if the N and/or V flags are set in the APSR register. And explain why.\
    **Answer**:
    N = 1 - TODO \
    C = 1 - TODO
 
4. Change the “counter” variable type in your code to “unsigned”. Inject the values “0xFFFFFFFF” then step thru the program to increment the “counter” once.
    * Part A - **Question**: What is the value of “counter” in the “Locals” window after incrementing for each value?\
    **Answer**: 0
    
    * Part B - **Question**: Please note down if the N and/or V flags are set in the APSR register. And explain why.\
    **Answer**:
    N = 0 - TODO \
    C = 0 - TODO
    
5. Move the “counter’ variable outside of main (at the top of the file):
    * Part A - **Question**: What is the scope of the variable “counter”?\
    **Answer**: Global
    
    * Part B - **Question**: Is it still visible in the “Locals” view?\
    **Answer**: No
    
    * Part C - **Question**: In which window view can we track “counter” now?\
    **Answer**: The 'Watch' window
    
    * Part D - **Question** What is the address of the “counter” variable in memory?\
    **Answer**: 0x20000000
    
    
    
 
    
