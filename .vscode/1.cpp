#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//��������
typedef struct Node
{
	char ID[50];			 //���֤��
	char name[50];			 //����
	char sex[50];			 //�Ա�
	char site[10], time[10]; //Υ�µص� & ʱ��
	int sum;				 //�۷�

	struct Node *next;
} node;

node List;
node *pHead = (node *)malloc(sizeof(node));
//��������
void code()
{
	char password[10];
	printf("\t����������:");
	gets(password);
	for (; strcmp(password, "rwc");)
	{
		printf("\t����������:");
		gets(password);
	}
	printf("\t������ȷ\n\t��ӭ����  (��?��)\n");
	printf("\n");
}

//�ļ�����
int readFile(Node *L)
{
	FILE *fp = fopen("2022��5�¾Ƽ�Υ�¼�¼.txt", "r");

	node st;
	node *s;
	node *t = L;

	if (fp == NULL)
	{
		printf("���ִ���!\n�úÿ������ٳ������ץ����\n\n(?��-��? ?) ɵ�Ӱ�? ������\n");
		return 0;
	}
	else
	{
		while (fscanf(fp, "%s %s %s %s %s %d ", st.ID, st.name, st.sex, st.site, st.time, &st.sum) != EOF)
		{
			// printf("%s,%s,%s,%s,%s,%d",st.ID,st.name,st.sex,st.site,st.time,st.sum);
			s = (node *)malloc(sizeof(node));

			*s = st;
			s->next = t->next;
			t->next = s;
		}
	}
	fclose(fp);
	return 1;
}

//���滺���������ļ�
int saveFile(node *L)
{
	printf("egoewgh"); //��֤�Ƿ����е���
	FILE *fp = fopen("2022��5�¾Ƽ�Υ�¼�¼.txt", "w");
	if (fp == NULL)
		return 0;

	node *p = pHead; //= L->next;

	printf("%s", pHead->name); //��֤�Ƿ����е���

	while (p->next != NULL)
	{

		fprintf(fp, "%s %s %s %s %s %d ", p->ID, p->name, p->sex, p->site, p->time, p->sum);

		p = p->next;
	}
	fclose(fp);
	return 1;
}

//��ȡ�ļ�
// int readFile(node* L);

//������ͷ������ν�����ṹ�������
// node* s()
//{
//	node* s = (node*)malloc(sizeof(node));
//	assert (s);		//���ԣ������ж�ָ���Ƿ�Ϊ�գ�Ϊ�ս������ϵ㣩
//	s->next = NULL;
//	return s;
//}

//Ŀ¼���
void makeMenu()
{
	printf("		    �ϻ�˵:��·ǧ����,��ȫ��һ����\n");
	printf("	       �ϻ�˵:��������ҹ�Ɑ��������ݼ��˻ء�\n");
	printf("		    ����˵��:��Ƽ�,�Ƽ��������!\n");
	printf("\n");
	printf("  	          |2022.5���ھƼ�Υ�²�ѯ,��������|\n");
	printf("\n");
	printf("\n");
	printf("  ___________________________------------___________________________\n");
	printf(" |                                                                  |\n");
	printf(" |     Ǭ�� []~����������~*----�˵�Ŀ¼----*~����������~[] Ǭ��     |\n");
	printf(" |                                                                  |\n");
	printf(" |	\t\t1.--[¼��Υ����Ϣ]--                        |\n");
	printf(" |	\t\t2.--[�޸�Υ�¼�¼]--                        |\n");
	printf(" |	\t\t3.--[ɾ��Υ�¼�¼]--                        |\n");
	printf(" |	\t\t4.--[��ѯΥ�¼�¼]--                        |\n");
	printf(" |	\t\t5.--[����Υ�¼�¼]--                        |\n");
	printf(" |	\t\t0.------[�˳�]------                        |\n");
	printf(" |__________________________________________________________________|\n");
	printf("\n");
	printf("\n");
	printf("�����������Ӧ���ܼ�(0~5):");
}

