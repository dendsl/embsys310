
void swapCharsAsm(char *a, char *b);

int main(void)
{   
    char a = 'a';
    char z = 'z';
        
    while(1)
    {
      swapCharsAsm(&a, &z);
    }
    
    return;
}

