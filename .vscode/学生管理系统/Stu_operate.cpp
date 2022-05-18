#include"head.h"

void stu_login()
{
	Node *head = NULL;
	char choice1[3], choice2[3];
	int cla;
	char ch;
	int i;
	int key = 0;
	
	while (1)
	{
		choice1[0] = '\0';
		if (WD == 1)
		{
			WD = 0;
			break;
		}

		system("cls");
		Face_class();
		for (i = 0; i < 3; i++)
		{
			scanf("%c", &ch);
			if (ch == '\n')
			{
				break;
			}
			choice1[i] = ch;
		}
		rewind(stdin);

		if (i > 1)
		{
			system("cls");
			printf("ѡ��ʧ��,");
			system("pause");
		}
		else
		{
			if (choice1[0] == '0')
			{
				break;
			}
			head = Find_class(choice1[0]);

			if (head != NULL)
			{
				key = 1;
			}

			if (key == 1)
			{
				while (1)
				{
					choice2[0] = '\0';
					system("cls");
					stu_face();
					for (i = 0; i < 3; i++)
					{
						scanf("%c", &ch);
						if (ch == '\n')
						{
							break;
						}
						choice2[i] = ch;
					}
					rewind(stdin);

					if (i > 1)
					{
						system("cls");
						printf("ѡ��ʧ��,");
						system("pause");
					}

					else
					{
						if (choice2[0] == '0')
						{
							Link_destroy(head);
							head = NULL;
							WD = 1;
							break;
						}
						else if (choice2[0] == '1')
						{
							cla = (int)(choice1[0] - '0');
							stu_inlog(head, cla);
						}
						else if (choice2[0] == '2')
						{
							stu_pass_back(head);
						}
						else
						{
							system("cls");
							printf("ѡ��ʧ��,");
							system("pause");
						}
					}
				}
				key = 0;
			}
		}
	}
}

void stu_operate(Node *head, Node *stu, int cla)
{
	char choice[1000];
	while (1)
	{
		choice[0] = '\0';
		system("cls");
		stu_operate_face();
		scanf("%s", choice);
		rewind(stdin);
		if (strlen(choice) > 1)
		{
			system("cls");
			printf("������󣬰��������������");
			system("pause");
		}
		else
		{
			if (choice[0] == '0')
			{
				break;
			}

			switch (choice[0])
			{
			case '1':
			{
				system("cls");
				printf("%s�ĳɼ����£�", stu->name);
				printf("���ģ�%d    ��ѧ��%d    Ӣ�%d\n", stu->Chinese_grades, stu->Math_grades, stu->English_grades);
				system("pause");
				break;
			}
			case '2':
			{
				system("cls");
				stu_sort_up(head);
				print_class_grades(head);
				printf("\n");
				system("pause");
				break;
			}
			case '3':
			{
				stu_analyse(stu, head);
				break;
			}
			case '4':
			{
				stu_complaint(stu, cla);
				break;
			}
			case '5':
			{
				stu_pass_change(head, stu, cla);
				break;
			}
			case '6':
			{
				Link_destroy(head);
				system("cls");
				printf("���˳�\n");
				exit(0);
			}
			default:
			{
				system("cls");
				printf("������󣬰��������������");
				system("pause");
			}
			}
		}
	}
}



