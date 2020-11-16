
// File name: 'stack.h'

#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 10

/*------------------------------------------------------------------
Name:           init_Stack()
Parameters:     None
Description:    Initializes an empty stack of predefined size
                determined by STACK_SIZE.
Returns:        None
------------------------------------------------------------------*/
void init_Stack(void);


/*------------------------------------------------------------------
Name:           delete_Stack()
Parameters:     None
Description:    Deletes the stack by freeing the allocated stack memory
Returns:        None
------------------------------------------------------------------*/
void delete_Stack(void);


/*------------------------------------------------------------------
Name:           get_Curr_Index()
Parameters:     None
Description:    Returns the current index of the stack (i.e. where
                the index the stack is pointing to.
Returns:        indexCurr - Current Index
------------------------------------------------------------------*/
int get_Curr_Index(void);


/*------------------------------------------------------------------
Name:           is_Empty()
Parameters:     None
Description:    Boolean function representing if the stack is empty
Returns:        1 - if the stack is empty
                0 - otherwise
------------------------------------------------------------------*/
int is_Empty(void);


/*------------------------------------------------------------------
Name:           is_Empty()
Parameters:     None
Description:    Boolean function representing if the stack is full
Returns:        1 - if the stack is full
                0 - otherwise
------------------------------------------------------------------*/
int is_Full(void);

/*------------------------------------------------------------------
Name:           reset_Stack()
Parameters:     None
Description:    Erases or resets the contents of the stack to '0'
Returns:        None - sets indexCurr = 0
------------------------------------------------------------------*/
void reset_Stack(void);

/*------------------------------------------------------------------
Name:           pop()
Parameters:     None
Description:    Removes the item from the top of the stack
Returns:        Item removed from the stack
------------------------------------------------------------------*/
int pop(void);


/*------------------------------------------------------------------
Name:           peek()
Parameters:     None
Description:    Reveals the item on the top of the stack but does not 
                remove the item
Returns:        Item removed from the stack
------------------------------------------------------------------*/
int peek(void);


/*------------------------------------------------------------------
Name:           push()
Parameters:     data - item to be pushed onto the stack
Description:    Pushes an item onto the stack
Returns:        None
------------------------------------------------------------------*/
void push(int data);


#endif /* STACK_H */