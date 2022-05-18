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
		printf("（输入exit返回）\n");
		printf("请输入账号：");
		//循环输入账号
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
		//输入exit返回
		if (strcmp(num, "exit") == 0)
		{
			break;
		}
		//控制账号长度
		if (i == 12)
		{
			system("cls");
			printf("账户过长，请重新输入！");
			system("pause");
		}

		else
		{
			printf("输入密码：");
			rewind(stdin);
			for (i = 0; i < 200; i++)       //循环录入密码，防止数组越界
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

			if (strcmp(password, "exit") == 0)      //特殊条件退出账户登录
			{
				break;
			}

			if (i >= 12)
			{
				system("cls");
				printf("密码过长，请重新输入！");
				system("pause");
			}

			else
			{
				tea = Find_tea(teahead, num);

				if (tea == NULL)
				{
					system("cls");
					printf("账户错误，按任意键重新输入\n");
					system("pause");
				}

				else if (strcmp(password, tea->password) == 0)
				{
					if (tea->adm == 'M' || tea->adm == 'O')
					{
						system("cls");
						printf("登录成功！\n");
						system("pause");
						//登录成功，进入操作界面
						adm_operate(teahead, tea);
					}

					else if (tea->adm == 'I')
					{
						system("cls");
						printf("您没有管理员权限\n");
						system("pause");
					}
					else
					{
						system("cls");
						printf("程序运行出错，停止运行\n");
						system("pause");
						exit(1);
					}
				}

				else
				{
					system("cls");
					printf("密码错误，按任意键重新输入！\n");
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
			printf("请重新操作\n");
			system("pause");
		}
		else if (choice[0] == '0')
		{
			//返回
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
				//管理员代办
				adm_agent(teahead, tea);
				break;
			}
			case '2':
			{
				//管理员进入教师端
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
				printf("姓名      账号      密码     班级\n");
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
				printf("已退出");
				exit(0);
			}
			default:
			{
				system("cls");
				printf("请重新操作\n");
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
			printf("请重新操作\n");
			system("pause");
		}
		else if (choice[0] == '0')
		{
			break;
			//返回
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
			printf("请重新操作\n");
			system("pause");
		}
	}
}