void stu_inlog(Node *head, int cla)
{
	Node *stu;
	char ch = '0', num[6];
	char password[200];
	int i;
	while (1)
	{
		//����ѧ�ź�����
		system("cls");
		printf("======================================\n");
		printf("--------------------------------------\n");
		printf("         ������ѧ�ź�����             \n");
		printf("          (����exit�˳�)\n");
		printf("\n         ѧ�ţ�");
		rewind(stdin);
		for (i = 0; i < 5; i++)       //ѭ��¼��ѧ�ţ���ֹ����Խ��
		{
			scanf("%c", &ch);
			if (ch == '\n')           //��⵽���з��˳�
			{
				break;
			}
			num[i] = ch;
		}
		rewind(stdin);
		num[i] = '\0';

		if (strcmp(num, "exit") == 0)      //���������˳�ѧ������
		{
			break;
		}

		printf("\n         �������룺");
		rewind(stdin);
		for (i = 0; i < 200; i++)       //ѭ��¼��ѧ�ţ���ֹ����Խ��
		{
			ch = _getch();

			if (ch == '\n' || ch == '\r')           //��⵽���з��˳�
			{
				break;
			}
			if (ch == '\b')
			{
				if (i == 0)
				{
					i = i - 1;
					continue;
				}
				else
				{
					i = i - 1;
					password[i] = '\0';
					i = i - 1;
					printf("\b");
					printf(" ");
					printf("\b");
				}
			}
			else
			{
				password[i] = ch;
				printf("*");
			}
		}
		rewind(stdin);
		password[i] = '\0';

		if (strcmp(password, "exit") == 0)      //���������˳�ѧ�ŵ�¼
		{
			break;
		}
		//����ѧ��
		stu = Find_num(head, num);

		if (stu == NULL)
		{
			system("cls");
			printf("ѧ�Ŵ��󣬰��������������\n");
			system("pause");
		}

		else if (strcmp(password, stu->password) == 0)
		{
			system("cls");
			printf("��¼�ɹ������������������!\n");
			system("pause");

			//��¼�ɹ��� �������

			stu_operate(head, stu, cla);
			break;
		}

		else
		{
			system("cls");
			printf("������󣬰�������������룡\n");
			system("pause");
		}
	}
}

void stu_analyse(Node *stu, Node *head)
{
	char ch1[10], ch2[10], ch3[10];
	int i = 1;
	Node *r;
	if (stu->Chinese_grades >= 80)
	{
		strcpy(ch1, "����");
	}
	else if (stu->Chinese_grades >= 60 && stu->Chinese_grades < 80)
	{
		strcpy(ch1, "����");
	}
	else
	{
		strcpy(ch1, "���ֹ�");
	}
	if (stu->Math_grades >= 80)
	{
		strcpy(ch2, "����");
	}
	else if (stu->Math_grades >= 60 && stu->Math_grades < 80)
	{
		strcpy(ch2, "����");
	}
	else
	{
		strcpy(ch2, "���ֹ�");
	}
	if (stu->English_grades >= 80)
	{
		strcpy(ch3, "����");
	}
	else if (stu->English_grades >= 60 && stu->English_grades < 80)
	{
		strcpy(ch3, "����");
	}
	else
	{
		strcpy(ch3, "���ֹ�");
	}
	system("cls");
	printf("======================================\n");
	printf("--------------------------------------\n");
	printf("���ĳɼ��������£�\n");
	stu_sort_up(head);
	for (r = head->next; r != NULL && r->next != NULL; r = r->next)
	{
		if (strcmp(r->num, stu->num) == 0)
		{
			break;
		}
		i++;
	}
	printf("\n���İ༶����Ϊ%d\n", i);
	printf("\n�������ķ���%d     %s\n", stu->Chinese_grades, ch1);
	printf("\n������ѧ����%d     %s\n", stu->Math_grades, ch2);
	printf("\n����Ӣ�����%d     %s\n", stu->English_grades, ch1);
	printf("\n");
	system("pause");
}

