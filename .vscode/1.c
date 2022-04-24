
       #include <stdio.h>
#include <stdio.h>
void move1(int *nums, int n)
{
    int i, j, k = -1;
    int temp;
    for (i = 0; i < n && j < n; i++)
    {
        if (nums[i] == 0)
        {
            if (k = -1)
            {
                j = i + 1;
            }
            else
            {
                j = k + 1;
            }
            for (; j < n; j++)
            {
                if (nums[j] != 0)
                {
                    break;
                }
            }
            if (j != n)
            {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                k = j;
            }
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