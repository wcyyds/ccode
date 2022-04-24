#include<stdio.h>
int main()
{
    int arr[] = {1,2,1};
    int i,j,k;
    int n= (sizeof(arr)/4);
    int max=0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(arr[i]<arr[j])
            {
                k = (arr[i]*(j-i));
            }
            else
            {
                k = (arr[j]*(j-i));
            }
            if(max<k)
            {
                max=k;
            }
        }
    }
    printf("%d",max);
}