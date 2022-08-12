#include <stdio.h>
struct student
{
    int sex;
    char name[9];
} stu[50];
int main()
{
    int n;
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %s", &stu[i].sex, stu[i].name);
    }
    for (i = 0; i < n; i++)
    {
        for (j = n - 1; j >= i; j--)
        {
            if (stu[i].sex != stu[j].sex && stu[j].sex != 3)
            {
                printf("%s %s\n", stu[i].name, stu[j].name);
                stu[j].sex = 3;
                break;
            }
        }
    }
}

/*
8
0 Amy
1 Tom
1 Bill
0 Cindy
0 Maya
1 John
1 Jack
0 Linda
*/