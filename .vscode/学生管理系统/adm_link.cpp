#include"head.h"

void tea_password_change(Teanode *head, Teanode *tea)
{
	char password1[200];
	char password2[200];
	char ch;
	int i;

	while (1)
	{
		system("cls");
		printf("===========================\n");
		printf("---------------------------\n");
		printf("������exit���أ�\n");
		printf("�����������룺(���11λ��");
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

		if (strcmp(password1, "exit") == 0)      //���������˳�
		{
			break;
		}

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

			if (strcmp(password2, "exit") == 0)      
			{
				break;
			}
			
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
				strcpy(tea->password, password1);
				tea_acc_save(head);
				system("cls");
				printf("�����޸ĳɹ���\n");
				system("pause");
				break;
			}
		}
	}
}


void tea_passback(Teanode *head)
{
	char num[13];
	char n[13];
	char ch;
	int i;
	Teanode *tea;

	while (1)
	{
		system("cls");
		printf("===========================\n");
		printf("---------------------------\n");
		printf("������exit���أ�\n");
		printf("�������˺ţ�");
		//ѭ�������˺�
		rewind(stdin);
		for (i = 0; i < 12; i++)
		{
			scanf("%c", &ch);
			if (ch == '\n')
			{
				break;
			}
			num[i] = ch;
		}
		num[i] = '\0';
		rewind(stdin);
		//����exit����
		if (strcmp(num, "exit") == 0)
		{
			break;
		}
		//�����˺ų���
		if (i == 12)
		{
			system("cls");
			printf("�˻����������������룡");
			system("pause");
		}

		else
		{
			printf("��������֤�루12345��:");
			rewind(stdin);
			for (i = 0; i < 12; i++)
			{
				scanf("%c", &ch);
				if (ch == '\n')
				{
					break;
				}
				n[i] = ch;
			}
			n[i] = '\0';
			rewind(stdin);
			//����exit����
			if (strcmp(n, "exit") == 0)
			{
				break;
			}
			if (strcmp(n, "12345") != 0)
			{
				system("cls");
				printf("��֤��������������룡");
				system("pause");
			}
			else
			{
				tea = tea_allfind(head, num);
				if (tea == NULL)
				{
					system("cls");
					printf("�˻��������������룡");
					system("pause");
				}
				else
				{
					system("cls");
					printf("====================================\n");
					printf("------------------------------------\n");
					printf("%s��ԭ����Ϊ��%s\n", tea->num, tea->password);
					system("pause");
					break;
				}
			}
		}
	}
}

Teanode *tea_allfind(Teanode *head, char n[13])
{
	Teanode *tea;

	tea = Find_tea(head, n);
	if (tea == NULL)
	{
		tea = Find_tea_name(head, n);
	}

	return tea;
}

//���ѹ���Ա���³ɼ���
void adm_rewind()
{
	Teanode *rhead;
	Teanode *p;
	int i = 0;
	int k = 1;
	char choice[200];

	rhead = tea_Remind();
	p = rhead->next;
	//�鿴��ʦ��������
	for (; p != NULL && p->next != NULL; p = p->next)
	{
		i++;
	}
	if (i == 0)
	{
		return;
	}
	else
	{
		while (k)
		{
			system("cls");
			printf("======================================\n");
			printf("--------------------------------------\n");
			printf("%d����ʦ���������³ɼ���\n", i);
			printf("�Ƿ�鿴���飨Y/N��\n");
			scanf("%s", &choice);
			rewind(stdin);
			if (strlen(choice) > 1)
			{
				system("cls");
				printf("�����²���\n");
				system("pause");
			}
			//��ӡ���ѽ�ʦ����
			else if (choice[0] == 'Y' || choice[0] == 'y')
			{
				while (1)
				{
					system("cls");
					printf("======================================\n");
					printf("--------------------------------------\n");
					for (p = rhead->next; p != NULL && p->next != NULL; p = p->next)
					{
						printf("%s %s\n", p->name, p->cla);
					}
					printf("\n�Ƿ�ɾ�����飨Y/N��\n");

					scanf("%s", &choice);
					rewind(stdin);
					if (strlen(choice) > 1)
					{
						system("cls");
						printf("�����²���\n");
						system("pause");
					}
					else if (choice[0] == 'Y' || choice[0] == 'y')
					{
						//���ý�ʦ����������
						Link_tea_destroy(rhead);
						rhead = (Teanode*)malloc(sizeof(Teanode));
						rhead->next = NULL;
						tea_remind_save(rhead);
						free(rhead);
						k = 0;
						printf("ɾ���ɹ���\n");
						system("pause");
						break;
					}
					else if (choice[0] == 'N' || choice[0] == 'n')
					{
						k = 0;
						break;
					}
				}
			}
			else if (choice[0] == 'N' || choice[0] == 'n')
			{
				break;
			}
			else
			{
				system("cls");
				printf("�����²���\n");
				system("pause");
			}
		}
	}
}

