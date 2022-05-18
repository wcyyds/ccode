//文件的使用方法           含义                      如果指定的文件不存在

// r(只读)	    输入数据，打开一个已存在文本文件	     出错
// w(只写）	    输出数据，打开一个文本文件	             建立一个新文件
// a(追加)	    向文本文件尾添加数据	                出错
// rb(只读)	    输入数据，打开一个2进制文件	             出错
// wb(只写)	    输出数据，打开一个2进制文件	             建立新文件0
// r+（读写）	读写，文本文件	                        出错
// w+(读写)	    读写，文本文件	                        建立新文件
// a+（读写）	 读写，文本文件	                        出错
// rb+(读写)	读写，二进制文件	                    出错
// wb+(读写)	读写，二进制文件	                    建立新文件
// ab+(读写)	读写二进制文件	                        出错

//打开文件和关闭文件函数
// fopen(文件名,使用文件方式);打开文件
// fclose(文件名,使用文件方式);关闭文件

// feof(文件指针);当文件结束时返回非零值，当文件未结束时返回0

//字符串的读写文件
// fgets(str,n,fp);从fp指向的文件读入一个长度为n-1的字符串，存放到字符数组str中去；成功返回地址str,失败返回空白
// fputs(str,fp);把str所指向的字符串写入fp所指向的文件中去，成功返回0，失败返回非零

// 格式化的方式读写文本
// fprintf(文件指针，格式字符，输出列表)
// fscanf(文件指针，格式字符串，输入列表)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 15
#define NUM 2

struct Student
{
    char name[LEN];
    int num;
    int age;
    char add[LEN]; //地址
} Stud[NUM];

// 1.输入字符串，写进一个叫text.exe的文件中
void wscanffile() //如果再次进行书写会把上次输入的内容清除并且重新输入新的内容
{
    FILE *p;                                  //设置一个文件指针
    char ch;                                  //定义一个字符变量
    if ((p = fopen("test.txt", "w")) == NULL) //打开一个叫test的文件，用只写的方式。当出错时，返回空，输出ERROE
    {
        printf("ERROR");
        exit(0); //关闭所有文件种植正在进行的程序
    }

    for (; ch != '\n';)
    {
        scanf("%c", &ch);
        fputc(ch, p); //将字符ch写入p所指向的文件
    }
    fclose(p);
}

// 2.读取一个叫text.exe的文件
void printfile()
{
    FILE *p;
    char ch;
    if ((p = fopen("test.txt", "r")) == NULL)
    {
        printf("ERROR");
        exit(0);
    }

    for (; ch != '\n';)
    {
        ch = fgetc(p); // ch得到的p所指的文件的每一个字符
        putchar(ch);   //将得到的字符输出在屏幕上
    }
    fclose(p);
}

// 3.
void ascanffile() //写入,是一个一个给下面写入的（保留原有内容）
{
    FILE *p;
    char ch;
    if ((p = fopen("test.txt", "a")) == NULL)
    {
        printf("ERROR");
        exit(0);
    }

    for (; ch != '\n';)
    {
        scanf("%c", &ch);
        fputc(ch, p); //将字符ch写入p所指向的文件
    }
    fclose(p);
}

// 4.复制一个文件
void copy()
{
    FILE *p1, *p2;                        //设置两个文件指针
    char filename[30], filename1[30], ch; //设置两个字符数组用来输入文件名用
    printf("请输入要复制的文件名\n");
    gets(filename);
    printf("请输入复制后的文件名\n");
    gets(filename1);
    if ((p1 = fopen(filename, "rb")) == NULL) //打开被复制的文件
    {
        printf("ERROR打开错误");
        exit(0);
    }
    if ((p2 = fopen(filename1, "wb")) == NULL) //写入要复制的文件名
    {
        printf("ERROR写入错误");
        exit(0);
    }
    while (!feof(p1)) //用一个检查文件是否结束的函数来进行判断
    {
        ch = fgetc(p1); //读出每一个p1指向的文件的字节，把p1写入到p2指向的文件中去
                        //如果没有p2文件，则会建立一个以filename1字符数组命名的文件
        fputc(ch, p2);
    }
    printf("复制成功");
    fclose(p1); //用完之后，为了避免不必要的操作干扰读写，要关闭文件，即断掉文件指针与文件的练习
    fclose(p2);
}

