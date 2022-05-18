#include"head.h"

void stu_increase(Node *head, int cla)
{
	Node *stu;
	char ch;
	int i;
	int key = 1;
	
	stu = (Node*)malloc(sizeof(Node));

	while (1)
	{
		system("cls");
		printf("======================================\n");
		printf("--------------------------------------\n");
		printf("\n����ѧ����Ϣ\n\n");
		printf("(����exit����)\n");
		printf("������ѧ��������");
		for (i = 0; i < 12; i++)
		{
			scanf("%c", &ch);
			if (ch == '\n')
			{
				break;
			}
			stu->name[i] = ch;
		}
		rewind(stdin);
		stu->name[i] = '\0';

		if (strcmp(stu->name, "exit") == 0)
		{
			key = 0;
			break;
		}

		if (i == 12)
		{
			system("cls");
			printf("���ֹ��������������룡");
			system("pause");
			key = 0;
		}
		else if (strlen(stu->name) == 0)
		{
			system("cls");
			printf("���ֲ���ȷ�����������룡");
			system("pause");
			key = 0;
		}
		else if (judg_Chinese(stu->name) == 0)
		{
			system("cls");
			printf("���ֲ���ȷ�����������룡");
			system("pause");
			key = 0;
		}
		else
		{
			key = 1;
			break;
		}
	}
	if (key)
	{
		while (1)
		{
			system("cls");
			printf("======================================\n");
			printf("--------------------------------------\n");
			printf("\n����ѧ����Ϣ\n\n");
			printf("(����exit����)\n");
			printf("������ѧ��������%s\n", stu->name);
			printf("������ѧ�ţ����5λ����");

			for (i = 0; i < 5; i++)
			{
				scanf("%c", &ch);
				if (ch == '\n')
				{
					break;
				}
				stu->num[i] = ch;
			}
			rewind(stdin);
			stu->num[i] = '\0';

			if (strcmp(stu->num, "exit") == 0)
			{
				key = 0;
				break;
			}
			ch = (char)(cla + '0');
			if (i != 5 || stu->num[0] != '0' || stu->num[1] != ch)
			{
				system("cls");
				printf("ѧ�Ų���ȷ�����������룡");
				system("pause");
				key = 0;
			}
			else if (judg_repeat_stu(head, stu->num))
			{
				system("cls");
				printf("ѧ���ظ������������룡");
				system("pause");
				key = 0;
			}
			else if (judg_Chinese(stu->num) == 1)
			{
				system("cls");
				printf("�����Ժ�����ѧ�ţ�\n");
				system("pause");
			}
			else
			{
				key = 1;
				break;
			}
		}
	}
	if (key)
	{
		while (1)
		{
			system("cls");
			printf("======================================\n");
			printf("--------------------------------------\n");
			printf("\n����ѧ����Ϣ\n\n");
			printf("(����-1����)\n");
			printf("������ѧ��������%s\n", stu->name);
			printf("������ѧ�ţ����5λ����%s\n", stu->num);
			printf("���������ĳɼ�:");

			stu->Chinese_grades = read();
			rewind(stdin);
			if (stu->Chinese_grades == -1)
			{
				key = 0;
				break;
			}
			if (stu->Chinese_grades >= 0 && stu->Chinese_grades <= 100)
			{
				key = 1;
				break;
			}
			else
			{
				key = 0;
				system("cls");
				printf("�ɼ�����ȷ�����������룡");
				system("pause");
			}
		}
	}
	if (key)
	{
		while (1)
		{
			system("cls");
			printf("======================================\n");
			printf("--------------------------------------\n");
			printf("\n����ѧ����Ϣ\n\n");
			printf("(����-1����)\n");
			printf("������ѧ��������%s\n", stu->name);
			printf("������ѧ�ţ����5λ����%s\n", stu->num);
			printf("���������ĳɼ�:%d\n", stu->Chinese_grades);
			printf("��������ѧ�ɼ�:");

			stu->Math_grades = read();
			rewind(stdin);
			if (stu->Math_grades == -1)
			{
				key = 0;
				break;
			}
			if (stu->Math_grades >= 0 && stu->Math_grades <= 100)
			{
				key = 1;
				break;
			}
			else
			{
				key = 0;
				system("cls");
				printf("�ɼ�����ȷ�����������룡");
				system("pause");
			}
		}
	}
	if (key)
	{
		while (1)
		{
			system("cls");
			printf("======================================\n");
			printf("--------------------------------------\n");
			printf("\n����ѧ����Ϣ\n\n");
			printf("(����-1����)\n");
			printf("������ѧ��������%s\n", stu->name);
			printf("������ѧ�ţ����5λ����%s\n", stu->num);
			printf("���������ĳɼ�:%d\n", stu->Chinese_grades);
			printf("��������ѧ�ɼ�:%d\n", stu->Math_grades);
			printf("������Ӣ��ɼ�:");

			stu->English_grades = read();
			rewind(stdin);
			if (stu->English_grades == -1)
			{
				key = 0;
				break;
			}
			if (stu->English_grades >= 0 && stu->English_grades <= 100)
			{
				key = 1;
				break;
			}
			else
			{
				key = 0;
				system("cls");
				printf("�ɼ�����ȷ�����������룡");
				system("pause");
			}
		}
	}

	if (key)
	{
		if (head->next != NULL)
		{
			switch (cla)
			{
			case 1:
			{
				strcpy(stu->classname, "����1��");
				break;
			}
			case 2:
			{
				strcpy(stu->classname, "����2��");
				break;
			}
			case 3:
			{
				strcpy(stu->classname, "����3��");
				break;
			}
			case 4:
			{
				strcpy(stu->classname, "����4��");
				break;
			}
			case 5:
			{
				strcpy(stu->classname, "����5��");
				break;
			}
			default:
			{
				system("cls");
				printf("�������г���ֹͣ����");
				system("pause");
				exit(1);
			}
			}
			strcpy(stu->password, "123456");
		}

		stu->next = head->next;
		head->next = stu;

		Link_save(head, cla);


		printf("���ӳɹ���");
		system("pause");
	}
}