//����Ա����ɼ�����
void adm_GradesComp()
{
	Comp *chead;
	Node *shead;
	Node *stu;
	Comp *p;
	Comp *q;
	char cla;
	char choice[200];

	chead = stu_Compcreate();

	//û������
	if (chead->next->next == NULL)
	{
		system("cls");
		printf("û������\n");
		system("pause");
	}
	//������
	else
	{
		while (1)
		{
			if (chead->next->next == NULL)
			{
				system("cls");
				printf("û������\n");
				system("pause");
				break;
			}
			//�������ͬѧ��Ϣ
			system("cls");
			printf("=========================================================\n");
			printf("---------------------------------------------------------\n");
			printf("����     ѧ��   �༶   ��Ŀ   ԭ�ɼ�    ���߳ɼ�\n");
			for (q = chead->next; q != NULL && q->next != NULL; q = q->next)
			{
				printf("%s   %s   %d��  %s   %d         %d\n", q->name, q->num, q->cla, q->course, q->oidGrades, q->newGrades);
			}
			while (1)
			{
				choice[0] = '\0';
				printf("\n�Ƿ�ͬ����λͬѧ����������Y/N��\n");
				printf("(����0����)");
				scanf("%s", choice);
				rewind(stdin);
				if (strlen(choice) > 1)
				{
					system("cls");
					printf("�����²���\n");
					system("pause");
				}
				else if (choice[0] == '0')
				{
					Link_comp_destroy(chead);
					return;
				}
				else if (choice[0] == 'Y' || choice[0] == 'y')
				{
					p = chead->next;
					//���Ҹ�ѧ��
					cla = (char)(p->cla + '0');
					shead = Find_class(cla);
					stu = Find_num(shead, p->num);
					//���³ɼ�
					switch (p->course[0])
					{
					    case 'C':
						{
							stu->Chinese_grades = p->newGrades;
							break;
						}
						case 'M':
						{
							stu->Math_grades = p->newGrades;
							break;
						}
						case 'E':
						{
							stu->English_grades = p->newGrades;
							break;
						}
						default:
						{
							system("cls");
							printf("�������г���������������\n");
							exit(0);
						}
					}
					//����
					Link_save(shead, p->cla);
					//�ͷ��ڴ�
					Link_destroy(shead);
					chead->next = p->next;
					free(p);
					stuComp_save(chead);
					break;
				}
				else if (choice[0] == 'N' || choice[0] == 'n')
				{
					p = chead->next;
					chead->next = p->next;
					free(p);
					stuComp_save(chead);
					system("cls");
					printf("�����ɹ�\n");
					system("pause");
					break;
				}
				else
				{
					system("cls");
					printf("�����²���\n");
					system("pause");
				}
			}
		}
	}
}

void admUp_grades()
{
	FILE *fp;
	Node *shead;
	char filename[500];
	char ch;
	int i;
	int cla;
	char choice[200];

	while (1)
	{
		system("cls");
		printf("==============================================================\n");
		printf("--------------------------------------------------------------\n");
		printf("(����exit ����)\n");
		printf("�������³ɼ��ļ�·����");

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

		fp = fopen(filename, "r");
		if (fp == NULL)
		{
			system("cls");
			printf("�ļ���ʧ�ܣ�");
			system("pause");
		}

		else
		{
			//��ȡ�³ɼ��ļ�
			shead = Link_create(fp);
			fclose(fp);
			while (1)
			{
				//���³ɼ�
				system("cls");
				printf("==============================================================\n");
				printf("--------------------------------------------------------------\n");
				printf("ѡ����°༶(1~5)(0���ز�������)\n");
				scanf("%s", choice);
				rewind(stdin);

				if (strlen(choice) > 1)
				{
					system("cls");
					printf("�����²���");
					system("pause");
				}
				else if (choice[0] == '0')
				{
					return;
				}
				else if (choice[0] >= '1' && choice[0] <= '5')
				{
					cla = (int)(choice[0] - '0');
					Link_save(shead, cla);
					Link_destroy(shead);
					break;
				}
				else
				{
					system("cls");
					printf("�����²���");
					system("pause");
				}
			}
			system("cls");
			printf("���³ɹ�");
			system("pause");
			break;
		}
	}
}