//¼��Υ�¼�¼
//ͷ�巨
void insertInfo(node *L, node e)
{
	node *h = L;
	node *s = (node *)malloc(sizeof(node));
	*s = e;

	if (pHead == NULL)
	{
		pHead->next = s;
	}
	else
	{
		s->next = pHead->next;
		pHead->next = s;
	}

	//		s->next = h->next;
	//		h->next = s;

	saveFile(pHead);
}

//		node *h = L;
//		node *s = (node *)malloc(sizeof(node));
void add()
{

	node st;
	printf("�뿪ʼ��������Υ����Ϣ\n");
	// printf ("(�������¼��,�밴'0')\n\n");
	printf("���֤����: ");
	scanf("%s", st.ID);
	// if (st.ID[1] != 0)
	//{

	printf("����: ");
	scanf("%s", st.name);
	printf("�Ա�: ");
	scanf("%s", st.sex);
	printf("�ص�: ");
	scanf("%s", st.site);
	printf("ʱ��: ");
	scanf("%s", st.time);
	printf("�۷�: ");
	scanf("%d", &st.sum);
	getchar();
	insertInfo(&List, st);
	//	}
}

//��ѯΥ�¼�¼
//�����֤���Ų�ѯ
node *searchInfoByID(char ID[50], node *L)
{
	node *p = L;
	while (p != NULL)
	{
		//	printf("%s",p->ID);
		if (strcmp(p->ID, ID) == 0)
		{

			return p;
		}

		p = p->next;
	}
	return NULL;
}

//��������ѯ
node *searchInfoByname(char name[50], node *L)
{
	node *p = L;
	while (p != NULL)
	{
		if (strcmp(name, p->name) == 0)
		{
			return p;

			break;
		}

		p = p->next;
	}
	return NULL;
}

void search(node *L)
{
	readFile(L);
	int choice;
	char ID[50], name[50];
	node *st;
	printf("��ѡ���ѯΥ�¼�¼��ʽ:  \n");
	printf("�����֤���Ų�ѯ---1\n");
	printf("��������ѯ---------2\n");
	scanf("%d", &choice);
	if (choice == 1)
	{
		printf("������Ҫ��ѯ�����֤����: \n");
		scanf("%s", ID);
		st = searchInfoByID(ID, L);

		if (st == NULL)
		{
			printf("���޴��� !\n");
		}
		else
		{

			printf("_________________________________________________\n");
			printf("|���֤����\t|����\t|�Ա�\t|�ص�\t|ʱ��\t|�۷�\t|\n");
			printf("_________________________________________________\n");
			printf("%s|%s\t|%s\t|%s\t|%s\t|%d\t|\n", st->ID, st->name, st->sex, st->site, st->time, st->sum);
			printf("_________________________________________________\n");
		}
	}
	else if (choice == 2)
	{
		printf("������Ҫ��ѯ������: \n");
		scanf("%s", name);
		st = searchInfoByname(name, L);

		if (st == NULL)
		{
			printf("���޴��� !\n");
		}
		else
		{

			printf("_________________________________________________\n");
			printf("|���֤����\t|����\t|�Ա�\t|�ص�\t|ʱ��\t|�۷�\t|\n");
			printf("_________________________________________________\n");
			printf("%s|%s\t|%s\t|%s\t|%s\t|%d\t|\n", st->ID, st->name, st->sex, st->site, st->time, st->sum);
			printf("_________________________________________________\n");
		}
	}
	else if (choice != 2 && choice != 1)
	{
		printf("���ִ���\n�úÿ������ٳ������ץ����\n\n(?��-��? ?) ɵ�Ӱ�? ������");
	}
}

