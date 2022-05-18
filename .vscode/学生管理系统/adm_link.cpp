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
		printf("（输入exit返回）\n");
		printf("请输入新密码：(最多11位）");
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

		if (strcmp(password1, "exit") == 0)      //特殊条件退出
		{
			break;
		}

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
				strcpy(tea->password, password1);
				tea_acc_save(head);
				system("cls");
				printf("密码修改成功！\n");
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
			printf("请输入验证码（12345）:");
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
			//输入exit返回
			if (strcmp(n, "exit") == 0)
			{
				break;
			}
			if (strcmp(n, "12345") != 0)
			{
				system("cls");
				printf("验证码错误，请重新输入！");
				system("pause");
			}
			else
			{
				tea = tea_allfind(head, num);
				if (tea == NULL)
				{
					system("cls");
					printf("账户出错，请重新输入！");
					system("pause");
				}
				else
				{
					system("cls");
					printf("====================================\n");
					printf("------------------------------------\n");
					printf("%s的原密码为：%s\n", tea->num, tea->password);
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

//提醒管理员更新成绩库
void adm_rewind()
{
	Teanode *rhead;
	Teanode *p;
	int i = 0;
	int k = 1;
	char choice[200];

	rhead = tea_Remind();
	p = rhead->next;
	//查看教师提醒数量
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
			printf("%d名教师提醒您更新成绩库\n", i);
			printf("是否查看详情（Y/N）\n");
			scanf("%s", &choice);
			rewind(stdin);
			if (strlen(choice) > 1)
			{
				system("cls");
				printf("请重新操作\n");
				system("pause");
			}
			//打印提醒教师详情
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
					printf("\n是否删除详情（Y/N）\n");

					scanf("%s", &choice);
					rewind(stdin);
					if (strlen(choice) > 1)
					{
						system("cls");
						printf("请重新操作\n");
						system("pause");
					}
					else if (choice[0] == 'Y' || choice[0] == 'y')
					{
						//重置教师提醒名单；
						Link_tea_destroy(rhead);
						rhead = (Teanode*)malloc(sizeof(Teanode));
						rhead->next = NULL;
						tea_remind_save(rhead);
						free(rhead);
						k = 0;
						printf("删除成功！\n");
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
				printf("请重新操作\n");
				system("pause");
			}
		}
	}
}

//管理员处理成绩申诉
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

	//没有申诉
	if (chead->next->next == NULL)
	{
		system("cls");
		printf("没有申诉\n");
		system("pause");
	}
	//有申诉
	else
	{
		while (1)
		{
			if (chead->next->next == NULL)
			{
				system("cls");
				printf("没有申诉\n");
				system("pause");
				break;
			}
			//输出申诉同学信息
			system("cls");
			printf("=========================================================\n");
			printf("---------------------------------------------------------\n");
			printf("姓名     学号   班级   科目   原成绩    申诉成绩\n");
			for (q = chead->next; q != NULL && q->next != NULL; q = q->next)
			{
				printf("%s   %s   %d班  %s   %d         %d\n", q->name, q->num, q->cla, q->course, q->oidGrades, q->newGrades);
			}
			while (1)
			{
				choice[0] = '\0';
				printf("\n是否同意首位同学的申诉请求（Y/N）\n");
				printf("(输入0返回)");
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
					Link_comp_destroy(chead);
					return;
				}
				else if (choice[0] == 'Y' || choice[0] == 'y')
				{
					p = chead->next;
					//查找该学生
					cla = (char)(p->cla + '0');
					shead = Find_class(cla);
					stu = Find_num(shead, p->num);
					//更新成绩
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
							printf("程序运行出错，结束程序运行\n");
							exit(0);
						}
					}
					//保存
					Link_save(shead, p->cla);
					//释放内存
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
					printf("操作成功\n");
					system("pause");
					break;
				}
				else
				{
					system("cls");
					printf("请重新操作\n");
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
		printf("(输入exit 返回)\n");
		printf("请输入新成绩文件路径：");

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

		fp = fopen(filename, "r");
		if (fp == NULL)
		{
			system("cls");
			printf("文件打开失败！");
			system("pause");
		}

		else
		{
			//读取新成绩文件
			shead = Link_create(fp);
			fclose(fp);
			while (1)
			{
				//更新成绩
				system("cls");
				printf("==============================================================\n");
				printf("--------------------------------------------------------------\n");
				printf("选择更新班级(1~5)(0返回操作界面)\n");
				scanf("%s", choice);
				rewind(stdin);

				if (strlen(choice) > 1)
				{
					system("cls");
					printf("请重新操作");
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
					printf("请重新操作");
					system("pause");
				}
			}
			system("cls");
			printf("更新成功");
			system("pause");
			break;
		}
	}
}

