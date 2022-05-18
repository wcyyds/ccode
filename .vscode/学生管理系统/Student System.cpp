#include"head.h"

int WD = 0;

int main()
{
	char choice[3];
	char ch;
	int i;

	while (1)
	{
		choice[0] = '\0';
		system("cls");
		main_face();
		for (i = 0; i < 2; i++)
		{
			scanf("%c", &ch);
			if (ch == '\n')
			{
				break;
			}
			choice[i] = ch;
		}

		rewind(stdin);
		if (choice[0] == '0')
		{
			break;
		}
		if (i > 1)
		{
			system("cls");
			printf("输入出错，按任意键重新输入！\n");
			system("pause");
		}
		else
		{
			switch (choice[0])
			{
			case '1':
			{
				system("cls");
				stu_login();
				break;
			}
			case '2':
			{
				system("cls");
				tea_operate();
				break;
			}
			case '3':
			{
				system("cls");
				adm_login();
				break;
			}
			default:
			{
				system("cls");
				printf("输入出错，按任意键重新输入！\n");
				system("pause");
				break;
			}
			}
		}
	}
	return 0;
}