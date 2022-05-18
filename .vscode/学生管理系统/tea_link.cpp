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
		printf("\n增加学生信息\n\n");
		printf("(输入exit返回)\n");
		printf("请输入学生姓名：");
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
			printf("名字过长，请重新输入！");
			system("pause");
			key = 0;
		}
		else if (strlen(stu->name) == 0)
		{
			system("cls");
			printf("名字不正确，请重新输入！");
			system("pause");
			key = 0;
		}
		else if (judg_Chinese(stu->name) == 0)
		{
			system("cls");
			printf("名字不正确，请重新输入！");
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
			printf("\n增加学生信息\n\n");
			printf("(输入exit返回)\n");
			printf("请输入学生姓名：%s\n", stu->name);
			printf("请输入学号（最多5位）：");

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
				printf("学号不正确，请重新输入！");
				system("pause");
				key = 0;
			}
			else if (judg_repeat_stu(head, stu->num))
			{
				system("cls");
				printf("学号重复，请重新输入！");
				system("pause");
				key = 0;
			}
			else if (judg_Chinese(stu->num) == 1)
			{
				system("cls");
				printf("不能以汉字做学号！\n");
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
			printf("\n增加学生信息\n\n");
			printf("(输入-1返回)\n");
			printf("请输入学生姓名：%s\n", stu->name);
			printf("请输入学号（最多5位）：%s\n", stu->num);
			printf("请输入语文成绩:");

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
				printf("成绩不正确，请重新输入！");
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
			printf("\n增加学生信息\n\n");
			printf("(输入-1返回)\n");
			printf("请输入学生姓名：%s\n", stu->name);
			printf("请输入学号（最多5位）：%s\n", stu->num);
			printf("请输入语文成绩:%d\n", stu->Chinese_grades);
			printf("请输入数学成绩:");

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
				printf("成绩不正确，请重新输入！");
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
			printf("\n增加学生信息\n\n");
			printf("(输入-1返回)\n");
			printf("请输入学生姓名：%s\n", stu->name);
			printf("请输入学号（最多5位）：%s\n", stu->num);
			printf("请输入语文成绩:%d\n", stu->Chinese_grades);
			printf("请输入数学成绩:%d\n", stu->Math_grades);
			printf("请输入英语成绩:");

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
				printf("成绩不正确，请重新输入！");
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
				strcpy(stu->classname, "网络1班");
				break;
			}
			case 2:
			{
				strcpy(stu->classname, "网络2班");
				break;
			}
			case 3:
			{
				strcpy(stu->classname, "网络3班");
				break;
			}
			case 4:
			{
				strcpy(stu->classname, "网络4班");
				break;
			}
			case 5:
			{
				strcpy(stu->classname, "网络5班");
				break;
			}
			default:
			{
				system("cls");
				printf("程序运行出错，停止运行");
				system("pause");
				exit(1);
			}
			}
			strcpy(stu->password, "123456");
		}

		stu->next = head->next;
		head->next = stu;

		Link_save(head, cla);


		printf("增加成功！");
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
		printf("(输入exit返回)\n");
		printf("请输入学生姓名/学号：");
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
			printf("名字/学号过长，请重新输入！");
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
					printf("未寻找到该学生，请重新操作！\n");
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
			printf("删除完成！");
			system("pause");
			break;
		}
	}
}

//学生信息修改
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
					while (1)
					{
						printf("\n输入（exit）返回\n");
						printf("请输入学生姓名：");
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
							printf("名字过长，请重新输入！\n");

						}
						else if (judg_Chinese(name) == 0)
						{
							printf("名字不正确，请重新输入！\n");
						}
						else
						{
							strcpy(stu->name, name);
							Link_save(head, cla);
							printf("名字修改成功！\n");
							break;
						}
					}
					break;
				}
				case '2':
				{
					while (1)
					{
						printf("\n输入（exit）返回\n");
						printf("请输入学生号(最多五位)：");
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
							printf("学号不正确，请重新输入！\n");
						}
						else if (num[0] != '0' || num[1] != ch)
						{
							printf("学号不正确，请重新输入！\n");
						}
						else if (judg_repeat_stu(head, num))
						{
							printf("学号重复！\n");
						}
						else
						{
							strcpy(stu->num, num);
							Link_save(head, cla);
							printf("学号修改成功！\n");
							break;
						}
					}
					break;
				}
				case '3':
				{
					while (1)
					{
						printf("(输入-1返回)\n");
						printf("请输入语文成绩:");

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
							printf("语文修改成功！\n");
							break;
						}
						else
						{
							printf("成绩不正确，请重新输入！");
						}
					}
					break;
				}
				case '4':
				{
					while (1)
					{
						printf("(输入-1返回)\n");
						printf("请输入数学成绩:");

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
							printf("数学修改成功！\n");
							break;
						}
						else
						{
							printf("成绩不正确，请重新输入！");
						}
					}
					break;
				}
				case '5':
				{
					while (1)
					{
						printf("请输入英语成绩:");
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
							printf("英语修改成功！\n");
							break;
						}
						else
						{
							printf("成绩不正确，请重新输入！");
						}
					}
					break;
				}
				default:
				{
					printf("请重新选择！\n");
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
		printf("(输入exit 返回)\n");
		printf("请输入文件路径：");

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

		//返回条件
		if (strcmp(filename, "exit") == 0)
		{
			break;
		}

		fp = fopen(filename, "wt");
		if (fp == NULL)
		{
			system("cls");
			printf("文件打开失败！");
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
			printf("下载成功");
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
		printf("成绩分析：\n");
		printf("语文平均分：%.2f\n", CH);
		printf("数学平均分：%.2f\n", MA);
		printf("英语平均分：%.2f\n", EN);
		printf("---------------------------------\n");
		printf("是否对学生成绩排序并输出？\n");
		printf("1. 升序    2. 降序    0.返回\n");

		scanf("%s", choice);
		rewind(stdin);
		if (strlen(choice) > 1)
		{
			system("cls");
			printf("请重新操作！");
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
			printf("请重新操作！");
			system("pause");
		}
	}
}