Node *stu_allfind(Node *head)
{
	char name[20];
	Node *stu;
	int i;
	char ch;

	while (1)
	{
		system("cls");
		printf("======================================\n");
		printf("--------------------------------------\n");
		printf("(����exit����)\n");
		printf("������ѧ������/ѧ�ţ�");
		for (i = 0; i < 12; i++)
		{
			scanf("%c", &ch);
			if (ch == '\n')
			{
				break;
			}
			name[i] = ch;
		}
		rewind(stdin);
		name[i] = '\0';

		if (strcmp(name, "exit") == 0)
		{
			return NULL;
			break;
		}

		if (i == 12)
		{
			system("cls");
			printf("����/ѧ�Ź��������������룡");
			system("pause");

		}
		else
		{
			stu = Find_name(head, name);
			if (stu == NULL)
			{
				stu = Find_num(head, name);

				if (stu == NULL)
				{
					system("cls");
					printf("δѰ�ҵ���ѧ���������²�����\n");
					system("pause");
				}
				else
				{
					return stu;
					break;
				}
			}
			else
			{
				return stu;
				break;
			}
		}
	}
}

void stu_del(Node *head, int cla)
{
	Node *stu;
	Node *r, *s;

	while (1)
	{
		stu = stu_allfind(head);
		if (stu != NULL)
		{
			s = head;
			for (r = head->next; strcmp(stu->num, r->num) != 0 && r->next != NULL; r = r->next)
			{
				s = s->next;
			}
			s->next = r->next;
			free(r);

			Link_save(head, cla);
			system("cls");
			printf("ɾ����ɣ�");
			system("pause");
			break;
		}
	}
}