//管理员权限
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
		printf("姓名      账号       是否拥有管理员权限\n");
		for (p = thead->next; p != NULL && p->next != NULL; p = p->next)
		{
			printf("%s     %s            ", p->name, p->num);
			if (p->adm == 'O' || p->adm == 'M')
			{
				printf("拥有\n");
			}
			else
			{
				printf("没有\n");
			}
		}
		printf("\n(输入exit返回)\n");
		printf("输入您想管理的账号或姓名：");

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
			printf("账号或姓名过长，请重新输入\n");
			system("pause");
		}
		//查找教师
		else
		{
			tea = tea_allfind(thead, n);
			if (tea == NULL)
			{
				system("cls");
				printf("未查找到该教师，请重新操作\n");
				system("pause");
			}
			else
			{
				if (tea->adm == 'M')
				{
					system("cls");
					printf("您不能对校长进行此操作！\n");
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
						printf("姓名：%s  班级：%s  拥有权限\n", tea->name, tea->cla);
						printf("\n输入N取消该教师管理员权限    输入E返回:");
						scanf("%s", choice);
						rewind(stdin);
						if (strlen(choice) > 1)
						{
							system("cls");
							printf("操作失败，请重新尝试！\n");
							system("pause");
						}
						else if (choice[0] == 'N' || choice[0] == 'n')
						{
							tea->adm = 'I';
							tea_acc_save(thead);
							system("cls");
							printf("操作成功！\n");
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
							printf("操作失败，请重新尝试！\n");
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
						printf("姓名：%s  班级：%s  没有权限\n", tea->name, tea->cla);
						printf("\n输入Y给与该教师管理员权限    输入E返回:");
						scanf("%s", choice);
						rewind(stdin);
						if (strlen(choice) > 1)
						{
							system("cls");
							printf("操作失败，请重新尝试！\n");
							system("pause");
						}
						else if (choice[0] == 'Y' || choice[0] == 'y')
						{
							tea->adm = 'O';
							tea_acc_save(thead);
							system("cls");
							printf("操作成功！\n");
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
							printf("操作失败，请重新尝试！\n");
							system("pause");
						}
					}
				}
			}
		}
	}
}

//管理员进入教师端
void adm_To_tea(Teanode *tea, Teanode *teahead)
{
	char cla[1000];
	int k;
	Node *shead;
	while (1)
	{
		cla[0] = '\0';
		//选择班级
		system("cls");
		Face_class();

		scanf("%s", cla);
		rewind(stdin);
		if (strlen(cla) > 1)
		{
			system("cls");
			printf("请重新操作！\n");
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
				printf("程序运行出错，停止运行\n");
				exit(1);
			}
			else
			{
				//进入教师端
				k = (int)(cla[0] - '0');
				admTotea_inoperate(shead, k, tea, teahead);
				Link_destroy(shead);
				break;
			}
		}
		else
		{
			system("cls");
			printf("请重新操作！\n");
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
		printf("-------------请要添加的教师的班级-----\n");
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
		printf("--------------0.返回------------------\n");
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
			printf("请重新操作\n");
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
		printf("(输入exit返回)");
		printf("请输入你要修改的账户的账号或姓名：");

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
			printf("请重新操作\n");
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
			printf("请重新操作\n");
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
				printf("姓名     账号     班级   \n");
				printf("%s   %s   %s", tea->name, tea->num, tea->cla);
				printf("\n请选择您要修改的项：\n");
				printf("1.姓名  2.账号  3.班级  0.返回\n");
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
						printf("请重新操作\n");
						system("pause");
						break;
					}
					}
				}
			}
		}
	}
}