//����ԱȨ��
void managerRoot(Teanode *thead)
{
	Teanode *tea;
	Teanode *p;
	char n[13];
	char ch;
	char choice[1000];
	int i;

	while (1)
	{
		system("cls");
		printf("==============================================================\n");
		printf("--------------------------------------------------------------\n");
		printf("����      �˺�       �Ƿ�ӵ�й���ԱȨ��\n");
		for (p = thead->next; p != NULL && p->next != NULL; p = p->next)
		{
			printf("%s     %s            ", p->name, p->num);
			if (p->adm == 'O' || p->adm == 'M')
			{
				printf("ӵ��\n");
			}
			else
			{
				printf("û��\n");
			}
		}
		printf("\n(����exit����)\n");
		printf("�������������˺Ż�������");

		for (i = 0; i < 12; i++)
		{
			scanf("%c", &ch);
			if (ch == '\n')
			{
				break;
			}
			n[i] = ch;
		}
		n[i] = '\0';
		rewind(stdin);

		if (strcmp(n, "exit") == 0)
		{
			break;
		}

		if (i == 12)
		{
			system("cls");
			printf("�˺Ż���������������������\n");
			system("pause");
		}
		//���ҽ�ʦ
		else
		{
			tea = tea_allfind(thead, n);
			if (tea == NULL)
			{
				system("cls");
				printf("δ���ҵ��ý�ʦ�������²���\n");
				system("pause");
			}
			else
			{
				if (tea->adm == 'M')
				{
					system("cls");
					printf("�����ܶ�У�����д˲�����\n");
					system("pause");
				}
				else if (tea->adm == 'O')
				{
					while (1)
					{
						choice[0] = '\0';
						system("cls");
						printf("==============================================================\n");
						printf("--------------------------------------------------------------\n");
						printf("������%s  �༶��%s  ӵ��Ȩ��\n", tea->name, tea->cla);
						printf("\n����Nȡ���ý�ʦ����ԱȨ��    ����E����:");
						scanf("%s", choice);
						rewind(stdin);
						if (strlen(choice) > 1)
						{
							system("cls");
							printf("����ʧ�ܣ������³��ԣ�\n");
							system("pause");
						}
						else if (choice[0] == 'N' || choice[0] == 'n')
						{
							tea->adm = 'I';
							tea_acc_save(thead);
							system("cls");
							printf("�����ɹ���\n");
							system("pause");
							break;
						}
						else if (choice[0] == 'E' || choice[0] == 'e')
						{
							break;
						}
						else
						{
							system("cls");
							printf("����ʧ�ܣ������³��ԣ�\n");
							system("pause");
						}
					}
				}
				else if (tea->adm == 'I')
				{
					while (1)
					{
						choice[0] = '\0';
						system("cls");
						printf("==============================================================\n");
						printf("--------------------------------------------------------------\n");
						printf("������%s  �༶��%s  û��Ȩ��\n", tea->name, tea->cla);
						printf("\n����Y����ý�ʦ����ԱȨ��    ����E����:");
						scanf("%s", choice);
						rewind(stdin);
						if (strlen(choice) > 1)
						{
							system("cls");
							printf("����ʧ�ܣ������³��ԣ�\n");
							system("pause");
						}
						else if (choice[0] == 'Y' || choice[0] == 'y')
						{
							tea->adm = 'O';
							tea_acc_save(thead);
							system("cls");
							printf("�����ɹ���\n");
							system("pause");
							break;
						}
						else if (choice[0] == 'E' || choice[0] == 'e')
						{
							break;
						}
						else
						{
							system("cls");
							printf("����ʧ�ܣ������³��ԣ�\n");
							system("pause");
						}
					}
				}
			}
		}
	}
}

