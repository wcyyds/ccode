#include <stdio.h>
int main()
{
    for1:for (int i = 0; i < 3; i++)
    {
        for2:for(int j = 0; j < 3; j++)
        {
            if(i = 2)
            {
                break for1 ;
            }
            printf("%d", j);
        }
    }
}