//ѧ����Ϣ�޸�
void stu_revise(Node *head, int cla)
{
	Node *stu;
	char choice[1000];
	char ch;
	char num[13];
	char name[13];
	int grades;
	int i;

	stu = stu_allfind(head);
	if (stu != NULL)
	{
		system("cls");
		while (1)
		{
			choice[0] = '\0';
			system("cls");
			tea_oper_revise(stu);

			scanf("%s", choice);
			rewind(stdin);
			if (strlen(choice) > 1)
			{
				printf("������ѡ��");
				system("pause");
			}
			else if (choice[0] == '0')
			{
				break;
			}
			else
			{
				switch (choice[0])
				{
				case '1':
				{
					while (1)
					{
						printf("\n���루exit������\n");
						printf("������ѧ��������");
						for (i = 0; i < 12; i++)
						{
							scanf("%c", &ch);
							if (ch == '\n')
							{
								break;
							}
							name[i] = ch;
						}
						rewind(stdin);
						name[i] = '\0';

						if (strcmp(name, "exit") == 0)
						{
							break;
						}

						else if (i == 12)
						{
							printf("���ֹ��������������룡\n");

						}
						else if (judg_Chinese(name) == 0)
						{
							printf("���ֲ���ȷ�����������룡\n");
						}
						else
						{
							strcpy(stu->name, name);
							Link_save(head, cla);
							printf("�����޸ĳɹ���\n");
							break;
						}
					}
					break;
				}
				case '2':
				{
					while (1)
					{
						printf("\n���루exit������\n");
						printf("������ѧ����(�����λ)��");
						for (i = 0; i < 5; i++)
						{
							scanf("%c", &ch);
							if (ch == '\n')
							{
								break;
							}
							num[i] = ch;
						}
						rewind(stdin);
						num[i] = '\0';

						if (strcmp(num, "exit") == 0)
						{
							break;
						}
						ch = (char)(cla + '0');
						if (i != 5)
						{
							printf("ѧ�Ų���ȷ�����������룡\n");
						}
						else if (num[0] != '0' || num[1] != ch)
						{
							printf("ѧ�Ų���ȷ�����������룡\n");
						}
						else if (judg_repeat_stu(head, num))
						{
							printf("ѧ���ظ���\n");
						}
						else
						{
							strcpy(stu->num, num);
							Link_save(head, cla);
							printf("ѧ���޸ĳɹ���\n");
							break;
						}
					}
					break;
				}
				case '3':
				{
					while (1)
					{
						printf("(����-1����)\n");
						printf("���������ĳɼ�:");

						grades = read();
						rewind(stdin);
						if (grades == -1)
						{
							break;
						}
						if (grades >= 0 && grades <= 100)
						{
							stu->Chinese_grades = grades;
							Link_save(head, cla);
							printf("�����޸ĳɹ���\n");
							break;
						}
						else
						{
							printf("�ɼ�����ȷ�����������룡");
						}
					}
					break;
				}
				case '4':
				{
					while (1)
					{
						printf("(����-1����)\n");
						printf("��������ѧ�ɼ�:");

						grades = read();
						rewind(stdin);
						if (grades == -1)
						{
							break;
						}
						if (grades >= 0 && grades <= 100)
						{
							stu->Math_grades = grades;
							Link_save(head, cla);
							printf("��ѧ�޸ĳɹ���\n");
							break;
						}
						else
						{
							printf("�ɼ�����ȷ�����������룡");
						}
					}
					break;
				}
				case '5':
				{
					while (1)
					{
						printf("������Ӣ��ɼ�:");
						grades = read();
						rewind(stdin);
						if (grades == -1)
						{
							break;
						}
						if (grades >= 0 && grades <= 100)
						{
							stu->English_grades = grades;
							Link_save(head, cla);
							printf("Ӣ���޸ĳɹ���\n");
							break;
						}
						else
						{
							printf("�ɼ�����ȷ�����������룡");
						}
					}
					break;
				}
				default:
				{
					printf("������ѡ��\n");
					break;
				}
				}
			}
		}
	}
}

void tea_save_loc(Node *head)
{
	FILE *fp;
	Node *r;
	char filename[500];
	char ch;
	int i;

	while (1)
	{
		system("cls");
		printf("==============================================================\n");
		printf("--------------------------------------------------------------\n");
		printf("(����exit ����)\n");
		printf("�������ļ�·����");

		for (i = 0; i < 499; i++)
		{
			scanf("%c", &ch);
			if (ch == '\n')
			{
				break;
			}
			filename[i] = ch;
		}
		filename[i] = '\0';
		rewind(stdin);

		//��������
		if (strcmp(filename, "exit") == 0)
		{
			break;
		}

		fp = fopen(filename, "wt");
		if (fp == NULL)
		{
			system("cls");
			printf("�ļ���ʧ�ܣ�");
			system("pause");
		}

		else
		{
			for (r = head->next; r != NULL && r->next != NULL; r = r->next)
			{
				fprintf(fp, "%s %s %s %d %d %d %s\n", r->name, r->num, r->classname, r->Chinese_grades, r->Math_grades, r->English_grades, r->password);
			}
			fclose(fp);
			system("cls");
			printf("���سɹ�");
			system("pause");
			break;
		}
	}
}

void tea_grades_anlayse(Node *head)
{
	float CH = 0;
	float MA = 0;
	float EN = 0;
	char choice[200];
	int count = 0;
	Node *r;

	for (r = head->next; r != NULL && r->next != NULL; r = r->next)
	{
		CH += r->Chinese_grades;
		MA += r->Math_grades;
		EN += r->English_grades;
		count++;
	}

	CH /= count;
	MA /= count;
	EN /= count;
	while (1)
	{
		choice[0] = '\0';
		system("cls");
		printf("=================================\n");
		printf("---------------------------------\n");
		printf("�ɼ�������\n");
		printf("����ƽ���֣�%.2f\n", CH);
		printf("��ѧƽ���֣�%.2f\n", MA);
		printf("Ӣ��ƽ���֣�%.2f\n", EN);
		printf("---------------------------------\n");
		printf("�Ƿ��ѧ���ɼ����������\n");
		printf("1. ����    2. ����    0.����\n");

		scanf("%s", choice);
		rewind(stdin);
		if (strlen(choice) > 1)
		{
			system("cls");
			printf("�����²�����");
			system("pause");
		}
		else if (choice[0] == '0')
		{
			break;
		}

		else if (choice[0] == '1')
		{
			stu_sort_up(head);
			print_class_grades(head);
			system("pause");
		}
		else if (choice[0] == '2')
		{
			stu_sort_down(head);
			print_class_grades(head);
			system("pause");
		}
		else
		{
			system("cls");
			printf("�����²�����");
			system("pause");
		}
	}
}