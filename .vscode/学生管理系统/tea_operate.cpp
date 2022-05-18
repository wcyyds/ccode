#include"head.h"

void tea_operate()
{
	char choice1[200], choice2[200];
	int cla;
	Teanode *acchead;
	Node *clahead;
	int key = 0;

	acchead = tea_account();

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
		scanf("%s", choice1);
		rewind(stdin);
		if (strlen(choice1) > 1)
		{
			system("cls");
			printf("输入错误");
			system("pause");
		}
		else if (choice1[0] == '0')
		{
			Link_tea_destroy(acchead);
			acchead = NULL;
			break;
		}

		else
		{
			clahead = Find_class(choice1[0]);
			//确保班级读取成功
			if (clahead != NULL)
			{
				key = 1;
			}
			if (key == 1)
			{
				while (1)
				{
					choice2[0] = '\0';
					system("cls");
					tea_face();
					scanf("%s", choice2);
					rewind(stdin);
					if (strlen(choice2) > 1)
					{
						system("cls");
						printf("输入错误");
						system("pause");
					}
					else if (choice2[0] == '0')
					{
						WD = 1;
						Link_destroy(clahead);
						clahead = NULL;
						break;
					}

					else
					{
						switch (choice2[0])
						{
						case '1':
						{
							cla = (int)(choice1[0] - '0');
							tea_acc_enroll(cla, acchead);
							break;
						}
						case '2':
						{
							cla = (int)(choice1[0] - '0');
							tea_login(acchead, clahead, cla);
							break;
						}
						case '3':
						{
							tea_passback(acchead);
							break;
						}
						default:
						{
							system("cls");
							printf("输入错误");
							system("pause");
							break;
						}
						}
					}
				}
				key = 0;
			}
		}
	}
}

//账户注册
void tea_acc_enroll(int cla, Teanode *acchead)
{
	Teanode *tea;
	Teanode *r = acchead->next;
	char ch;
	int i;

	tea = (Teanode*)malloc(sizeof(Teanode));

	switch (cla)
	{
	    case 1:
		{
			strcpy(tea->cla, "class1");
			break;
		}
		case 2:
		{
			strcpy(tea->cla, "class2");
			break;
		}
		case 3:
		{
			strcpy(tea->cla, "class3");
			break;
		}
		case 4:
		{
			strcpy(tea->cla, "class4");
			break;
		}
		case 5:
		{
			strcpy(tea->cla, "class5");
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

	while (1)
	{
		system("cls");
		printf("======================================\n");
		printf("--------------------------------------\n");
		printf("(输入exit返回)\n");
		printf("请输入姓名：");
		for (i = 0; i < 12; i++)
		{
			scanf("%c", &ch);
			if (ch == '\n')
			{
				break;
			}
			tea->name[i] = ch;
		}
		rewind(stdin);
		tea->name[i] = '\0';

		if (strcmp(tea->name, "exit") == 0)
		{
			break;
		}

		else if (judg_Chinese(tea->name) == 0)
		{
			system("cls");
			printf("名字不正确，请重新输入！");
			system("pause");
		}
		else if (i == 12)
		{
			system("cls");
			printf("名字过长，请重新输入！");
			system("pause");
		}
		else if (strlen(tea->name) == 0)
		{
			system("cls");
			printf("名字不正确，请重新输入！");
			system("pause");
		}
		else
		{
			printf("请输入账号（最多11位）：");

			for (i = 0; i < 12; i++)
			{
				scanf("%c", &ch);
				if (ch == '\n')
				{
					break;
				}
				tea->num[i] = ch;
			}
			rewind(stdin);
			tea->num[i] = '\0';

			if (strcmp(tea->num, "exit") == 0)
			{
				break;
			}

			else if (i == 12)
			{
				system("cls");
				printf("账号过长，请重新输入！");
				system("pause");
			}
			else if (strlen(tea->num) == 0)
			{
				system("cls");
				printf("账号不正确，请重新输入！");
				system("pause");
			}
			else if (judg_Chinese(tea->num) == 1)
			{
				system("cls");
				printf("不能以汉字做账号！\n");
				system("pause");
			}
			else if (judg_repeat_tea(acchead, tea->num))
			{
				system("cls");
				printf("账号重复，请重新输入！");
				system("pause");
			}
			else
			{
				printf("请输入密码（最多11位）：");

				for (i = 0; i < 200; i++)
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
							i = i - 1;
							continue;
						}
						else
						{
							i = i - 1;
							tea->password[i] = '\0';
							i = i - 1;
							printf("\b");
							printf(" ");
							printf("\b");
						}
					}
					else
					{
						printf("*");
						tea->password[i] = ch;
					}
				}
				rewind(stdin);
				tea->password[i] = '\0';

				if (strcmp(tea->password, "exit") == 0)
				{
					break;
				}

				else if (i == 12)
				{
					system("cls");
					printf("密码过长，请重新输入！");
					system("pause");
				}
				else if (judg_Chinese(tea->password) == 1)
				{
					system("cls");
					printf("不能以汉字做密码！\n");
					system("pause");
				}
				else if (strlen(tea->password) == 0)
				{
					system("cls");
					printf("密码不正确，请重新输入！");
					system("pause");
				}
				else
				{
					tea->adm = 'I';
					//将账户连接到链表上
					tea->next = r;
					acchead->next = tea;

					//保存
					tea_acc_save(acchead);

					system("cls");
					printf("注册成功！");
					system("pause");
					break;
				}
			}
		}
	}
}

