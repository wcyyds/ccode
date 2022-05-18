#include"head.h"

int read()
{
	char ch;
	int a = 0;
	int flag = 1;

	while (1)
	{
		scanf("%c", &ch);
		if (ch >= '0' && ch <= '9')
		{
			a = (int)(ch - '0') + a * 10;
		}
		else if (ch == '-' && a == 0)
		{
			flag = -1;
		}
		else
		{
			if (ch == '\n')
			{
				break;
			}
			else
			{
				printf("请输入正确的数字！\n");
				rewind(stdin);
			}
		}
	}
	return a * flag;
}

Node *Link_create(FILE *fp)
{
	Node *head, *stu, *r;
	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	r = head;
	while (!feof(fp))
	{
		stu = (Node*)malloc(sizeof(Node));
		fscanf(fp, "%s %s %s %d %d %d %s", stu->name, stu->num, stu->classname, &stu->Chinese_grades, &stu->Math_grades, &stu->English_grades, stu->password);
		r->next = stu;
		r = stu;
	}
	r->next = NULL;
	return head;
}

//学号查询
Node* Find_num(Node *head, char num[6])
{
	Node *r;
	for (r = head->next; r != NULL && r->next != NULL; r = r->next)
	{
		if (!strcmp(num, r->num))
		{
			break;
		}
	}
	if (r != NULL && r->next != NULL)
	{
		return r;
	}
	else
	{
		return NULL;
	}
}

//姓名查询
Node* Find_name(Node *head, char name[20])
{
	Node *r;
	for (r = head->next; r != NULL && r->next != NULL; r = r->next)
	{
		if (!strcmp(name, r->name))
		{
			break;
		}
	}
	if (r != NULL && r->next != NULL)
	{
		return r;
	}
	else
	{
		return NULL;
	}
}

//查找班级

Node* Find_class(char choice)
{
	Node *head;
	FILE *fp;

	switch (choice)             //根据学号查找班级
	{
	case '1':
	{
		fp = fopen(CL1, "r");
		if (fp == NULL)
		{
			system("cls");
			printf("打开文件失败，按任意键结束程序！\n");
			system("pause");
			exit(1);
		}
		head = Link_create(fp);              //提取班级信息
		printf("%s", head->next->name);
		fclose(fp);
		break;
	}
	case '2':
	{
		fp = fopen(CL2, "r");
		if (fp == NULL)
		{
			system("cls");
			printf("打开文件失败，按任意键结束程序！\n");
			system("pause");
			exit(1);
		}
		head = Link_create(fp);              //提取班级信息
		fclose(fp);
		break;
	}
	case '3':
	{
		fp = fopen(CL3, "r");
		if (fp == NULL)
		{
			system("cls");
			printf("打开文件失败，按任意键结束程序！\n");
			system("pause");
			exit(1);
		}
		head = Link_create(fp);              //提取班级信息
		fclose(fp);
		break;
	}
	case '4':
	{
		fp = fopen(CL4, "r");
		if (fp == NULL)
		{
			system("cls");
			printf("打开文件失败，按任意键结束程序！\n");
			system("pause");
			exit(1);
		}
		head = Link_create(fp);              //提取班级信息
		fclose(fp);
		break;
	}
	case '5':
	{
		fp = fopen(CL5, "r");
		if (fp == NULL)
		{
			system("cls");
			printf("打开文件失败，按任意键结束程序！\n");
			system("pause");
			exit(1);
		}
		head = Link_create(fp);              //提取班级信息
		fclose(fp);
		break;
	}
	default:
	{
		system("cls");
		printf("班级不正确，按任意键重新输入！\n");
		system("pause");
		head = NULL;
		break;
	}
	}
	return head;
}

void print_class_grades(Node *head)
{
	Node *r = head->next;
	int i = 1, grades = 0;
	printf("排名   姓名     学号     语文   数学   英语   总成绩\n");
	for (; r->next != NULL; r = r->next)
	{
		grades = r->Chinese_grades + r->Math_grades + r->English_grades;
		printf("%d     %s    %s      %d     %d     %d     %d\n", i, r->name, r->num, r->Chinese_grades, r->Math_grades, r->English_grades, grades);
		i++;
	}
}

