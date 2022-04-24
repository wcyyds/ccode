#include<stdio.h>
int main()
{
    char text[] = "nlaebolko";
    int i,k;
    int len = (sizeof(text))-1;
    int b=0,a=0,l=0,o=0,n=0;
        for(i=0;i<len;i++)
        {
            if(text[i] == 'b')
            {
                b++;
            }
        }
        for(i=0;i<len;i++)
        {
            if(text[i] == 'a')
            {
                a++;
            }
        }
        for(i=0;i<len;i++)
        {
            if(text[i] == 'l')
            {
                l++;
            }
        }
        for(i=0;i<len;i++)
        {
            if(text[i] == 'o')
            {
                o++;
            }
        }
        for(i=0;i<len;i++)
        {
            if(text[i] == 'n')
            {
                n++;
            }
        }
    if(b>a)
    {
        k=a;
    }
    if(k>(l/2))
    {
        k = (l/2);
    }
    if(k>(o/2))
    {
        k=(o/2);
    }
    if(k>n)
    {
        k=n;
    }

    printf("%d",k);

}