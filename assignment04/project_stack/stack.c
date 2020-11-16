
// File name: 'stack.c'

#include <stdlib.h>
#include "stack.h"
 

static int *pStack;     // Pointer to base of the stack allocated in memory
static int indexCurr;   // Tracks the current (top) index of the stack      

/*------------------------------------------------------------------
Name:           init_Stack()
Parameters:     None
Description:    Initializes an empty stack of predefined size
                determined by STACK_SIZE.
Returns:        None
------------------------------------------------------------------*/
void init_Stack()
{
  pStack = (int *)calloc(/* size */ STACK_SIZE, sizeof(int));
  indexCurr = -1;
}


/*------------------------------------------------------------------
Name:           delete_Stack()
Parameters:     None
Description:    Deletes the stack by freeing the allocated stack memory
Returns:        None
------------------------------------------------------------------*/
void delete_Stack(void)
{
  free(pStack);
  pStack = NULL;
  indexCurr = -1;
}


/*------------------------------------------------------------------
Name:           get_Curr_Index()
Parameters:     None
Description:    Returns the current index of the stack (i.e. where
                    the index the stack is pointing to.
Returns:        indexCurr - Current Index
------------------------------------------------------------------*/
int get_Curr_Index(void)
{
  return indexCurr;
}


/*------------------------------------------------------------------
Name:           is_Empty()
Parameters:     None
Description:    Boolean function representing if the stack is empty
Returns:        1 - if the stack is empty
                0 - otherwise
------------------------------------------------------------------*/
int is_Empty(void)
{
  return ((indexCurr == -1) ? 1 : 0);
}


/*------------------------------------------------------------------
Name:           is_Empty()
Parameters:     None
Description:    Boolean function representing if the stack is full
Returns:        1 - if the stack is full
                0 - otherwise
------------------------------------------------------------------*/
int is_Full(void)
{
  return ((indexCurr == STACK_SIZE - 1) ? 1 : 0);
}


/*------------------------------------------------------------------
Name:           reset_Stack()
Parameters:     None
Description:    Sets indexCurr to 0 - effectively resetting the stack.
                Note: We do not need to set the remaining contents of
                      the stack to '0' because resetting the indexCurr
                      treats the data past the indexCurr as garbage.
Returns:        None - sets indexCurr = 0
------------------------------------------------------------------*/
void reset_Stack(void)
{
  indexCurr = -1;
}


/*------------------------------------------------------------------
Name:           pop()
Parameters:     None
Description:    Removes the item from the top of the stack
Returns:        Item removed from the stack. Else if the stack is empty,
                    returns -1.
------------------------------------------------------------------*/
int pop(void)
{
  int item;
  if (!is_Empty())
  {
    item = pStack[indexCurr--];
  }
  else 
  {
    item = -1;
  }
  
  return item;
}


/*------------------------------------------------------------------
Name:           peek()
Parameters:     None
Description:    Reveals the item on the top of the stack but does not 
                    remove the item
Returns:        Item removed from the stack
------------------------------------------------------------------*/
int peek(void)
{
  int item;
  if (!is_Empty())
  {
    item = pStack[indexCurr];
  }
  else 
  {
    item = -1;
  }
  return item;
}


/*------------------------------------------------------------------
Name:           push()
Parameters:     data - item to be pushed onto the stack
Description:    Pushes an item onto the stack. indexCurr is incremented 
                    before the item is e item is placed on the stack 
Returns:        None
------------------------------------------------------------------*/
void push(int data)
{
  if (!is_Full())
  {
    pStack[++indexCurr] = data;
  }
  return;
}

