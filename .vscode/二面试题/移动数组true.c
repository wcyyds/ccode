#include <stdio.h>
#include <stdio.h>
void move1(int *nums, int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            j = i + 1;
            while (nums[j] != 0 && j < n)
            {
                
                j++;
            }
            k = nums[j];
            nums[j] = nums[i];
            nums[i] = k;
        }
    }
}

int main()
{
    int nums[] = {1, 0, 8, 0, 4};
    int n = (sizeof(nums) / 4);
    int i;
    move1(nums, n);
    for (i = 0; i < n; i++)
        printf("%d", nums[i]);
}