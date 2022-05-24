#include<stdio.h>
int main()
{
    char a = 'a';
    char b = 'b';
    printf("%c%c\n",a,b);
    a = a ^ b;
    b = a ^ b;
    a = a ^ b; 
    printf("%c%c\n",a,b);
}