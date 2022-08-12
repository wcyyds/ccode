#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//创建链表
typedef struct Node
{
	int ID;		   //身份证号
	char name[50]; //姓名
	char sex[10];  //性别
	char site[10]; //违章地点
	char time[10]; // 时间
	int sum;	   //总扣分
	struct Node *next;
} node;

node *inithead() //创造新的结点
{
	node *head = NULL;
	head = (node *)malloc(sizeof(node));
	head->next = NULL;
	return head;
}

//目录设计
void makeMenu()
{
	printf("		    老话说:道路千万条,安全第一条。\n");
	printf("	       老话说:葡萄美酒夜光杯，借问醉驾几人回。\n");
	printf("		    所以说啊:别酒驾,酒驾你就无啦!\n");
	printf("\n");
	printf("  	          |2022.5月内酒驾违章查询,敬待君来|\n");
	printf("\n");
	printf("\n");
	printf("  ___________________________------------___________________________\n");
	printf(" |                                                                  |\n");
	printf(" |     乾杯 []~（￣▽￣）~*----菜单目录----*~（￣▽￣）~[] 乾杯     |\n");
	printf(" |                                                                  |\n");
	printf(" |	\t\t1.--[录入违章记录]--                        |\n");
	printf(" |	\t\t2.--[修改违章记录]--                        |\n");
	printf(" |	\t\t3.--[删除违章记录]--                        |\n");
	printf(" |	\t\t4.--[查询违章记录]--                        |\n");
	printf(" |	\t\t5.--[导出违章记录]--                        |\n");
	printf(" |	\t\t0.------[退出]------                        |\n");
	printf(" |__________________________________________________________________|\n");
	printf("\n");
	printf("\n");
	printf("请输入输入对应功能键(0~5):");
}

//创建密码
void code()
{
	char password[10];
	printf("\t请输入密码:");
	gets(password);
	for (; strcmp(password, "rwc");)
	{
		printf("\t请重新输入:");
		gets(password);
	}
	printf("\t密码正确\n\t欢迎光临  (′?｀)\n");
	printf("\n");
}

//录入违章记录
void add()
{
}

// 修改违章记录
void fix()
{
}

//删除违章记录
void erase()
{
}

//查询违章记录
void search(node *L)
{
	printf("%d", L->next->ID);
}

//导出违章记录
void print()
{
}

//文件写入
void readFile(node *head)
{

	FILE *fp;
	int n = 0;
	if ((fp = fopen("2022年5月酒驾违章记录.txt", "r")) == NULL)
	{
		printf("EROOR打开错误");
		exit(0);
	}
	node *q = head;
	node *p = head;
	node *newhead1 = (node *)malloc(sizeof(node));
	p->next = newhead1;
	newhead1->next = NULL;
	while (6 == fscanf(fp, "%d %s %s %s %s %d", &newhead1->ID, newhead1->name, newhead1->sex, newhead1->site, newhead1->time, &newhead1->sum))
	{
		q = q->next;
		node *newhead = (node *)malloc(sizeof(node));
		newhead->next = NULL;
		newhead1->next = newhead;
		newhead1 = newhead1->next;
		n++;
		printf("%d", n);
	}
	q->next = NULL;
	fclose(fp);
}

//文件更新
void writeFile(node *head)
{

	FILE *fp;
	if ((fp = fopen("student.txt", " w")) == NULL)
	{
		printf("EROOR打开错误");
		exit(0);
	}
	node *p = head->next;
	while (p)
	{
		fprintf(fp, "%d %s %s %s %s %d", &p->ID, p->name, p->sex, p->site, p->time, &p->sum);
		p = p->next;
	}
	printf("文件更新成功\n");
	fclose(fp);
}

//目录跳转
void keyDown()
{
	int userkey = 20;
	scanf("%d", &userkey);
	switch (userkey)
	{
	case 1:
		printf("---[录入违章记录]---\n");
		printf("\n");
		break;
	case 2:
		printf("---[修改违章记录]---\n");
		printf("\n");
		break;
	case 3:
		printf("---[删除违章记录]---\n");
		printf("\n");
		break;
	case 4:
		printf("---[查询违章记录]---\n");
		printf("\n");
		break;
	case 5:
		printf("---[导出违章记录]---\n");
		printf("\n");
		break;
	case 0:
		printf("---[退出]---\n");
		printf("\n");
		exit(0); //直接退出模块本程序
		break;
	default:
		printf("出现错误！\n好好看看，再出错给你抓起来\n\n(?￣-￣? ?) 傻子吧? 嫌弃你\n");
		printf("\n");
		break;
	}
}
int main()
{
	node *head = NULL;
	head = inithead(); //创建了一个头结点
	readFile(head);
	code();
	while (1)
	{
		makeMenu();
		keyDown();
		system("pause"); //按任意键继续
	}
	printf("1da6sd1a65d");
	return 0;
}