void stu_pass_back(Node *head)
{
	Node *stu;
	char ch = '0', num[6];
	char exit[] = "exit";
	char password[13];
	int i;
	while (1)
	{
		//����ѧ�ź�����
		system("cls");
		printf("======================================\n");
		printf("--------------------------------------\n");
		printf("            ������ѧ��                \n");
		printf("          (����exit�˳�)\n");
		printf("\n         ѧ�ţ�");
		rewind(stdin);
		for (i = 0; i < 5; i++)       //ѭ��¼��ѧ�ţ���ֹ����Խ��
		{
			scanf("%c", &ch);
			if (ch == '\n')           //��⵽���з��˳�
			{
				break;
			}
			num[i] = ch;
		}
		rewind(stdin);
		num[i] = '\0';

		if (strcmp(num, exit) == 0)      //���������˳�ѧ������
		{
			break;
		}

		printf("\n         ������֤�루12345����");
		rewind(stdin);
		for (i = 0; i < 12; i++)       //ѭ��¼��ѧ�ţ���ֹ����Խ��
		{
			scanf("%c", &ch);
			if (ch == '\n')           //��⵽���з��˳�
			{
				break;
			}
			password[i] = ch;
		}
		rewind(stdin);
		password[i] = '\0';

		if (strcmp(password, exit) == 0)      //���������˳�ѧ�ŵ�¼
		{
			break;
		}
		//����ѧ��
		stu = Find_num(head, num);

		if (stu == NULL)
		{
			system("cls");
			printf("ѧ�Ŵ��󣬰��������������\n");
			system("pause");
		}

		else
		{
			system("cls");
			printf("����������: %s\n", stu->password);
			system("pause");
			break;
		}
	}
}

//ѧ�������޸�
void stu_pass_change(Node *head, Node *stu, int cla)
{
	char password1[200];
	char password2[200];
	char ch;
	int i;
	char exit0[] = "exit";

	while (1)
	{
		system("cls");
		printf("(exit�˳�)");
		printf("������������(���11λ����");
		rewind(stdin);
		for (i = 0; i < 200; i++)       
		{
			ch = _getch();
			if (ch == '\n' || ch == '\r')          
			{
				break;
			}
			if (ch == '\b')
			{
				if (i == 0)
				{
					i = i - 1;
					continue;
				}
				else
				{
					i = i - 1;
					password1[i] = '\0';
					i = i - 1;
					printf("\b");
					printf(" ");
					printf("\b");
				}
			}
			else
			{
				password1[i] = ch;
				printf("*");
			}
		}
		rewind(stdin);
		password1[i] = '\0';

		if (strcmp(password1, exit0) == 0)      //���������˳�ѧ�ŵ�¼
		{
			break;
		}
		//��������
		if (i >= 12)
		{
			system("cls");
			printf("���������\n");
			system("pause");
		}
		else if (judg_Chinese(password1) == 1)
		{
			system("cls");
			printf("�����Ժ��������룡\n");
			system("pause");
		}
		else
		{
			printf("\n���ٴ�����������(���11λ����");
			rewind(stdin);
			for (i = 0; i < 200; i++)       //ѭ��¼��ѧ�ţ���ֹ����Խ��
			{
				ch = _getch();
				if (ch == '\n' || ch == '\r')           //��⵽���з��˳�
				{
					break;
				}
				if (ch == '\b')
				{
					if (i == 0)
					{
						i = i - 1;
						continue;
					}
					else
					{
						i = i - 1;
						password2[i] = '\0';
						i = i - 1;
						printf("\b");
						printf(" ");
						printf("\b");
					}
				}
				else
				{
					password2[i] = ch;
					printf("*");
				}
			}
			rewind(stdin);
			password2[i] = '\0';

			if (strcmp(password2, exit0) == 0)      //���������˳�ѧ�ŵ�¼
			{
				break;
			}
			//��������
			if (i >= 12)
			{
				system("cls");
				printf("���������\n");
				system("pause");
			}
			else if (strcmp(password1, password2) != 0)
			{
				system("cls");
				printf("�������벻һ�£�\n");
				system("pause");
			}
			else
			{
				strcpy(stu->password, password1);
				Link_save(head, cla);
				system("cls");
				printf("�����޸ĳɹ���\n");
				system("pause");
				break;
			}
		}
	}
}

