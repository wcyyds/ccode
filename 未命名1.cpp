#include<stdio.h>

int main()
{
	FILE *p1, *p2;                        //设置两个文件指针
    char filename[30], filename1[30], ch; //设置两个字符数组用来输入文件名用
    printf("请输入要复制的文件名\n");
    gets(filename);
    printf("请输入复制后的文件名\n");
    gets(filename1);
    if ((p1 = fopen(filename, "rb")) == NULL) //打开被复制的文件
    {
        printf("ERROR");

    }
    if ((p2 = fopen(filename1, "wb")) == NULL) //写入要复制的文件名
    {
        printf("ERROR");

    }
    while (!feof(p1)) //用一个检查文件是否结束的函数来进行判断
    {
        ch = fgetc(p1); //读出每一个p1指向的文件的字节，把p1写入到p2指向的文件中去
                        //如果没有p2文件，则会建立一个以filename1字符数组命名的文件
        fputc(ch, p2);
        printf("复制成功");
        fclose(p1); //用完之后，为了避免不必要的操作干扰读写，要关闭文件，即断掉文件指针与文件的练习
        fclose(p2);
    }
 } 
