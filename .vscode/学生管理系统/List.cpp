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
				printf("��������ȷ�����֣�\n");
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

//ѧ�Ų�ѯ
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

//������ѯ
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

//���Ұ༶

Node* Find_class(char choice)
{
	Node *head;
	FILE *fp;

	switch (choice)             //����ѧ�Ų��Ұ༶
	{
	case '1':
	{
		fp = fopen(CL1, "r");
		if (fp == NULL)
		{
			system("cls");
			printf("���ļ�ʧ�ܣ����������������\n");
			system("pause");
			exit(1);
		}
		head = Link_create(fp);              //��ȡ�༶��Ϣ
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
			printf("���ļ�ʧ�ܣ����������������\n");
			system("pause");
			exit(1);
		}
		head = Link_create(fp);              //��ȡ�༶��Ϣ
		fclose(fp);
		break;
	}
	case '3':
	{
		fp = fopen(CL3, "r");
		if (fp == NULL)
		{
			system("cls");
			printf("���ļ�ʧ�ܣ����������������\n");
			system("pause");
			exit(1);
		}
		head = Link_create(fp);              //��ȡ�༶��Ϣ
		fclose(fp);
		break;
	}
	case '4':
	{
		fp = fopen(CL4, "r");
		if (fp == NULL)
		{
			system("cls");
			printf("���ļ�ʧ�ܣ����������������\n");
			system("pause");
			exit(1);
		}
		head = Link_create(fp);              //��ȡ�༶��Ϣ
		fclose(fp);
		break;
	}
	case '5':
	{
		fp = fopen(CL5, "r");
		if (fp == NULL)
		{
			system("cls");
			printf("���ļ�ʧ�ܣ����������������\n");
			system("pause");
			exit(1);
		}
		head = Link_create(fp);              //��ȡ�༶��Ϣ
		fclose(fp);
		break;
	}
	default:
	{
		system("cls");
		printf("�༶����ȷ����������������룡\n");
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
	printf("����   ����     ѧ��     ����   ��ѧ   Ӣ��   �ܳɼ�\n");
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
		printf("�������г����������У�");
		system("pause");
		exit(1);
	}
	}
	fp = fopen(filename, "wt");
	if (fp == NULL)
	{
		system("cls");
		printf("�ļ��򿪳����������У�");
		system("pause");
		exit(0);
	}

	//����д���ļ�
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
		printf("�ļ���ʧ��,�رճ���\n");
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

//��ʦ�˻�����
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

//�˻����ҽ�ʦ
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

//�������ҽ�ʦ
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


//��������
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

//��������

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

//�������������б�

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
		printf("�ļ���ʧ��,�رճ���\n");
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
//��ȡ����������ʦ��Ϣ
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
		printf("�ļ���ʧ��,�رճ���\n");
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
//�����ʦ����������
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
			//�˺��ظ�
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
			//�˺��ظ�
			return 1;
		}
	}
	return 0;
}

