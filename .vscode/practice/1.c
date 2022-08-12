#include <stdio.h>

int fun(int x[], int n)
{
    static int sum = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        sum += x[i];
    }
    return sum;
}
int main()

{

    int a[] = {1, 2, 3, 4, 5};
    int b[] = {6, 7, 8, 9};
    int s = 0;
    s = fun(a, 5) + fun(b, 4);
    printf("%d\n", s);
    return 0;
}