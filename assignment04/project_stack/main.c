#include <assert.h>
#include "stack.h"

//----------------------------------------------------------------
// Test Function Prototypes
//----------------------------------------------------------------

/*------------------------------
    Empty and Full Tests
------------------------------*/
// Test "is_Empty()" on an empty stack
void test_isEmpty_Empty_Stack(void);

// Test "is_Full()" on an empty stack
void test_isFull_Empty_Stack(void); 

// Test "is_Empty()" on an non-empty stack
void test_isEmpty_Full_Stack(void);

// Test "is_Full()" on a full stack
void test_isFull_Full_Stack(void); 

/*------------------------------
    Pushing Tests
------------------------------*/
// Test Pushing a single item
void test_Push_Single(void);

// Test Pushing max number of items
void test_Push_All(void);

// Test Pushing an item onto a full stack
void test_Push_Full_Stack(void);

// Test Resetting the stack
void test_Reset_Stack(void);

/*------------------------------
    Popping Tests
------------------------------*/
// Test Popping a single item
void test_Pop_Single(void);

// Test Popping an item from an empty stack
void test_Pop_Empty_Stack(void);

/*------------------------------
    Peeking Tests
------------------------------*/
// Test Peeking a single item from the stack
void test_Peek_Single(void);

// Test Peeking as data fill the entire stack
void test_Peek_Full(void);

// Test Peeking on an empty stack
void test_Peek_Empty_Stack(void);



int main()
{  
  // Test "is_Empty()" on an empty stack
  test_isEmpty_Empty_Stack();
  
  // Test "is_Full()" on an empty stack
  test_isFull_Empty_Stack(); 
  
  // Test "is_Empty()" on an non-empty stack
  test_isEmpty_Full_Stack();
  
  // Test "is_Full()" on a full stack
  test_isFull_Full_Stack(); 
  
  // Test Pushing a single item
  test_Push_Single();
  
  // Test Pushing max number of items
  test_Push_All();
  
  // Test Resetting the stack
  test_Reset_Stack();
  
  // Test Popping a single item
  test_Pop_Single();
 
  // Test Pushing an item onto a full stack
  test_Push_Full_Stack();
  
  // Test Popping an item from an empty stack
  test_Pop_Empty_Stack();
  
  // Test Peeking a single item from the stack
  test_Peek_Single();
  
  // Test Peeking as data fill the entire stack
  test_Peek_Full();
  
  // Test Peeking on an empty stack
  test_Peek_Empty_Stack();
  
  while(1);
  
  return 0;
}


void test_isEmpty_Empty_Stack()
{
  init_Stack();
  assert(is_Empty() == 1);
  
  delete_Stack();
  return;
}


void test_isFull_Empty_Stack()
{
  init_Stack();
  assert(is_Full() != 1);
  
  delete_Stack();
  return;
}


void test_isEmpty_Full_Stack()
{
  init_Stack();
  
  // Fill the stack
  for(int i = 0; i < STACK_SIZE; i++)
  {
    push(i);
    assert(get_Curr_Index() == i);
  }
  
  assert(is_Empty() != 1);
  
  delete_Stack();
  return;
}


void test_isFull_Full_Stack()
{
  init_Stack();
  
  // Fill the stack
  for(int i = 0; i < STACK_SIZE; i++)
  {
    push(i);
    assert(get_Curr_Index() == i);
  }
  
  assert(is_Full() == 1);
  
  delete_Stack();
  return;
}


void test_Push_Single()
{
  init_Stack();
  int currIndex = get_Curr_Index(); 
  push(5);
  assert(get_Curr_Index() == (currIndex + 1));
  
  delete_Stack();
  return;
}

void test_Push_All()
{
   init_Stack();
   // Fill the stack
   for(int i = 0; i < STACK_SIZE; i++)
   {
     push(i);
     assert(get_Curr_Index() == i);
   }
   
  delete_Stack();
  return;
}

void test_Reset_Stack()
{
  init_Stack();
  
  reset_Stack();
  assert(get_Curr_Index() == -1);
  assert(is_Empty() == 1);
  
  // Fill the stack
  for(int i = 0; i < STACK_SIZE; i++)
  {
    push(i);
  }
  
  reset_Stack();
  assert(get_Curr_Index() == -1);
  assert(is_Empty() == 1);
  
  delete_Stack();
  return;
}


void test_Pop_Single()
{
  init_Stack();
  int item = 5;
  push(item);
  
  assert(pop() == item);
  assert(get_Curr_Index() == -1);
  
  delete_Stack();
  return;
}


void test_Push_Full_Stack()
{
  init_Stack();
  // Fill the stack
  for(int i = 0; i < STACK_SIZE; i++)
  {
    push(i);
    assert(get_Curr_Index() == i);
  }
  
  assert(is_Full() == 1);
  assert(get_Curr_Index() == STACK_SIZE - 1);
  
  // Attempt to push onto a full stack
  push(1);
  
  assert(is_Full() == 1);
  assert(get_Curr_Index() == STACK_SIZE - 1);
  
  delete_Stack();
  return;
}


void test_Pop_Empty_Stack()
{
  init_Stack();
  assert(get_Curr_Index() == -1);
  assert(is_Empty() == 1);
  
  int item = pop();
  
  assert(item == -1);
  assert(get_Curr_Index() == -1);
  assert(is_Empty() == 1);
  
  delete_Stack();
  return;
}

void test_Peek_Single()
{
  init_Stack();
  int item = 5;
  push(item);
  
  int currIndex = get_Curr_Index(); 
  assert(peek() == item);
  assert(currIndex == get_Curr_Index());
  
  delete_Stack();
  return;
}


void test_Peek_Full()
{
  init_Stack();
  int currIndex = 0; 
  
  for(int i = 0; i < STACK_SIZE; i++)
  {
    push(i);
    currIndex = get_Curr_Index(); 
    
    assert(peek() == i);
    assert(currIndex == get_Curr_Index());
  }
  
  delete_Stack();
  return;
}


void test_Peek_Empty_Stack()
{
  init_Stack();
  
  assert(peek() == -1);
  
  delete_Stack();
  return;
}


