#include"head.h"

void adm_login()
{
	Teanode *teahead;
	Teanode *tea;
	char num[13];
	char password[200];
	char ch;
	int i;

	teahead = tea_account();

	while (1)
	{
		if (WD == 1)
		{
			WD = 0;
			break;
		}
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
			printf("�������룺");
			rewind(stdin);
			for (i = 0; i < 200; i++)       //ѭ��¼�����룬��ֹ����Խ��
			{
				ch = _getch();
				if (ch == '\n' || ch == '\r')
				{
					break;
				}
				else if (ch == '\b')
				{
					if (i == 0)
					{
						i--;
						continue;
					}
					else
					{
						i--;
						password[i] = '\0';
						i--;
						printf("\b");
						printf(" ");
						printf("\b");
					}
				}
				else
				{
					printf("*");
					password[i] = ch;
				}
			}
			rewind(stdin);
			password[i] = '\0';

			if (strcmp(password, "exit") == 0)      //���������˳��˻���¼
			{
				break;
			}

			if (i >= 12)
			{
				system("cls");
				printf("������������������룡");
				system("pause");
			}

			else
			{
				tea = Find_tea(teahead, num);

				if (tea == NULL)
				{
					system("cls");
					printf("�˻����󣬰��������������\n");
					system("pause");
				}

				else if (strcmp(password, tea->password) == 0)
				{
					if (tea->adm == 'M' || tea->adm == 'O')
					{
						system("cls");
						printf("��¼�ɹ���\n");
						system("pause");
						//��¼�ɹ��������������
						adm_operate(teahead, tea);
					}

					else if (tea->adm == 'I')
					{
						system("cls");
						printf("��û�й���ԱȨ��\n");
						system("pause");
					}
					else
					{
						system("cls");
						printf("�������г���ֹͣ����\n");
						system("pause");
						exit(1);
					}
				}

				else
				{
					system("cls");
					printf("������󣬰�������������룡\n");
					system("pause");
				}
			}
		}
	}
}

void adm_operate(Teanode *teahead, Teanode *tea)
{
	char choice[100];
	Teanode *r;

	adm_rewind();
	while (1)
	{
		choice[0] = '\0';
		system("cls");
		adm_face();

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
			//����
			WD = 1;
			Link_tea_destroy(teahead);
			break;
		}
		else
		{
			switch (choice[0])
			{
			case '1':
			{
				//����Ա����
				adm_agent(teahead, tea);
				break;
			}
			case '2':
			{
				//����Ա�����ʦ��
				adm_To_tea(tea, teahead);
				break;
			}
			case '3':
			{
				teaIncrease(teahead);
				break;
			}
			case '4':
			{
				teaDelete(teahead);
				break;
			}
			case '5':
			{
				adm_change(teahead);
				break;
			}
			case '6':
			{
				tea_findWord(teahead);
				break;
			}
			/*case '7':
			{
				Link_tea_destroy(teahead);
				teahead = tea_input();
				break;
			}*/
			case '7':
			{
				system("cls");
				printf("==============================================================\n");
				printf("--------------------------------------------------------------\n");
				printf("����      �˺�      ����     �༶\n");
				for (r = teahead->next; r != NULL && r->next != NULL; r = r->next)
				{
					printf("%s    %s    %s    %s\n", r->name, r->num, r->password, r->cla);
				}
				system("pause");
				break;
			}
			case '8':
			{
				Link_tea_destroy(teahead);
				system("cls");
				printf("���˳�");
				exit(0);
			}
			default:
			{
				system("cls");
				printf("�����²���\n");
				system("pause");
			}
			}
		}
	}
}

void adm_agent(Teanode *head, Teanode *manager)
{
	char choice[200];
	while (1)
	{
		choice[0] = '\0';
		system("cls");
		adm_agent_face();

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
			break;
			//����
		}

		else if (choice[0] == '1')
		{
			adm_GradesComp();
		}
		else if (choice[0] == '2')
		{
			admUp_grades();
		}
		else if (choice[0] == '3')
		{
			managerRoot(head);
		}
		else
		{
			system("cls");
			printf("�����²���\n");
			system("pause");
		}
	}
}