// 5.用fgets函数，读取fp指向的文件名，并输出上面的文字
void fgetsfile()
{
    FILE *fp;
    char filename[40], string[30]; //定义一个字符数组来存储文件里面的信息
    printf("请输入要打开的文件名");
    gets(filename);
    if ((fp = fopen(filename, "r")) == NULL) //用只读的方式打开文件
    {
        printf("ERROR");
        exit(0);
    }
    fgets(string, 20, fp); //将fp所指的文件中的20个字符读给字符串string
    fclose(fp);            //关闭文件
    puts(string);          //以字符串形式输出string
}

// 6.格式化的方式读写文本
// fprintf(文件指针，格式字符，输出列表)
// fscanf(文件指针，格式字符串，输入列表)
void geshihuafile()
{
    int i = 3;
    float j = 4.567;
    char string[20];
    FILE *fp;
    if ((fp = fopen("test.txt", " r+")) == NULL) //以读写的方式打开test
    {
        printf("EROOR打开错误");
        exit(0);
    }
    fscanf(fp, "%s", string); //把其中的字符写入字符数组string中
    puts(string);
    fprintf(fp, "%3d,%6.4f", i, j);
    printf("****\n");
    fclose(fp);
}

// 7.用二进制的方式向文件读写一组数据(也称数据块读写)
//数据块读写多用于结构体变量的读写（因为结构体所占的字符数是不规则的）
// fread(buffer,size,count,fp)
// fwrite(buffer,size,count,fp)

// buffer
// 用于接收数据的内存地址（是一个指针，无论输出或者输入都是首地址）

// size
// 要读的每一个数据项的字节数，单位是字节

// count
// 要读的count个数据项，每一个数据size个字节

// stream
// 文件指针
void shujukuaiscanffile()
{

    FILE *fp;

    int i;

    if ((fp = fopen("student", "wb")) == NULL) //建立一个叫student的文件以二进制形式进行打开进行写入操作，
    {
        printf("ERROR");

        exit(0);
    }

    printf("请输入学生数据\n");

    for (i = 0; i < NUM; i++) //
    {
        scanf("%s%d%d%s", &Stud[i].name, &Stud[i].num, &Stud[i].age, &Stud[i].add); //输入学生数据信息
    }

    for (i = 0; i < NUM; i++)
    {
        if (fwrite(&Stud[i], sizeof(struct Student), 1, fp) != 1) //每次写一个结构体变量所占的字节，将输入的数据写入文件
        {
            printf("write error");
        }
    }

    fclose(fp); //关闭文件
}

void shujukuaiprintfile()
{

    FILE *fp;

    int i;

    if ((fp = fopen("student", "rb")) == NULL) //以二进制的方式读取
    {
        printf("ERROR读取错误");

        exit(0);
    }

    printf("姓名 学号 年龄 地址\n");

    for (i = 0; i < NUM; i++) //将数据每次一个结构体变量所占字节的个数的数据赋给结构体变量
    {
        if (fread(&Stud[i], sizeof(struct Student), 1, fp) != 1)
        {
            printf("read error");
        }
    }

    for (i = 0; i < NUM; i++) //输出结构体变量的各个成员，输出数据
    {
        printf("%-10s%4d%4d%-15s", Stud[i].name, Stud[i].num, Stud[i].age, Stud[i].add);
        printf("\n");
    }

    fclose(fp); //关闭文件
}

// // rewind 功能是将文件内部的指针重新指向一个文件的开头
// void rewind()
// {

//     FILE *fp, *fp1;

//     int i;

//     if ((fp = fopen("student", "rb")) == NULL)
//     {
//         printf("ERROR");

//         exit(0);
//     }
//     if ((fp1 = fopen("CSDN", "wb")) == NULL) //以写入的方式打开一个文件
//     {
//         printf("ERROR");

//         exit(0);
//     }

//     printf("姓名     学号   年龄     地址\n");

//     for (i = 0; i < NUM; i++) //把文件中的数据读入结构体数组的元素
//     {
//         if (fread(&Stud[i], sizeof(struct Student), 1, fp) != 1)
//         {
//             printf("read error");
//         }
//     }

//     rewind(fp); //重置文件指针

//     for (i = 0; i < NUM; i++) //写入新的文件中
//     {
//         if (fwrite(&Stud[i], sizeof(struct Student), 1, fp1) != 1)
//         {
//             printf("read error");
//         }
//     }

//     for (i = 0; i < NUM; i++) //输出文件数据
//     {
//         printf("%-10s%4d%4d%15s", Stud[i].name, Stud[i].num, Stud[i].age, Stud[i].add);
//         printf("\n");
//     }

//     fclose(fp);
//     fclose(fp1);
// }

int main()
{
    geshihuafile();
}