//修改教师账户姓名
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
		printf("(输入exit返回)");
		printf("请输入新姓名：");

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
			printf("请重新操作\n");
			system("pause");
		}

		else if (strcmp(name, "exit") == 0)
		{
			break;
		}
		else if (judg_Chinese(name) == 0)
		{
			system("cls");
			printf("请输入正确的姓名\n");
			system("pause");
		}
		else
		{
			strcpy(tea->name, name);
			tea_acc_save(thead);
			system("cls");
			printf("修改成功！\n");
			system("pause");
			break;
		}
	}
}

//修改教师账号
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
		printf("(输入exit返回)");
		printf("请输入新账号：");

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
			printf("请重新操作\n");
			system("pause");
		}

		if (strcmp(num, "exit") == 0)
		{
			break;
		}
		else if (judg_repeat_tea(thead, num))
		{
			system("cls");
			printf("账号重复，请重新选择\n");
			system("pause");
		}
		else if (judg_Chinese(num) == 1)
		{
			system("cls");
			printf("不能以汉字做账号！\n");
			system("pause");
		}
		else
		{
			strcpy(tea->num, num);
			tea_acc_save(thead);
			system("cls");
			printf("修改成功！\n");
			system("pause");
			break;
		}
	}
}

//修改教师班级
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
			printf("修改成功！\n");
			system("pause");
			break;
		}
		else
		{
			system("cls");
			printf("请重新操作\n");
			system("pause");
		}
	}
}


//删除账户
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
		printf("(输入exit返回)");
		printf("请输入你要删除的账户的账号或姓名：");

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
			printf("请重新操作\n");
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
			printf("请重新操作\n");
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
			printf("删除成功！\n");
			system("pause");
			break;
		}
	}
}

//查找账户
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
		printf("(输入exit返回)");
		printf("请输入你要查找的账户的账号或姓名：");

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
			printf("请重新操作\n");
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
			printf("请重新操作\n");
			system("pause");
		}
		else
		{
			system("cls");
			printf("==============================================================\n");
			printf("--------------------------------------------------------------\n");
			printf("该账户信息如下:\n");
			printf("姓名：%s  账号：%s   班级：%s\n", tea->name, tea->num, tea->cla);
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
//	printf("请输入信息(在姓名输入end结束)：\n");
//	printf("姓名     账号     密码    班级     管理员权限\n");
//	while (1)
//	{
//		p = (Teanode*)malloc(sizeof(Teanode));
//		//输入姓名
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
//				printf("请重新操作\n");
//				system("pause");
//				system("cls");
//				printf("==============================================================\n");
//				printf("--------------------------------------------------------------\n");
//				printf("请输入信息(在姓名输入end结束)：\n");
//				printf("姓名     账号     密码    班级     管理员权限\n");
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
//		//结束录入
//		if (strcmp(n, "end") == 0)
//		{
//			break;
//		}
//		//输入账号
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
//				printf("请重新操作\n");
//				system("pause");
//				system("cls");
//				printf("==============================================================\n");
//				printf("--------------------------------------------------------------\n");
//				printf("请输入信息(在姓名输入end结束)：\n");
//				printf("姓名     账号     密码    班级     管理员权限\n");
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
//		//输入密码
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
//				printf("请重新操作\n");
//				system("pause");
//				system("cls");
//				printf("==============================================================\n");
//				printf("--------------------------------------------------------------\n");
//				printf("请输入信息(在姓名输入end结束)：\n");
//				printf("姓名     账号     密码    班级     管理员权限\n");
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
//		//输入班级
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
//			//固定班级形式
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
//				printf("请重新操作\n");
//				system("pause");
//				system("cls");
//				printf("==============================================================\n");
//				printf("--------------------------------------------------------------\n");
//				printf("请输入信息(在姓名输入end结束)：\n");
//				printf("姓名     账号     密码    班级     管理员权限\n");
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
//		//管理员权限
//		while (1)
//		{
//			scanf("%c", &ch);
//
//			if (ch != 'M' && ch != 'O' && ch != 'I')
//			{
//				system("cls");
//				printf("请重新操作\n");
//				system("pause");
//				system("cls");
//				printf("==============================================================\n");
//				printf("--------------------------------------------------------------\n");
//				printf("请输入信息(在姓名输入end结束)：\n");
//				printf("姓名     账号     密码    班级     管理员权限\n");
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
//				printf("请输入信息(在姓名输入end结束)：\n");
//				printf("姓名     账号     密码    班级     管理员权限\n");
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
//	printf("录入完成");
//	system("pause");
//	return thead;
//}