////////////////////////////////////////////////////////////////////////
void search1(node *L) //��ѯ����,ָ����һ���ڵ�
{
	readFile(L);
	int choice;
	char ID[50], name[50];
	node *st;
	printf("��ѡ���ѯΥ�¼�¼��ʽ:  \n");
	printf("�����֤���Ų�ѯ---1\n");
	printf("��������ѯ---------2\n");
	scanf("%d", &choice);
	if (choice == 1)
	{
		printf("������Ҫ��ѯ�����֤����: \n");
		scanf("%s", ID);
		st = searchInfoByID(ID, L);

		if (st == NULL)
		{
			printf("���޴��� !\n");
		}
		else
		{

			printf("_________________________________________________\n");
			printf("|���֤����\t|����\t|�Ա�\t|�ص�\t|ʱ��\t|�۷�\t|\n");
			printf("_________________________________________________\n");
			printf("%s|%s\t|%s\t|%s\t|%s\t|%d\t|\n", st->ID, st->name, st->sex, st->site, st->time, st->sum);
			printf("_________________________________________________\n");
		}
	}
	else if (choice == 2)
	{
		printf("������Ҫ��ѯ������: \n");
		scanf("%s", name);
		st = searchInfoByname(name, L);

		if (st == NULL)
		{
			printf("���޴��� !\n");
		}
		else
		{

			printf("_________________________________________________\n");
			printf("|���֤����\t|����\t|�Ա�\t|�ص�\t|ʱ��\t|�۷�\t|\n");
			printf("_________________________________________________\n");
			printf("%s|%s\t|%s\t|%s\t|%s\t|%d\t|\n", st->ID, st->name, st->sex, st->site, st->time, st->sum);
			printf("_________________________________________________\n");
		}
	}
	else if (choice != 2 && choice != 1)
	{
		printf("���ִ���\n�úÿ������ٳ������ץ����\n\n(?��-��? ?) ɵ�Ӱ�? ������");
	}
}

node *searchInfoByID1(char ID[50], node *L)
{
	node *p = L->next;
	node *n = L;
	while (p != NULL)
	{
		if (strcmp(p->ID, ID) == 0)
		{
			return n;
		}
		n = n->next;
		p = p->next;
	}
	return NULL;
}

node *searchInfoByname1(char name[50], node *L)
{
	node *p = L->next;
	node *n = L;
	while (p != NULL)
	{
		if (strcmp(name, p->name) == 0)
		{
			return n;
			break;
		}
		n = n->next;
		p = p->next;
	}
	return NULL;
}

/////////////////////////////////////////////////

// �޸�Υ�¼�¼
void fix(node *L)
{
	readFile(L);
	char ID[50];
	int choice;
	printf("������Ҫ��ѯ�ߵ����֤����: \n");
	scanf("%s", ID);
	node *st = searchInfoByID(ID, L);

	if (st == NULL)
	{
		printf("���޴���!\n");
		return;
	}

	//	st = st->next;

	while (1)
	{
		printf("_________________________________________________\n");
		printf("|���֤����\t|����\t|�Ա�\t|�ص�\t|ʱ��\t|�۷�\t|\n");
		printf("_________________________________________________\n");
		printf("%s|%s\t|%s\t|%s\t|%s\t|%d\t|\n", st->ID, st->name, st->sex, st->site, st->time, st->sum);
		printf("_________________________________________________\n");
		printf("�޸����֤����-----1\n");
		printf("�޸�����-----------2\n");
		printf("�޸��Ա�-----------3\n");
		printf("�޸�Υ�µص�-------4\n");
		printf("�޸�Υ��ʱ��-------5\n");
		printf("�޸�Υ�����۷���---6\n");
		printf("��Ҫ�뿪-----------0\n");
		printf("��ѡ����Ҫ�޸ĵ�����: \n(�����Ӧ����0~6)\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 0:
			printf("\n");
			break;
		case 1:
			printf("�������޸ĺ�����֤����:  \n");
			scanf("%s", st->ID);
			break;
		case 2:
			printf("�������޸ĺ������:  \n");
			scanf("%s", st->name);
			break;
		case 3:
			printf("�������޸ĺ���Ա�:  \n");
			scanf("%s", st->sex);
			break;
		case 4:
			printf("�������޸ĺ��Υ�µص�:  \n");
			scanf("%s", st->site);
			break;
		case 5:
			printf("�������޸ĺ��Υ��ʱ��:  \n");
			scanf("%s", st->time);
			break;
		case 6:
			printf("�������޸ĺ�Ŀ۷���:  \n");
			scanf("%d", st->sum);
			break;
		}
		printf("%s", st->site);
		// insertInfo(&List,*st);
		//	    saveFile(L);
		break;
	}
}

