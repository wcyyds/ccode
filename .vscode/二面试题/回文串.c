#include<stdio.h>
#include<string.h>
int main()
{
    char arr[] = {"jdklasdhuihjkfbajn"};
    char nums[100];
    int n = strlen(arr);
    int count = 0;
    int i, j;
    for (i = 0; i < n; i++) 
    {
        if (arr[i] >= 'A' && arr[i] <= 'Z') 
        {
            arr[i] = arr[i] + 32;
        }
        if (arr[i] >= 'a' && arr[i] <= 'z') 
        {
            nums[count++] = arr[i];
        }
    }
    i = 0;
    j = count - 1;
    while (i <= j) {
        if (nums[i] != nums[j]) {
            printf("false");
            break;
        }
        i++;
        j--;
    }
    if (nums[i] == nums[j]) {
        printf("true");
    }
}
