#include <stdio.h>
#include <stdlib.h>
int first()
{
    int n = 6, m = 0;
    printf("&n=%p\n", &n);
    printf("&m=%p\n", &m);

    int *p = &n;
    int **pp = &p;

    printf("n=%d\nn=%d\n", *p, **pp);
}
//一维指针存放变量的地址，二维指针存放一维指针的地址

int second()
{

    // 指针与数组之间关系
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int *p = arr;
    for (int i = 0; i < 6; ++i)
    {
        printf("%d\n", p[i]);
    }

    // 二维指针与指针数组之间关系
    int arr2[6] = {7, 8, 9, 10, 11, 12};
    int *parr[] = {arr, arr2};
    int **pp = parr;

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            printf("%d ", pp[i][j]);
        }
        printf("\n");
    }
    printf("--------------\n");
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            printf("%d ", parr[i][j]);
        }
        printf("\n");
    }
}

//二维指针作为函数参数
void Fun_b(int **pp)
{
    int *p = malloc(sizeof(int));
    *p = 100;
    *pp = p;
    printf("&p=%p\np=%p\n*p=%d\n", &p, p, *p);
}
int Fun_a()
{
    int *p = NULL;
    Fun_b(&p);
    printf("------%p-----\n", &p);
    printf("&p=%p\np=%p\n*p=%d\n", &p, p, *p);
    free(p);
    p = NULL;
}

//二维指针作为函数返回值
//创建一个矩阵r*c

int **CreateIdentityMatrix(int r, int c)
{
    int **pm = (int **)malloc(sizeof(int *) * r);
    for (int i = 0; i < r; ++i)
    {
        pm[i] = (int *)malloc(sizeof(int) * c);
        for (int j = 0; j < c; ++j)
        {
            pm[i][j] = (i == j);
        }
    }
    return pm;
}

void PrintMatrix(int **pm, int r, int c)
{
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            printf("%d ", pm[i][j]);
        }
        printf("\n");
    }
}


int main1()
{
    int r, c;
    scanf("%d%d", &r, &c);
    int **pm = CreateIdentityMatrix(r, c);
    PrintMatrix(pm, r, c);
}