//�ɼ�����
void stu_complaint(Node *stu, int cla)
{
	char choice[1000];
	int grades;
	int len;
	Comp *stuNew;
	Comp *head;
	Comp *r;

	while (1)
	{
		choice[0] = '\0';
		system("cls");
		printf("==========================\n");
		printf("--------------------------\n");
		printf("��ѡ����Ҫ���ߵĿ�Ŀ");
		printf("1.����  2.Ӣ��  3.��ѧ  0.����\n");
		rewind(stdin);
		scanf("%s", choice);
		rewind(stdin);
		len = strlen(choice);
		if (len > 1)
		{
			system("cls");
			printf("����������\n");
			system("pause");
			break;
		}
		if (choice[0] == '0')
		{
			break;
		}
		switch (choice[0])
		{
		    case '1':
			{
				while (1)
				{
					head = stu_Compcreate();
					r = head->next;

					system("cls");
					printf("(����-1����)\n");
					printf("����������³ɼ���\n");
					grades = read();


					if (grades == -1)
					{
						break;
					}

					else if (grades >= 0 && grades <= 100)
					{
						stuNew = (Comp*)malloc(sizeof(Comp));

						stuNew->newGrades = grades;
						stuNew->oidGrades = stu->Chinese_grades;
						stuNew->cla = cla;
						strcpy(stuNew->name, stu->name);
						strcpy(stuNew->num, stu->num);
						strcpy(stuNew->course, "Chinese");

						stuNew->next = r;
						head->next = stuNew;

						stuComp_save(head);

						Link_comp_destroy(head);
						system("cls");
						printf("���߳ɼ��ɹ�\n");
						system("pause");
						break;
					}
					else
					{
						system("cls");
						printf("����������ɼ�\n");
						system("pause");
					}
				}
				break;
			}
			case '2':
			{
				while (1)
				{
					head = stu_Compcreate();
					r = head->next;

					system("cls");
					printf("(����-1����)\n");
					printf("����������³ɼ���\n");
					grades = read();
					rewind(stdin);

					if (grades == -1)
					{
						break;
					}

					if (grades >= 0 && grades <= 100)
					{
						stuNew = (Comp*)malloc(sizeof(Comp));

						stuNew->newGrades = grades;
						strcpy(stuNew->course, "Math");
						stuNew->oidGrades = stu->Math_grades;
						stuNew->cla = cla;
						strcpy(stuNew->name, stu->name);
						strcpy(stuNew->num, stu->num);

						stuNew->next = r;
						head->next = stuNew;

						stuComp_save(head);
						Link_comp_destroy(head);
						system("cls");
						printf("���߳ɼ��ɹ�\n");
						system("pause");
						break;
					}
					else
					{
						system("cls");
						printf("����������ɼ�\n");
						system("pause");
					}
				}
				break;
			}
			case '3':
			{
				while (1)
				{
					head = stu_Compcreate();
					r = head->next;

					system("cls");
					printf("(����-1����)\n");
					printf("����������³ɼ���\n");
					grades = read();
					rewind(stdin);

					if (grades == -1)
					{
						break;
					}

					if (grades >= 0 && grades <= 100)
					{
						stuNew = (Comp*)malloc(sizeof(Comp));

						stuNew->newGrades = grades;
						strcpy(stuNew->course, "English");
						stuNew->oidGrades = stu->English_grades;
						stuNew->cla = cla;
						strcpy(stuNew->name, stu->name);
						strcpy(stuNew->num, stu->num);

						stuNew->next = r;
						head->next = stuNew;

						stuComp_save(head);
						Link_comp_destroy(head);
						system("cls");
						printf("���߳ɼ��ɹ�\n");
						system("pause");
						break;
					}
					else
					{
						system("cls");
						printf("����������ɼ�\n");
						system("pause");
					}
				}
				break;
			}
			default:
			{
				system("cls");
				printf("����������\n");
				system("pause");
			}
		}
	}
}