//����Ա�����ʦ��
void adm_To_tea(Teanode *tea, Teanode *teahead)
{
	char cla[1000];
	int k;
	Node *shead;
	while (1)
	{
		cla[0] = '\0';
		//ѡ��༶
		system("cls");
		Face_class();

		scanf("%s", cla);
		rewind(stdin);
		if (strlen(cla) > 1)
		{
			system("cls");
			printf("�����²�����\n");
			system("pause");
		}
		else if (cla[0] == '0')
		{
			break;
		}
		else if (cla[0] >= '1' && cla[0] <= '5')
		{
			shead = Find_class(cla[0]);

			if (shead == NULL)
			{
				system("cls");
				printf("�������г���ֹͣ����\n");
				exit(1);
			}
			else
			{
				//�����ʦ��
				k = (int)(cla[0] - '0');
				admTotea_inoperate(shead, k, tea, teahead);
				Link_destroy(shead);
				break;
			}
		}
		else
		{
			system("cls");
			printf("�����²�����\n");
			system("pause");
		}
	}
}

void teaIncrease(Teanode *thead)
{
	char cla[1000];
	int k;

	while (1)
	{
		cla[0] = '\0';
		system("cls");
		printf("======================================\n");
		printf("-------------��Ҫ��ӵĽ�ʦ�İ༶-----\n");
		printf("--------------------------------------\n");
		printf("--------------1.class1----------------\n");
		printf("--------------------------------------\n");
		printf("--------------2.class2----------------\n");
		printf("--------------------------------------\n");
		printf("--------------3.class3----------------\n");
		printf("--------------------------------------\n");
		printf("--------------4.class4----------------\n");
		printf("--------------------------------------\n");
		printf("--------------5.class5----------------\n");
		printf("--------------------------------------\n");
		printf("--------------0.����------------------\n");
		printf("--------------------------------------\n");
		printf("======================================\n");
		scanf("%c", cla);
		rewind(stdin);

		if (cla[0] == '0')
		{
			break;
		}
		else if (cla[0] >= '1' && cla[0] <= '5')
		{
			k = (int)(cla[0] - '0');
			tea_acc_enroll(k, thead);
			break;
		}
		else
		{
			system("cls");
			printf("�����²���\n");
			system("pause");
		}
	}
}

void adm_change(Teanode *thead)
{
	Teanode *tea;
	char n[13];
	char ch;
	int i;
	char choice[1000];

	while (1)
	{
		system("cls");
		printf("==============================================================\n");
		printf("--------------------------------------------------------------\n");
		printf("(����exit����)");
		printf("��������Ҫ�޸ĵ��˻����˺Ż�������");

		for (i = 0; i < 12; i++)
		{
			scanf("%c", &ch);
			if (ch == '\n')
			{
				break;
			}
			n[i] = ch;
		}
		rewind(stdin);
		n[i] = '\0';

		if (i == 12)
		{
			system("cls");
			printf("�����²���\n");
			system("pause");
		}

		if (strcmp(n, "exit") == 0)
		{
			break;
		}
		tea = tea_allfind(thead, n);
		if (tea == NULL)
		{
			system("cls");
			printf("�����²���\n");
			system("pause");
		}
		else
		{
			while (1)
			{
				choice[0] = '\0';
				system("cls");
				printf("==============================================================\n");
				printf("--------------------------------------------------------------\n");
				printf("����     �˺�     �༶   \n");
				printf("%s   %s   %s", tea->name, tea->num, tea->cla);
				printf("\n��ѡ����Ҫ�޸ĵ��\n");
				printf("1.����  2.�˺�  3.�༶  0.����\n");
				scanf("%s", choice);
				rewind(stdin);
				if (strlen(choice) > 1)
				{
					system("cls");
					printf("�����²���\n");
					system("pause");
				}
				else if (choice[0] == '0')
				{
					return;
				}
				else
				{
					switch (choice[0])
					{
					case '1':
					{
						adm_change_name(tea, thead);
						break;
					}
					case '2':
					{
						adm_change_num(tea, thead);
						break;
					}
					case '3':
					{
						adm_change_class(tea, thead);
						break;
					}
					default:
					{
						system("cls");
						printf("�����²���\n");
						system("pause");
						break;
					}
					}
				}
			}
		}
	}
}