void Link_destroy(Node *head)
{
	Node *r = head;
	Node *s = NULL;
	while (r != NULL)
	{
		s = r->next;
		free(r);
		r = s;
	}
}

void Link_tea_destroy(Teanode *head)
{
	Teanode *r = head;
	Teanode *s = NULL;
	while (r != NULL)
	{
		s = r->next;
		free(r);
		r = s;
	}
}

void Link_save(Node *head, int cla)
{
	char filename[100];
	FILE *fp;
	Node *r;

	switch (cla)
	{
	case 1:
	{
		strcpy(filename, CL1);
		break;
	}
	case 2:
	{
		strcpy(filename, CL2);
		break;
	}
	case 3:
	{
		strcpy(filename, CL3);
		break;
	}
	case 4:
	{
		strcpy(filename, CL5);
		break;
	}
	case 5:
	{
		strcpy(filename, CL5);
		break;
	}
	default:
	{
		system("cls");
		printf("程序运行出错，结束运行！");
		system("pause");
		exit(1);
	}
	}
	fp = fopen(filename, "wt");
	if (fp == NULL)
	{
		system("cls");
		printf("文件打开出错，结束运行！");
		system("pause");
		exit(0);
	}

	//重新写入文件
	for (r = head->next; r->next != NULL && r != NULL; r = r->next)
	{
		fprintf(fp, "%s %s %s %d %d %d %s\n", r->name, r->num, r->classname, r->Chinese_grades, r->Math_grades, r->English_grades, r->password);
	}
	fclose(fp);
}

Teanode *tea_account()
{
	FILE *fp;
	Teanode *head, *tea, *r;

	head = (Teanode*)malloc(sizeof(Teanode));
	head->next = NULL;
	r = head;

	fp = fopen(Teaacc, "r");

	if (fp == NULL)
	{
		system("cls");
		printf("文件打开失败,关闭程序！\n");
		system("pause");
		exit(1);
	}

	while (!feof(fp))
	{
		tea = (Teanode*)malloc(sizeof(Teanode));
		fscanf(fp, "%s %s %s %s %c", tea->name, tea->num, tea->password, tea->cla, &tea->adm);
		r->next = tea;
		r = tea;
	}
	r->next = NULL;

	fclose(fp);
	return head;
}

//教师账户保存
void tea_acc_save(Teanode *head)
{
	Teanode *r;
	FILE *fp;
	fp = fopen(Teaacc, "wt");
	for (r = head->next; r != NULL && r->next != NULL; r = r->next)
	{
		fprintf(fp, "%s %s %s %s %c\n", r->name, r->num, r->password, r->cla, r->adm);
	}
	fclose(fp);
}

//账户查找教师
Teanode *Find_tea(Teanode *head, char num[13])
{
	Teanode *r = head->next;
	for (; r != NULL && r->next != NULL; r = r->next)
	{
		if (strcmp(r->num, num) == 0)
		{
			break;
		}
	}
	if (r == NULL || r->next == NULL)
	{
		return NULL;
	}
	else
	{
		return r;
	}
}

//姓名查找教师
Teanode *Find_tea_name(Teanode *head, char name[13])
{
	Teanode *r = head->next;
	for (; r != NULL && r->next != NULL; r = r->next)
	{
		if (strcmp(r->name, name) == 0)
		{
			break;
		}
	}
	if (r == NULL || r->next == NULL)
	{
		return NULL;
	}
	else
	{
		return r;
	}
}


//升序排序
void stu_sort_up(Node *head)
{
	Node *p = head->next;
	Node *pNext;
	Node *r;
	pNext = p->next;
	p->next = NULL;
	p = pNext;

	while (p != NULL && p->next != NULL)
	{
		pNext = p->next;
		r = head;
		while (r->next != NULL && stu_compare(r->next, p) > 0)
		{
			r = r->next;
		}
		p->next = r->next;
		r->next = p;
		p = pNext;
	}
}

//降序排序

