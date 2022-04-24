//选择排序，冒泡排序
#include <stdio.h>
int main ()
{
    int arr[]={1,8,9,2,4,5,2,4,1,456};
    int i;
    //choose(arr);
    bubble(arr);
    for(i = 0; i < 10; i++)
    {
        printf("%d",arr[i]);
    }
}

void choose (int *arr)//选择排序法
{
    int i, j, k, t;
    for(i = 0; i < 10; i++)
    {
        for(j = i; j < 10; j++)
        {
            if(arr[i] > arr[j])
            {
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }

}

void bubble (int *arr)//冒泡排序法
{
    int i, j, t;
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
}