//�޸Ľ�ʦ�˻�����
void adm_change_name(Teanode *tea, Teanode *thead)
{
	char name[13];
	char ch;
	int i;

	while (1)
	{
		system("cls");
		printf("==============================================================\n");
		printf("--------------------------------------------------------------\n");
		printf("(����exit����)");
		printf("��������������");

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

		if (i == 12)
		{
			system("cls");
			printf("�����²���\n");
			system("pause");
		}

		else if (strcmp(name, "exit") == 0)
		{
			break;
		}
		else if (judg_Chinese(name) == 0)
		{
			system("cls");
			printf("��������ȷ������\n");
			system("pause");
		}
		else
		{
			strcpy(tea->name, name);
			tea_acc_save(thead);
			system("cls");
			printf("�޸ĳɹ���\n");
			system("pause");
			break;
		}
	}
}

//�޸Ľ�ʦ�˺�
void adm_change_num(Teanode *tea, Teanode *thead)
{
	char num[13];
	char ch;
	int i;

	while (1)
	{
		system("cls");
		printf("==============================================================\n");
		printf("--------------------------------------------------------------\n");
		printf("(����exit����)");
		printf("���������˺ţ�");

		for (i = 0; i < 12; i++)
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

		if (i == 12)
		{
			system("cls");
			printf("�����²���\n");
			system("pause");
		}

		if (strcmp(num, "exit") == 0)
		{
			break;
		}
		else if (judg_repeat_tea(thead, num))
		{
			system("cls");
			printf("�˺��ظ���������ѡ��\n");
			system("pause");
		}
		else if (judg_Chinese(num) == 1)
		{
			system("cls");
			printf("�����Ժ������˺ţ�\n");
			system("pause");
		}
		else
		{
			strcpy(tea->num, num);
			tea_acc_save(thead);
			system("cls");
			printf("�޸ĳɹ���\n");
			system("pause");
			break;
		}
	}
}

//�޸Ľ�ʦ�༶
void adm_change_class(Teanode *tea, Teanode *thead)
{
	char cla;
	while (1)
	{
		system("cls");
		Face_class();
		scanf("%c", &cla);
		rewind(stdin);

		if (cla == '0')
		{
			break;
		}
		if (cla >= '1' && cla <= '5')
		{
			tea->cla[5] = cla;
			tea_acc_save(thead);
			system("cls");
			printf("�޸ĳɹ���\n");
			system("pause");
			break;
		}
		else
		{
			system("cls");
			printf("�����²���\n");
			system("pause");
		}
	}
}


//ɾ���˻�
void teaDelete(Teanode *thead)
{
	Teanode *tea;
	Teanode *p;
	char n[13];
	char ch;
	int i;

	while (1)
	{
		system("cls");
		printf("==============================================================\n");
		printf("--------------------------------------------------------------\n");
		printf("(����exit����)");
		printf("��������Ҫɾ�����˻����˺Ż�������");

		for (i = 0; i < 12; i++)
		{
			scanf("%c", &ch);
			if (ch == '\n')
			{
				break;
			}
			n[i] = ch;
		}
		rewind(stdin);
		n[i] = '\0';

		if (i == 12)
		{
			system("cls");
			printf("�����²���\n");
			system("pause");
		}

		if (strcmp(n, "exit") == 0)
		{
			break;
		}
		tea = tea_allfind(thead, n);
		if (tea == NULL)
		{
			system("cls");
			printf("�����²���\n");
			system("pause");
		}
		else
		{
			p = thead->next;
			for (; p->next != tea; p = p->next)
			{
				;
			}
			p->next = tea->next;
			free(tea);
			tea_acc_save(thead);

			system("cls");
			printf("ɾ���ɹ���\n");
			system("pause");
			break;
		}
	}
}

