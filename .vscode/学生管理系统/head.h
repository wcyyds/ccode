#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<Windows.h>
#define CL1 "D:\\vs 2019\\C语言 文件操作练习\\学生管理系统21届\\学生信息\\class1的副本.txt"
#define CL2 "D:\\vs 2019\\C语言 文件操作练习\\学生管理系统21届\\学生信息\\class2的副本.txt"
#define CL3 "D:\\vs 2019\\C语言 文件操作练习\\学生管理系统21届\\学生信息\\class3的副本.txt"
#define CL4 "D:\\vs 2019\\C语言 文件操作练习\\学生管理系统21届\\学生信息\\class4的副本.txt"
#define CL5 "D:\\vs 2019\\C语言 文件操作练习\\学生管理系统21届\\学生信息\\class5的副本.txt"
#define shensu "D:\\vs 2019\\C语言 文件操作练习\\学生管理系统21届\\管理员\\申诉名单.txt"
#define Teaacc "D:\\vs 2019\\C语言 文件操作练习\\学生管理系统21届\\管理员\\教师账户.txt"
#define TeaRemind "D:\\vs 2019\\C语言 文件操作练习\\学生管理系统21届\\管理员\\教师提醒名单.txt"

extern int WD;

typedef struct node
{
	char name[100];
	char num[7];
	char classname[100];
	int Chinese_grades;
	int Math_grades;
	int English_grades;
	char password[200];
	struct node *next;
}Node;

typedef struct teanode
{
	char name[20];
	char num[13];
	char password[200];
	char cla[100];
	char adm;
	struct teanode *next;
}Teanode;

typedef struct complaint
{
	char name[20];
	char num[13];
	int cla;
	char course[15];
	int oidGrades;
	int newGrades;
	struct complaint *next;
}Comp;

int read();

void main_face();

void stu_face();

Node* Link_create(FILE *fp);

Node* Find_num(Node *head, char num[6]);

void stu_operate(Node *head, Node *stu, int cla);

void stu_operate_face();

void Face_class();

Node *Find_class(char choice);

void print_class_grades(Node *head);

void stu_login();

void stu_inlog(Node *head, int cla);

void stu_analyse(Node *stu, Node *head);

void stu_pass_back(Node *head);

void Link_destroy(Node *head);

void Link_save(Node *head, int cla);

void stu_pass_change(Node *head, Node *stu, int cla);

void tea_face();

Teanode *tea_account();

void Link_tea_destroy(Teanode *head);

void tea_acc_save(Teanode *head);

void tea_acc_enroll(int cla, Teanode *acchead);

void tea_operate();

Teanode *Find_tea(Teanode *head, char num[13]);

void tea_login(Teanode *head, Node *clahead, int cla);

void tea_inoperate(Node *clahead, int cla, Teanode *tea, Teanode *teahead);

void tea_oper_face();

void stu_increase(Node *head, int cla);

Node* Find_name(Node *head, char name[20]);

Node *stu_allfind(Node *head);

void stu_del(Node *head, int cla);

void tea_oper_revise(Node *stu);

void stu_revise(Node *head, int cla);

void tea_save_loc(Node *head);

void tea_grades_anlayse(Node *head);

void adm_face();

void stu_sort_up(Node *head);

void stu_sort_down(Node *head);

int stu_compare(Node *stu1, Node *stu2);

void adm_operate(Teanode *teahead, Teanode *tea);

void adm_face();

void adm_login();

void adm_agent_face();

void tea_password_change(Teanode *head, Teanode *tea);

Teanode *Find_tea_name(Teanode *head, char name[13]);

Teanode *tea_allfind(Teanode *head, char n[13]);

void tea_passback(Teanode *head);

Comp *stu_Compcreate();

void stuComp_save(Comp *head);

void Link_comp_destroy(Comp *head);

void stu_complaint(Node *stu, int cla);

Teanode *tea_Remind();

void tea_remind_save(Teanode *head);

void adm_rewind();

void adm_GradesComp();

void admUp_grades();

void managerRoot(Teanode *thead);

void adm_agent(Teanode *head, Teanode *manager);

void adm_To_tea(Teanode *tea, Teanode *teahead);

void teaIncrease(Teanode *thead);

void adm_change_name(Teanode *tea, Teanode *thead);

void adm_change_num(Teanode *tea, Teanode *thead);

void adm_change_class(Teanode *tea, Teanode *thead);

void adm_change_password(Teanode *tea, Teanode *thead);

void adm_change(Teanode *thead);

void teaDelete(Teanode *thead);

void tea_findWord(Teanode *thead);

//Teanode *tea_input();

int judg_Chinese(char *s);

int judg_repeat_tea(Teanode *thead, char *num);

int judg_repeat_stu(Node *shead, char *num);

void adm_to_face();

void admTotea_inoperate(Node *clahead, int cla, Teanode *tea, Teanode *teahead);