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
			printf("选择失败,");
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
						printf("选择失败,");
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
							printf("选择失败,");
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
			printf("输入错误，按任意键重新输入");
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
				printf("%s的成绩如下：", stu->name);
				printf("语文：%d    数学：%d    英语：%d\n", stu->Chinese_grades, stu->Math_grades, stu->English_grades);
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
				printf("已退出\n");
				exit(0);
			}
			default:
			{
				system("cls");
				printf("输入错误，按任意键重新输入");
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
		//输入学号和密码
		system("cls");
		printf("======================================\n");
		printf("--------------------------------------\n");
		printf("         请输入学号和密码             \n");
		printf("          (输入exit退出)\n");
		printf("\n         学号：");
		rewind(stdin);
		for (i = 0; i < 5; i++)       //循环录入学号，防止数组越界
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

		if (strcmp(num, "exit") == 0)      //特殊条件退出学号输入
		{
			break;
		}

		printf("\n         输入密码：");
		rewind(stdin);
		for (i = 0; i < 200; i++)       //循环录入学号，防止数组越界
		{
			ch = _getch();

			if (ch == '\n' || ch == '\r')           //检测到换行符退出
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

		if (strcmp(password, "exit") == 0)      //特殊条件退出学号登录
		{
			break;
		}
		//查找学生
		stu = Find_num(head, num);

		if (stu == NULL)
		{
			system("cls");
			printf("学号错误，按任意键重新输入\n");
			system("pause");
		}

		else if (strcmp(password, stu->password) == 0)
		{
			system("cls");
			printf("登录成功，按任意键继续操作!\n");
			system("pause");

			//登录成功， 进入操作

			stu_operate(head, stu, cla);
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

void stu_analyse(Node *stu, Node *head)
{
	char ch1[10], ch2[10], ch3[10];
	int i = 1;
	Node *r;
	if (stu->Chinese_grades >= 80)
	{
		strcpy(ch1, "优秀");
	}
	else if (stu->Chinese_grades >= 60 && stu->Chinese_grades < 80)
	{
		strcpy(ch1, "良好");
	}
	else
	{
		strcpy(ch1, "不乐观");
	}
	if (stu->Math_grades >= 80)
	{
		strcpy(ch2, "优秀");
	}
	else if (stu->Math_grades >= 60 && stu->Math_grades < 80)
	{
		strcpy(ch2, "良好");
	}
	else
	{
		strcpy(ch2, "不乐观");
	}
	if (stu->English_grades >= 80)
	{
		strcpy(ch3, "优秀");
	}
	else if (stu->English_grades >= 60 && stu->English_grades < 80)
	{
		strcpy(ch3, "良好");
	}
	else
	{
		strcpy(ch3, "不乐观");
	}
	system("cls");
	printf("======================================\n");
	printf("--------------------------------------\n");
	printf("您的成绩分析如下：\n");
	stu_sort_up(head);
	for (r = head->next; r != NULL && r->next != NULL; r = r->next)
	{
		if (strcmp(r->num, stu->num) == 0)
		{
			break;
		}
		i++;
	}
	printf("\n您的班级排名为%d\n", i);
	printf("\n您的语文分数%d     %s\n", stu->Chinese_grades, ch1);
	printf("\n您的数学分数%d     %s\n", stu->Math_grades, ch2);
	printf("\n您的英语分数%d     %s\n", stu->English_grades, ch1);
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
		//输入学号和密码
		system("cls");
		printf("======================================\n");
		printf("--------------------------------------\n");
		printf("            请输入学号                \n");
		printf("          (输入exit退出)\n");
		printf("\n         学号：");
		rewind(stdin);
		for (i = 0; i < 5; i++)       //循环录入学号，防止数组越界
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

		if (strcmp(num, exit) == 0)      //特殊条件退出学号输入
		{
			break;
		}

		printf("\n         输入验证码（12345）：");
		rewind(stdin);
		for (i = 0; i < 12; i++)       //循环录入学号，防止数组越界
		{
			scanf("%c", &ch);
			if (ch == '\n')           //检测到换行符退出
			{
				break;
			}
			password[i] = ch;
		}
		rewind(stdin);
		password[i] = '\0';

		if (strcmp(password, exit) == 0)      //特殊条件退出学号登录
		{
			break;
		}
		//查找学生
		stu = Find_num(head, num);

		if (stu == NULL)
		{
			system("cls");
			printf("学号错误，按任意键重新输入\n");
			system("pause");
		}

		else
		{
			system("cls");
			printf("您的密码是: %s\n", stu->password);
			system("pause");
			break;
		}
	}
}

//学生密码修改
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
		printf("(exit退出)");
		printf("请输入新密码(最多11位）：");
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

		if (strcmp(password1, exit0) == 0)      //特殊条件退出学号登录
		{
			break;
		}
		//更改密码
		if (i >= 12)
		{
			system("cls");
			printf("密码过长！\n");
			system("pause");
		}
		else if (judg_Chinese(password1) == 1)
		{
			system("cls");
			printf("不能以汉字做密码！\n");
			system("pause");
		}
		else
		{
			printf("\n请再次输入新密码(最多11位）：");
			rewind(stdin);
			for (i = 0; i < 200; i++)       //循环录入学号，防止数组越界
			{
				ch = _getch();
				if (ch == '\n' || ch == '\r')           //检测到换行符退出
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

			if (strcmp(password2, exit0) == 0)      //特殊条件退出学号登录
			{
				break;
			}
			//更改密码
			if (i >= 12)
			{
				system("cls");
				printf("密码过长！\n");
				system("pause");
			}
			else if (strcmp(password1, password2) != 0)
			{
				system("cls");
				printf("两次密码不一致！\n");
				system("pause");
			}
			else
			{
				strcpy(stu->password, password1);
				Link_save(head, cla);
				system("cls");
				printf("密码修改成功！\n");
				system("pause");
				break;
			}
		}
	}
}

//成绩申诉
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
		printf("请选择你要申诉的科目");
		printf("1.语文  2.英语  3.数学  0.返回\n");
		rewind(stdin);
		scanf("%s", choice);
		rewind(stdin);
		len = strlen(choice);
		if (len > 1)
		{
			system("cls");
			printf("请重新输入\n");
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
					printf("(输入-1返回)\n");
					printf("请输入你的新成绩：\n");
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
						printf("申诉成绩成功\n");
						system("pause");
						break;
					}
					else
					{
						system("cls");
						printf("请重新输入成绩\n");
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
					printf("(输入-1返回)\n");
					printf("请输入你的新成绩：\n");
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
						printf("申诉成绩成功\n");
						system("pause");
						break;
					}
					else
					{
						system("cls");
						printf("请重新输入成绩\n");
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
					printf("(输入-1返回)\n");
					printf("请输入你的新成绩：\n");
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
						printf("申诉成绩成功\n");
						system("pause");
						break;
					}
					else
					{
						system("cls");
						printf("请重新输入成绩\n");
						system("pause");
					}
				}
				break;
			}
			default:
			{
				system("cls");
				printf("请重新输入\n");
				system("pause");
			}
		}
	}
}