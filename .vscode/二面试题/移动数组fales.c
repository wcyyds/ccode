#include <stdio.h>
int main()
{
    int nums[5] = {0,0,0,1,0};
    int nums1[5] ={0,0,0,1,0};
    int n = (sizeof(nums) / 4);
    int i, j, k = 0;
    for (i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            nums1[k] = nums[i];
            k++;
        }
    }
    for (i = 0; i < (n - k); i++)
    {
        nums1[n - i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        printf("%d.", nums1[i]);
    }
}