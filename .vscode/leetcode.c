#include<stdio.h>
#include<stdlib.h>
typedef union a{
int number;
char string[10];
}b;
typedef struct c{
b d;
int e;
double f;
char h;
//b i;
}g;
int main(void){
printf("%d\n",sizeof(b));
printf("%d\n",sizeof(g));
return 0;
}
