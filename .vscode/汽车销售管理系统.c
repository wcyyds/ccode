#include <stdio.h>
#include <string.h>//�����ַ����� 
#include <conio.h>
#include <stdlib.h>//���а���system���� 
#define N 100 
struct car//������Ϣ 
{
	char carname[15];//������Ʒ�� 
	char model[10];//�������ͺ� 
	int saleprice;//�����Ľ��� 
	int  soldprice;//�������ۼ� 
    int gain;//ӯ�� 
}car[N];
int n=0;//nΪ����������Ԫ�ظ���
r_f() //���ļ�����
{
	FILE*fp;
	int i=0;
	fp=fopen("car.txt","rt");//�Զ��ı��ļ���ʽ�� D�̵�car.txt,ע����ļ������ֶ��ڵ����ϴ���
	while(feof(fp)==0) //���ļ�δ���������滹����Ϣδ�����꣩ʱѭ��
	{
		fread(&car[i],sizeof(struct car),1,fp);//��fp�а�1��struct car��С����Ϣ����ṹ������
		i++; 
	 } 
	 fclose(fp);//�ر��ļ�
	 n=i-1;// ���������е���ЧԪ�ظ�����������Ӧ��n=i,ʵ���з���n=i-1�������� 
 } 
 s_f()//���ļ�����
 {
 	FILE*fp;
 	int i;
 	fp=fopen("car.txt","wt");//��д�ı��ļ���ʽ��D�̵�car.txt,��ʱ�ļ������ݻᱻ���
	 for(i=0;i<n;i++) 
	 fwrite(&car[i],sizeof(struct car),1,fp);//�ӽṹ�������а�1��struct car��С����Ϣд��fp
	 fclose(fp);//�ر��ļ�����ʱfp�е����ݻ�д��Ӳ���ļ�d:\\car.txt 
 }
 input()//���뺯��
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

main()//������
{
	int c;
	r_f();//��Ӳ���ļ����ݶ���ṹ������
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
	 s_f();//���ṹ�������е���Ϣд��Ӳ���ļ� 
	
 } 

 

  
  
 
 
  
  