void stu_sort_down(Node *head)
{
	Node *p = head->next;
	Node *pNext;
	Node *r;
	pNext = p->next;
	p->next = NULL;
	p = pNext;

	while (p != NULL && p->next != NULL)
	{
		pNext = p->next;
		r = head;
		while (r->next != NULL && stu_compare(r->next, p) < 0)
		{
			r = r->next;
		}
		p->next = r->next;
		r->next = p;
		p = pNext;
	}
}

int stu_compare(Node *stu1, Node *stu2)
{
	int grades1;
	int grades2;

	grades1 = stu1->Chinese_grades + stu1->Math_grades + stu1->English_grades;
	grades2 = stu2->Chinese_grades + stu2->Math_grades + stu2->English_grades;

	if (grades1 >= grades2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

//创建申诉名单列表

Comp *stu_Compcreate()
{
	FILE *fp;
	Comp *head, *stu, *r;

	head = (Comp*)malloc(sizeof(Comp));
	head->next = NULL;
	r = head;

	fp = fopen(shensu, "r");

	if (fp == NULL)
	{
		system("cls");
		printf("文件打开失败,关闭程序！\n");
		system("pause");
		exit(1);
	}

	while (!feof(fp))
	{
		stu = (Comp*)malloc(sizeof(Comp));
		fscanf(fp, "%s %s %d %s %d %d", stu->name, stu->num, &stu->cla, stu->course, &stu->oidGrades, &stu->newGrades);
		r->next = stu;
		r = stu;
	}
	r->next = NULL;

	fclose(fp);
	return head;
}

void stuComp_save(Comp *head)
{
	Comp *r;
	FILE *fp;
	fp = fopen(shensu, "wt");
	for (r = head->next; r != NULL && r->next != NULL; r = r->next)
	{
		fprintf(fp, "%s %s %d %s %d %d\n", r->name, r->num, r->cla, r->course, r->oidGrades, r->newGrades);
	}
	fclose(fp);
}

void Link_comp_destroy(Comp *head)
{
	Comp *r = head;
	Comp *s = NULL;
	while (r != NULL)
	{
		s = r->next;
		free(r);
		r = s;
	}
}
//提取提醒名单教师信息
Teanode *tea_Remind()
{
	FILE *fp;
	Teanode *head, *tea, *r;

	head = (Teanode*)malloc(sizeof(Teanode));
	head->next = NULL;
	r = head;

	fp = fopen(TeaRemind, "r");

	if (fp == NULL)
	{
		system("cls");
		printf("文件打开失败,关闭程序！\n");
		system("pause");
		exit(1);
	}

	while (!feof(fp))
	{
		tea = (Teanode*)malloc(sizeof(Teanode));
		fscanf(fp, "%s %s %s %s %c", tea->name, tea->num, tea->password, tea->cla, &tea->adm);
		r->next = tea;
		r = tea;
	}
	r->next = NULL;

	fclose(fp);
	return head;
}
//保存教师到提醒名单
void tea_remind_save(Teanode *head)
{
	Teanode *r;
	FILE *fp;
	fp = fopen(TeaRemind, "wt");
	for (r = head->next; r != NULL && r->next != NULL; r = r->next)
	{
		fprintf(fp, "%s %s %s %s %c\n", r->name, r->num, r->password, r->cla, r->adm);
	}
	fclose(fp);
}


int judg_Chinese(char *s)
{
	int s_len;
	int i;
	s_len = strlen(s);
	for (i = 0; i < s_len; i++)
	{
		if (s[i] >> 8 == 0)
		{
			return 0;
		}
	}
	return 1;
}

int judg_repeat_tea(Teanode *thead, char *num)
{
	Teanode *r;
	for (r = thead->next; r != NULL && r->next != NULL; r = r->next)
	{
		if (strcmp(r->num, num) == 0)
		{
			//账号重复
			return 1;
		}
	}
	return 0;
}

int judg_repeat_stu(Node *shead, char *num)
{
	Node * r;
	for (r = shead->next; r != NULL && r->next != NULL; r = r->next)
	{
		if (strcmp(r->num, num) == 0)
		{
			//账号重复
			return 1;
		}
	}
	return 0;
}

