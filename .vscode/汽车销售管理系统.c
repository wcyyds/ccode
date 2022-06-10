#include <stdio.h>
#include <string.h>//定义字符数组 
#include <conio.h>
#include <stdlib.h>//其中包含system函数 
#define N 100 
struct car//汽车信息 
{
	char carname[15];//汽车的品牌 
	char model[10];//汽车的型号 
	int saleprice;//汽车的进价 
	int  soldprice;//汽车的售价 
    int gain;//盈利 
}car[N];
int n=0;//n为数组中现有元素个数
r_f() //读文件函数
{
	FILE*fp;
	int i=0;
	fp=fopen("car.txt","rt");//以读文本文件形式打开 D盘的car.txt,注意此文件必须手动在电脑上创建
	while(feof(fp)==0) //当文件未结束（里面还有信息未被读完）时循环
	{
		fread(&car[i],sizeof(struct car),1,fp);//从fp中把1块struct car大小的信息读入结构体数组
		i++; 
	 } 
	 fclose(fp);//关闭文件
	 n=i-1;// 修正数组中的有效元素个数，理论上应该n=i,实际中发现n=i-1才能运行 
 } 
 s_f()//存文件函数
 {
 	FILE*fp;
 	int i;
 	fp=fopen("car.txt","wt");//以写文本文件形式打开D盘的car.txt,此时文件中数据会被清空
	 for(i=0;i<n;i++) 
	 fwrite(&car[i],sizeof(struct car),1,fp);//从结构体数组中把1块struct car大小的信息写入fp
	 fclose(fp);//关闭文件，此时fp中的内容会写入硬盘文件d:\\car.txt 
 }
 input()//输入函数
 {
 	int i=n;
 	int c;
 	do
 	{
 		printf("carname:");scanf("%s",&car[i].carname);
 		printf("model:");scanf("%s",&car[i].model);
 		printf("saleprice:");scanf("%d",&car[i].saleprice);
 		printf("soldprice:");scanf("%d",&car[i].soldprice);
 		printf("gain:");scanf("%d",&car[i].gain);
 		i++;
 		printf("continue(1/0)?");scanf("%d",&c);
	 }
	 while(c==1);
	 n=i;	 
}

main()//主函数
{
	int c;
	r_f();//将硬盘文件内容读入结构体数组
	do
	{
		system("cls");
		printf("\n\n\t\tcar\n\n");
		printf("\t\t1.input\n");
		printf("\t\t0.quit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:input();break;
			case 0:break;
		}
	 } 
	 while (c!=0);
	 s_f();//将结构体数组中的信息写入硬盘文件 
	
 } 

 

  
  
 
 
  
  