void tea_login(Teanode *head, Node *clahead, int cla)
{
	Teanode *tea;
	char num[13];
	char password[200];
	char ch;
	int i;

	while (1)
	{
		system("cls");
		printf("======================================\n");
		printf("--------------------------------------\n");
		printf("         请输入账号和密码             \n");
		printf("          (输入exit退出)\n");
		printf("\n         账户：");
		rewind(stdin);
		for (i = 0; i < 12; i++)       //循环录入账户，防止数组越界
		{
			scanf("%c", &ch);
			if (ch == '\n')           //检测到换行符退出
			{
				break;
			}
			num[i] = ch;
		}
		rewind(stdin);
		num[i] = '\0';

		if (strcmp(num, "exit") == 0)      //特殊条件退出账户输入
		{
			break;
		}

		printf("\n         输入密码：");
		rewind(stdin);
		for (i = 0; i < 200; i++)       //循环录入密码，防止数组越界
		{
			ch = _getch();
			if (ch == '\n' || ch == '\r')           //检测到换行符退出
			{
				break;
			}
			else if (ch == '\b')
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

		tea = Find_tea(head, num);

		if (tea == NULL)
		{
			system("cls");
			printf("账户错误，按任意键重新输入\n");
			system("pause");
		}
		else if ((int)(tea->cla[5] - '0') != cla)
		{
			system("cls");
			printf("班级错误，按任意键重新输入\n");
			system("pause");
		}

		else if (strcmp(password, tea->password) == 0)
		{
			system("cls");
			printf("登录成功，按任意键继续操作!\n");
			system("pause");

			//登录成功， 进入操作
			tea_inoperate(clahead, cla, tea, head);
			break;
		}

		else
		{
			system("cls");
			printf("密码错误，按任意键重新输入！\n");
			system("pause");
		}
	}
}

void tea_inoperate(Node *clahead, int cla, Teanode *tea, Teanode *teahead)
{
	char choice[1000];
	Node *stu;
	Teanode *rhead;
	Teanode *s;

	while (1)
	{
		choice[0] = '\0';
		system("cls");
		tea_oper_face();

		scanf("%s", choice);
		rewind(stdin);
		if (strlen(choice) > 1)
		{
			system("cls");
			printf("请重新选择！");
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
				stu_increase(clahead, cla);
				break;
			}
			case '2':
			{
				stu_del(clahead, cla);
				break;
			}
			case '3':
			{
				stu_revise(clahead, cla);
				break;
			}
			case '4':
			{
				stu = stu_allfind(clahead);
				if (stu != NULL)
				{
					system("cls");
					printf("该学生信息如下：\n");
					printf("姓名       学号     语文    数学    英语\n");
					printf("%s     %s      %d     %d     %d\n", stu->name, stu->num, stu->Chinese_grades, stu->Math_grades, stu->English_grades);
					system("pause");
				}
				stu = NULL;
				break;
			}
			case '5':
			{
				system("cls");
				stu_sort_up(clahead);
				print_class_grades(clahead);
				system("pause");
				break;
			}
			case '6':
			{
				tea_save_loc(clahead);
				break;
			}
			case '7':
			{
				tea_password_change(teahead, tea);
				break;
			}
			case '8':
			{
				tea_grades_anlayse(clahead);
				break;
			}
			case '9':
			{
				rhead = tea_Remind();
				s = (Teanode*)malloc(sizeof(Teanode));

				*s = *tea;
				s->next = rhead->next;
				rhead->next = s;
				tea_remind_save(rhead);
				Link_tea_destroy(rhead);
				system("cls");
				printf("提醒成功\n");
				system("pause");
				break;
			}
			case 'a':
			{
				Link_tea_destroy(teahead);
				Link_destroy(clahead);
				system("cls");
				printf("已退出\n");
				exit(0);
			}
			default:
			{
				system("cls");
				printf("请重新选择！");
				system("pause");
				break;
			}
			}
		}
	}
}

void admTotea_inoperate(Node *clahead, int cla, Teanode *tea, Teanode *teahead)
{
	char choice[1000];
	Node *stu;

	while (1)
	{
		choice[0] = '\0';
		system("cls");
		adm_to_face();

		scanf("%s", choice);
		rewind(stdin);
		if (strlen(choice) > 1)
		{
			system("cls");
			printf("请重新选择！");
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
				stu_increase(clahead, cla);
				break;
			}
			case '2':
			{
				stu_del(clahead, cla);
				break;
			}
			case '3':
			{
				stu_revise(clahead, cla);
				break;
			}
			case '4':
			{
				stu = stu_allfind(clahead);
				if (stu != NULL)
				{
					system("cls");
					printf("该学生信息如下：\n");
					printf("姓名       学号     语文    数学    英语\n");
					printf("%s     %s      %d     %d     %d\n", stu->name, stu->num, stu->Chinese_grades, stu->Math_grades, stu->English_grades);
					system("pause");
				}
				stu = NULL;
				break;
			}
			case '5':
			{
				system("cls");
				stu_sort_up(clahead);
				print_class_grades(clahead);
				system("pause");
				break;
			}
			case '6':
			{
				tea_save_loc(clahead);
				break;
			}
			case '7':
			{
				tea_password_change(teahead, tea);
				break;
			}
			case '8':
			{
				tea_grades_anlayse(clahead);
				break;
			}
			case 'a':
			{
				Link_tea_destroy(teahead);
				Link_destroy(clahead);
				system("cls");
				printf("已退出\n");
				exit(0);
			}
			default:
			{
				system("cls");
				printf("请重新选择！");
				system("pause");
				break;
			}
			}
		}
	}
}