//�����˻�
void tea_findWord(Teanode *thead)
{
	Teanode *tea;
	char n[13];
	char ch;
	int i;

	while (1)
	{
		system("cls");
		printf("==============================================================\n");
		printf("--------------------------------------------------------------\n");
		printf("(����exit����)");
		printf("��������Ҫ���ҵ��˻����˺Ż�������");

		for (i = 0; i < 12; i++)
		{
			scanf("%c", &ch);
			if (ch == '\n')
			{
				break;
			}
			n[i] = ch;
		}
		rewind(stdin);
		n[i] = '\0';

		if (i == 12)
		{
			system("cls");
			printf("�����²���\n");
			system("pause");
		}

		if (strcmp(n, "exit") == 0)
		{
			break;
		}
		tea = tea_allfind(thead, n);
		if (tea == NULL)
		{
			system("cls");
			printf("�����²���\n");
			system("pause");
		}
		else
		{
			system("cls");
			printf("==============================================================\n");
			printf("--------------------------------------------------------------\n");
			printf("���˻���Ϣ����:\n");
			printf("������%s  �˺ţ�%s   �༶��%s\n", tea->name, tea->num, tea->cla);
			system("pause");
			break;
		}
	}
}

//Teanode *tea_input()
//{
//	Teanode *thead;
//	Teanode *p;
//	Teanode *link;
//	Teanode *qPrintf;
//	char n[13];
//	char cla[] = "class";
//	char ch;
//	int i;
//	int key = 0;
//
//	thead = (Teanode *)malloc(sizeof(Teanode));
//	thead->next = NULL;
//	link = thead;
//
//	system("cls");
//	printf("==============================================================\n");
//	printf("--------------------------------------------------------------\n");
//	printf("��������Ϣ(����������end����)��\n");
//	printf("����     �˺�     ����    �༶     ����ԱȨ��\n");
//	while (1)
//	{
//		p = (Teanode*)malloc(sizeof(Teanode));
//		//��������
//		while (1)
//		{
//			for (i = 0; i < 12; i++)
//			{
//				scanf("%c", &ch);
//				if (ch == '\n' || ch == ' ')
//				{
//					break;
//				}
//				n[i] = ch;
//			}
//
//			n[i] = '\0';
//
//			if (i == 12)
//			{
//				system("cls");
//				printf("�����²���\n");
//				system("pause");
//				system("cls");
//				printf("==============================================================\n");
//				printf("--------------------------------------------------------------\n");
//				printf("��������Ϣ(����������end����)��\n");
//				printf("����     �˺�     ����    �༶     ����ԱȨ��\n");
//				for (qPrintf = thead->next; qPrintf != NULL; qPrintf = qPrintf->next)
//				{
//					printf("%s %s %s %s %c\n", qPrintf->name, qPrintf->num, qPrintf->password, qPrintf->cla, qPrintf->adm);
//				}
//				rewind(stdin);
//			}
//
//			if (strcmp(n, "end") == 0)
//			{
//				break;
//			}
//			else
//			{
//				strcpy(p->name, n);
//				break;
//			}
//		}
//		//����¼��
//		if (strcmp(n, "end") == 0)
//		{
//			break;
//		}
//		//�����˺�
//		while (1)
//		{
//			for (i = 0; i < 12; i++)
//			{
//				scanf("%c", &ch);
//				if (ch == '\n' || ch == ' ')
//				{
//					break;
//				}
//				n[i] = ch;
//			}
//
//			n[i] = '\0';
//
//			if (i == 12)
//			{
//				system("cls");
//				printf("�����²���\n");
//				system("pause");
//				system("cls");
//				printf("==============================================================\n");
//				printf("--------------------------------------------------------------\n");
//				printf("��������Ϣ(����������end����)��\n");
//				printf("����     �˺�     ����    �༶     ����ԱȨ��\n");
//				for (qPrintf = thead->next; qPrintf != NULL; qPrintf = qPrintf->next)
//				{
//					printf("%s %s %s %s %c\n", qPrintf->name, qPrintf->num, qPrintf->password, qPrintf->cla, qPrintf->adm);
//				}
//				printf("%s ", p->name);
//				rewind(stdin);
//			}
//			else
//			{
//				strcpy(p->num, n);
//				break;
//			}
//		}
//
//		//��������
//		while (1)
//		{
//			for (i = 0; i < 12; i++)
//			{
//				scanf("%c", &ch);
//				if (ch == '\n' || ch == ' ')
//				{
//					break;
//				}
//				n[i] = ch;
//			}
//
//			n[i] = '\0';
//
//			if (i == 12)
//			{
//				system("cls");
//				printf("�����²���\n");
//				system("pause");
//				system("cls");
//				printf("==============================================================\n");
//				printf("--------------------------------------------------------------\n");
//				printf("��������Ϣ(����������end����)��\n");
//				printf("����     �˺�     ����    �༶     ����ԱȨ��\n");
//				for (qPrintf = thead->next; qPrintf != NULL; qPrintf = qPrintf->next)
//				{
//					printf("%s %s %s %s %c\n", qPrintf->name, qPrintf->num, qPrintf->password, qPrintf->cla, qPrintf->adm);
//				}
//				printf("%s %s ", p->name, p->num);
//				rewind(stdin);
//			}
//			else
//			{
//				strcpy(p->password, n);
//				break;
//			}
//		}
//
//		//����༶
//		while (1)
//		{
//			for (i = 0; i < 7; i++)
//			{
//				scanf("%c", &ch);
//				if (ch == '\n' || ch == ' ')
//				{
//					break;
//				}
//				n[i] = ch;
//			}
//
//			n[i] = '\0';
//
//			//�̶��༶��ʽ
//			if (i != 6)
//			{
//				key++;
//			}
//			else
//			{
//				for (i = 0; i <= 4; i++)
//				{
//					if (cla[i] != n[i])
//					{
//						key++;
//					}
//				}
//				if (n[5] < '1' || n[5] > '5')
//				{
//					key++;
//				}
//			}
//
//			if (key != 0)
//			{
//				system("cls");
//				printf("�����²���\n");
//				system("pause");
//				system("cls");
//				printf("==============================================================\n");
//				printf("--------------------------------------------------------------\n");
//				printf("��������Ϣ(����������end����)��\n");
//				printf("����     �˺�     ����    �༶     ����ԱȨ��\n");
//				for (qPrintf = thead->next; qPrintf != NULL; qPrintf = qPrintf->next)
//				{
//					printf("%s %s %s %s %c\n", qPrintf->name, qPrintf->num, qPrintf->password, qPrintf->cla, qPrintf->adm);
//				}
//				printf("%s %s %s ", p->name, p->num, p->password);
//				key = 0;
//				rewind(stdin);
//			}
//
//			else
//			{
//				strcpy(p->cla, n);
//				break;
//			}
//		}
//
//		//����ԱȨ��
//		while (1)
//		{
//			scanf("%c", &ch);
//
//			if (ch != 'M' && ch != 'O' && ch != 'I')
//			{
//				system("cls");
//				printf("�����²���\n");
//				system("pause");
//				system("cls");
//				printf("==============================================================\n");
//				printf("--------------------------------------------------------------\n");
//				printf("��������Ϣ(����������end����)��\n");
//				printf("����     �˺�     ����    �༶     ����ԱȨ��\n");
//				for (qPrintf = thead->next; qPrintf != NULL; qPrintf = qPrintf->next)
//				{
//					printf("%s %s %s %s %c\n", qPrintf->name, qPrintf->num, qPrintf->password, qPrintf->password, qPrintf->adm);
//				}
//				printf("%s %s %s %s ", p->name, p->num, p->password, p->cla);
//				rewind(stdin);
//			}
//			else
//			{
//				p->adm = ch;
//				system("cls");
//				printf("==============================================================\n");
//				printf("--------------------------------------------------------------\n");
//				printf("��������Ϣ(����������end����)��\n");
//				printf("����     �˺�     ����    �༶     ����ԱȨ��\n");
//				for (qPrintf = thead->next; qPrintf != NULL; qPrintf = qPrintf->next)
//				{
//					printf("%s %s %s %s %c\n", qPrintf->name, qPrintf->num, qPrintf->password, qPrintf->password, qPrintf->adm);
//				}
//				printf("%s %s %s %s %c\n", p->name, p->num, p->password, p->cla, p->adm);
//				getchar();
//				break;
//			}
//		}
//		link->next = p;
//		link = p;
//		link->next = NULL;
//	}
//	p = (Teanode*)malloc(sizeof(Teanode));
//	link->next = p;
//	link = p;
//	link->next = NULL;
//	tea_acc_save(thead);
//	system("cls");
//	printf("¼�����");
//	system("pause");
//	return thead;
//}