//ɾ��Υ�¼�¼
void eraseInFo(node *pr, node *st) // eraseInFo(st,L);
{
	pr->next = pr->next->next;
}

void erase(node *L)
{
	readFile(L);
	char ID[50];
	int choice;
	node *p;
	printf("��������Ҫɾ����Ϣ�ߵ����֤����: \n");
	scanf("%s", ID);
	node *st = searchInfoByID1(ID, L);
	p = st;

	if (st == NULL)
	{
		printf("���޴���!\n");

		return;
	}

	//	st = st->next;
	printf("_________________________________________________\n");
	printf("|���֤����\t|����\t|�Ա�\t|�ص�\t|ʱ��\t|�۷�\t|\n");
	printf("_________________________________________________\n");
	printf("%s|%s\t|%s\t|%s\t|%s\t|%d\t|\n", st->ID, st->name, st->sex, st->site, st->time, st->sum);
	printf("_________________________________________________\n");
	eraseInFo(st, L);
	//	st = p->next;
	printf("\nɾ���ɹ�!\n�뿪���ٰ�--0\n");
	scanf("%d", &choice);
	//		if(choice == 0)
	//		{
	//			system ("pause");
	//		}
	saveFile(st);
}

//����Υ�¼�¼
void print(node *L)
{
	readFile(L);
	node *p = L->next;
	printf("\n");
	printf("________________________________________________________\n");
	printf("|���֤����\t|����\t|�Ա�\t|�ص�\t|ʱ��\t|�۷�\t|\n");
	printf("________________________________________________________\n");
	if (p != NULL)
	{
		while (p != NULL)
		{
			printf("%s|%s|%s|%s|%s|%d\n", p->ID, p->name, p->sex, p->site, p->time, p->sum);
			printf("________________________________________________________\n");
			p = p->next;
		}
	}
}

//Ŀ¼��ת
void keyDown()
{
	int userkey = 0;
	scanf("%d", &userkey);
	switch (userkey)
	{
	case 1:
		printf("---[¼��Υ�¼�¼]---\n");
		printf("\n");
		add();
		break;
	case 2:
		printf("---[�޸�Υ�¼�¼]---\n");
		fix(&List);
		printf("\n");
		break;
	case 3:
		printf("---[ɾ��Υ�¼�¼]---\n");
		erase(&List);
		printf("\n");
		break;
	case 4:
		printf("---[��ѯΥ�¼�¼]---\n");
		search(&List);
		printf("\n");

		break;
	case 5:
		printf("---[����Υ�¼�¼]---\n");
		printf("\n");
		print(&List);
		break;
	case 0:
		printf("---[�˳�]---\n");
		printf("\n");
		exit(0); //ֱ���˳�ģ�鱾����
		break;
	default:
		printf("���ִ���\n�úÿ������ٳ������ץ����\n\n(?��-��? ?) ɵ�Ӱ�? ������\n");
		printf("\n");
		break;
	}
}
int main()
{
	int choice = 0;
	// scanf ("%d",&choice);

	// code();
	while (1)
	{
		makeMenu();
		keyDown();
		// getchar();//�����������
		system("pause"); //�����������
	}
	readFile(&List);
	return 0;
}
