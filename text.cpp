#include <stdio.h>
#define min 60
int main(void)
{
int n,m,h;
scanf("%d",&n);
while (n<=0)
{
    m=n%60;
    h=n/60;
    printf("hour=%d,min=%d",h,m);
    scanf("%d",&n);
}

}