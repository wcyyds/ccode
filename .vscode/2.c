#include<stdio.h>
#include<string.h>
int main()
{
	char *s = {"Hello World"};

	int n;
    n = strlen(s);
    int size = 0;
    for(n-1; n > 0; n--)
    {
        size++;
        if(s[n] == ' ')
        {
            break;
            return size;
        }
    }
    return size;
}