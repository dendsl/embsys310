
void swap_pointer(int **p1, int **p2);


int main()
{
  int x = 2000000;
  int y = 1000000;
  
  int *xPtr = &x;
  int *yPtr = &y;
  
  swap_pointer(&xPtr, &yPtr);
  
  while(1);
    
  return 0;
}

void swap_pointer(int **p1, int **p2)
{
  int *temp = *p1;      // Obtain value (address) of p1 pointer
  *p1 = *p2;            // Swap address values stored in the pointers
  *p2 = temp;
  
  return;
}