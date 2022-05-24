#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
typedef struct Student
{
    char stu_acc[20];
    char name[20];
    int mathgrade;
    char stu_pass[20];
    char class[20];
    struct Student *next;
} student;

typedef struct Teacherinformation
{
    char account[20];
    char password[20];
    struct Teacherinformation *next;
} teacher;

void creatfile();                                                                          //检查创建文件
void scanffile1(teacher *head1);                                                           //第一次从老师账号文件读写函数，直接写入链表中去
void teacherland(teacher *head1, student *head, student *p, teacher *b);                   //教师登录函数
void studentland(student *head);                                                           //学生登录函数
void adminlan(teacher *head1, student *head, student *p, teacher *b);                      //管理员登录函数
void printlist2(teacher *head1);                                                           //表达所有教师信息
student *inithead();                                                                       //创造学生头结点
teacher *inithead1();                                                                      //创造教师的头结点
void creatlist(student *head);                                                             // 1.增加学生信息
void creatlist1(teacher *head1);                                                           // 1.增加教师信息
void deletelist(student *p, student *head);                                                // 2.删除学生信息
void deletelist1(teacher *b, teacher *head1);                                              // 2.删除教师信息
void correctlist(student *p, student *head);                                               // 3.修改学生信息
void correctlist1(teacher *b, teacher *head1);                                             // 3.修改教师信息
void creatclass(student *head, char *class);                                               // 1.教师增加学生信息
student *findlist(student *head);                                                          // 4.查询学生信息,返回的是要查询的上一个的结点
teacher *findlist1(teacher *head1);                                                        // 4.查询教师信息，返回的是要查询的上一个节点
student *printlist(student *head);                                                         // 5.查询所有学生信息
teacher *printlist1(teacher *head1);                                                       // 5.查询所有教师信息
student *printclass(student *head, char *class);                                           // 5.教师查看班级所有学生
student *sortlist(student *head);                                                          // 6.排序所有学生的数学成绩
student *sortclass(student *head, char *class);                                            // 6.教师排序本班学生的数学成绩
void updatefile(student *head);                                                            //更新文件函数！
void updatefile1(teacher *head1);                                                          //更新老师文件函数
void scanffile(student *head);                                                             //第一次从文件读写函数，直接写入链表中去
void tea_face();                                                                           //教师端登录界面
void stu_face();                                                                           //学生端登录界面
void admin_face();                                                                         //管理员登录界面
void adminstu_face();                                                                      //管理员学生端登录界面
void admintea_face();                                                                      //管理员教师端登录界面
void facemain();                                                                           //端口登录选择
void main_UI(teacher *head1, student *head, student *p, teacher *b);                       //主界面循环
void studentUI(student *head, student *q);                                                 //学生端循环
void teacherUI(student *head, student *p, teacher *head1, teacher *b);                     //教师端循环
void adminUI(student *head, student *p, teacher *head1, teacher *b);                       //管理员循环
void adminUIone(teacher *head1, teacher *b);                                               //管理员教师端循环
void adminUItwo(student *head, student *p, teacher *head1);                                //管理员学生端循环
void chongzhumima(student *head, student *q);                                              //重置学生密码函数
student *findclass(student *head, student *p, teacher *head1, teacher *b, char *teaclass); //确认查找班级函数

student *sorlist5(student *head);

void creatfile() //检查创建文件
{
    FILE *fp;
    if ((fp = fopen("student.txt", "r")) == NULL)
    {
        printf("学生配置信息错误，没有找到指定文件\n");
        printf("创建新文件");
        fp = fopen("student.txt", "w");
    }
    if ((fp = fopen("teacherinfor.txt", "r")) == NULL)
    {
        printf("教师配置信息错误，没有找到指定文件\n");
        printf("创建新文件");
        fp = fopen("teacherinfor.txt", "w");
    }
    printf("创建文件成功，配置用户信息完成\n");
    Sleep(1000);
    system("cls");
    fflush(stdin);
    fclose(fp);
}

void scanffile1(teacher *head1) //第一次从老师账号文件读写函数，直接写入链表中去
{

    FILE *fp;
    int n = 0;
    if ((fp = fopen("teacherinfor.txt", "r")) == NULL)
    {
        printf("EROOR打开错误");
        exit(0);
    }
    teacher *q = head1;
    teacher *p = head1;
    teacher *newhead1 = (teacher *)malloc(sizeof(teacher));
    p->next = newhead1;
    newhead1->next = NULL;
    while (fscanf(fp, "%s %s\n", newhead1->account, newhead1->password) != EOF)
    {
        q = q->next;
        teacher *newhead = (teacher *)malloc(sizeof(teacher));
        newhead->next = NULL;
        newhead1->next = newhead;
        newhead1 = newhead1->next;
        n++;
    }
    q->next = NULL;
    fclose(fp);
}

void teacherland(teacher *head1, student *head, student *p, teacher *b) //教师登录函数
{
    teacher *q = head1->next;
    int n;
    char tea_account[20];
    char tea_password[20];
    printf("请输入你的教师账号\n");
    scanf("%s", tea_account);
    while (q)
    {
        if (strcmp(q->account, tea_account) == 0)
        {
            printf("输入成功，有该账号，你有三次输入的机会\n");
            for (n = 3; n >= 0; n--)
            {
                if (n == 0)
                {
                    printf("你的使用次数使用完毕，请重新登录\n");
                    system("pause");
                    teacherland(head1, head, p, b);
                    system("cls");
                    fflush(stdin);
                }
                printf("请输入密码，你有%d次机会。\n", n);
                scanf("%s", &tea_password);
                if (strcmp(q->password, tea_password) == 0)
                {
                    printf("输入正确，进入管理系统\n");
                    system("cls");
                    fflush(stdin);
                    teacherUI(head, p, head1, b);
                }
            }
        }
        q = q->next;
    }
    printf("没有该账号，请重新输入");
    system("pause");
    system("cls");
    fflush(stdin);
    teacherland(head1, head, p, b);
}

void studentland(student *head) //学生登录函数
{
    student *q = head->next;
    int n;
    char stu_account[20];
    char stu_password[20];
    printf("请输入你的学号\n");
    scanf("%s", stu_account);
    while (q)
    {
        if (strcmp(q->stu_acc, stu_account) == 0)
        {
            printf("输入成功，有该账号，你有三次输入的机会\n");
            for (n = 3; n >= 0; n--)
            {
                if (n == 0)
                {
                    printf("你的使用次数使用完毕，请重新登录\n");
                    system("pause");
                    studentland(head);
                    system("cls");
                    fflush(stdin);
                }
                printf("请输入密码，你有%d次机会。\n", n);
                scanf("%s", stu_password);
                if (strcmp(q->stu_pass, stu_password) == 0)
                {
                    printf("输入正确，进入学生系统\n");
                    system("pause");
                    system("cls");
                    fflush(stdin);
                    studentUI(head, q);
                }
            }
        }

        q = q->next;
    }
    printf("没有该账号，请重新输入");
    system("pause");
    system("cls");
    fflush(stdin);
    studentland(head);
}

void adminlan(teacher *head1, student *head, student *p, teacher *b) //管理员登录函数
{
    printf("请输入管理员验证码\n");
    char yanzhengma[20];
    scanf("%s", yanzhengma);
    int choice;
    if (strcmp(yanzhengma, "3gniubi") == 0)
    {
        printf("管理员验证码正确，进入学生管理系统\n");
        system("cls");
        fflush(stdin);
        adminUI(head, p, head1, b);
    }
    else
    {
        printf("输入管理员验证码错误，请选择\n");
        printf("======================================\n");
        printf("--------------------------------------\n");
        printf("--------------1.重新输入--------------\n");
        printf("--------------------------------------\n");
        printf("--------------2.返回上一级-------------\n");
        printf("--------------------------------------\n");
        printf("--------------0.关闭文件--------------\n");
        printf("--------------------------------------\n");
        printf("======================================\n");
        printf("请输入0到2：   ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            adminlan(head1, head, p, b);
            break;
        case 2:
            main_UI(head1, head, p, b);
            break;
        }
        system("pause");
        system("cls");
        fflush(stdin);
    }
}

void printlist2(teacher *head1) //表达所有教师信息
{
    teacher *p = head1->next;
    printf("现在的教师信息:账号  密码\n");
    while (p)
    {
        printf("%s %s\n", p->account, p->password);
        p = p->next;
    }
    printf("所有教师表达成功");
    system("pause");
}

student *inithead() //创造学生头结点
{
    student *head = NULL;
    head = (student *)malloc(sizeof(student));
    head->next = NULL;
}

teacher *inithead1() //创造教师的头结点
{
    teacher *head1 = NULL;
    head1 = (teacher *)malloc(sizeof(teacher));
    head1->next = NULL;
}

void creatlist(student *head) // 1.增加学生信息
{
    char account[20];
    char name[20];
    int mathgrade;
    char class[20];
    printf("请输入学生的信息：学号 姓名 数学成绩   班级\n");
    scanf("%s %s %d %s", account, name, &mathgrade, class);
    student *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    student *newhead = (student *)malloc(sizeof(student));
    newhead->next = NULL;
    strcpy(newhead->stu_acc, account);
    strcpy(newhead->name, name);
    newhead->mathgrade = mathgrade;
    strcpy(newhead->class, class);
    strcpy(newhead->stu_pass, "123456");
    p->next = newhead;
    printf("录入成功\n");
    updatefile(head);
    system("pause");
}

void creatlist1(teacher *head1) // 1.增加教师信息
{
    char tea_acc[20];
    char tea_pass[20];
    printf("请输入教师的信息：账号      密码\n");
    scanf("%s %s", tea_acc, tea_pass);
    teacher *p = head1;
    while (p->next != NULL)
    {
        p = p->next;
    }
    teacher *newhead = (teacher *)malloc(sizeof(teacher));
    newhead->next = NULL;
    strcpy(newhead->account, tea_acc);
    strcpy(newhead->password, tea_pass);
    p->next = newhead;
    printf("录入成功\n");
    updatefile1(head1);
    system("pause");
}

void creatclass(student *head, char *class) // 1.教师增加学生信息
{
    char account[20];
    char name[20];
    int mathgrade;
    printf("请输入学生的信息：学号 姓名 数学成绩\n");
    scanf("%s %s %d", account, name, &mathgrade);
    student *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    student *newhead = (student *)malloc(sizeof(student));
    newhead->next = NULL;
    strcpy(newhead->stu_acc, account);
    strcpy(newhead->name, name);
    newhead->mathgrade = mathgrade;
    strcpy(newhead->class, class);
    strcpy(newhead->stu_pass, "123456");
    p->next = newhead;
    printf("录入成功\n");
    updatefile(head);
    system("pause");
}

void deletelist(student *p, student *head) // 2.删除学生信息
{
    p->next = p->next->next;
    printf("删除成功\n");
    updatefile(head);
    system("pause");
}

void deletelist1(teacher *b, teacher *head1) // 2.删除教师信息
{
    b->next = b->next->next;
    printf("删除成功\n");
    updatefile1(head1);
    system("pause");
}

void correctlist(student *p, student *head) // 3.修改学生信息
{
    p = p->next;
    printf("现在的学生信息\n");
    printf("学号    姓名     数学成绩    登录密码   班级\n");
    printf("%s %s %d %s %s", p->stu_acc, p->name, p->mathgrade, p->stu_pass, p->class);
    printf("\n输入修改后的学生信息\n");
    printf("学号    姓名     数学成绩    登录密码   班级\n");
    scanf("%s %s %d %s %s", p->stu_acc, p->name, &p->mathgrade, p->stu_pass, p->class);
    printf("修改成功\n");
    updatefile(head);
    system("pause");
}

void correctlist1(teacher *b, teacher *head1) // 3.修改教师信息
{
    b = b->next;
    printf("现在的教师信息\n");
    printf("%s %s", b->account, b->password);
    printf("输入修改后的教师信息\n");
    scanf("%s %s", b->account, b->password);
    printf("修改成功\n");
    updatefile1(head1);
    system("pause");
}

student *findlist(student *head) // 4.查询学生信息,返回的是要查询的上一个的结点
{
    printf("请输入需要查找的学生学号\n");
    char account[20];
    scanf("%s", account);
    student *p = head->next;
    student *q = head;
    while (p)
    {
        if (strcmp(p->stu_acc, account) == 0)
        {
            printf("查找成功\n");
            printf("%s %s %d\n", p->stu_acc, p->name, p->mathgrade);
            system("pause");
            return q;
        }
        p = p->next;
        q = q->next;
    }
    int choice;
    printf("没有找到该学生,请选择\n");
    printf("----------------1.重新输入------------\n");
    printf("--------------------------------------\n");
    printf("----------------2.返回上一级------------\n");

    while (1)
    {
        scanf("%d", &choice);
        if (choice == 1)
        {
            findlist(head);
            break;
        }
        else if (choice == 2)
        {
            return 0;
        }
        else
        {
            printf("输入错误，请重新输入");
        }
        system("cls");
        fflush(stdin);
    }
}

teacher *findlist1(teacher *head1) // 4.查询教师信息,返回的是要查询的上一个的结点
{
    printf("请输入需要查找的教师账号\n");
    char account[20];
    scanf("%s", account);
    teacher *p = head1->next;
    teacher *q = head1;
    while (p)
    {
        if (strcmp(p->account, account) == 0)
        {
            printf("查找成功\n");
            printf("%s %s\n", p->account, p->password);
            system("pause");
            return q;
        }
        p = p->next;
        q = q->next;
    }
    int choice;
    printf("没有找到该教师,请选择\n");
    printf("----------------1.重新输入------------\n");
    printf("-------------------------------------\n");
    printf("----------------2.返回上一级----------\n");

    while (1)
    {
        scanf("%d", &choice);
        if (choice == 1)
        {
            findlist1(head1);
            break;
        }
        else if (choice == 2)
        {
            return 0;
        }
        else
        {
            printf("输入错误，请重新输入");
        }
        system("cls");
        fflush(stdin);
    }
}

student *findclass(student *head, student *p, teacher *head1, teacher *b, char *teaclass) // 4.教师查询学生信息，返回的是要查询的上一个节点
{
    printf("请输入需要查找的学生学号\n");
    char account[20];
    scanf("%s", account);
    student *m = head->next;
    student *q = head;
    while (m)
    {
        if (strcmp(m->stu_acc, account) == 0)
        {
            printf("查找成功\n");
            if (strcmp(m->class, teaclass) == 0)
            {
                printf("%s %s %d\n", m->stu_acc, m->name, m->mathgrade);
                system("pause");
                return q;
            }
            else
            {
                printf("你正在查找其他班级学生，无权操作，请重新输入\n");
                teacherUI(head, p, head1, b);
            }
        }
        m = m->next;
        q = q->next;
    }
    int choice = 10;
    printf("没有找到该学生,请选择\n");
    printf("----------------1.重新输入------------\n");
    printf("--------------------------------------\n");
    printf("----------------2.返回上一级------------\n");

    while (1)
    {
        scanf("%d", &choice);
        if (choice == 1)
        {
            findclass(head, p, head1, b, teaclass);
            break;
        }
        else if (choice == 2)
        {
            teacherUI(head, p, head1, b);
        }

        system("cls");
        fflush(stdin);
    }
}

student *printlist(student *head) // 5.查询所有学生信息
{
    if (head->next == NULL)
    {
        printf("还没有学生信息，请先录入学生信息\n");
        system("pause");
        return 0;
    }
    student *q = head->next;
    printf("现在的学生信息:\n学号        姓名          数学成绩    班级\n");
    while (q)
    {
        printf("%8s %10s %12d %10s\n", q->stu_acc, q->name, q->mathgrade, q->class);
        q = q->next;
    }
    printf("所有学生表达成功");
    system("pause");
}

teacher *printlist1(teacher *head1) // 5.查询所有教师信息
{
    if (head1->next == NULL)
    {
        printf("还没有教师信息，请先录入教师信息");
        system("pause");
        return 0;
    }
    teacher *q = head1->next;
    printf("现在的教师信息:\n账号       密码\n");
    while (q)
    {
        printf("%8s %10s\n", q->account, q->password);
        q = q->next;
    }
    printf("所有学生表达成功");
    system("pause");
}

student *printclass(student *head, char *class) // 5.教师查看班级所有学生
{
    if (head->next == NULL)
    {
        printf("还没有学生信息，请先录入学生信息\n");
        system("pause");
        return 0;
    }
    student *q = head->next;
    printf("现在的学生信息:\n学号        姓名          数学成绩    班级\n");
    while (q)
    {
        if (strcmp(q->class, class) == 0)
        {
            printf("%8s %10s %12d %10s\n", q->stu_acc, q->name, q->mathgrade, q->class);
            q = q->next;
        }
        else
        {
            q = q->next;
        }
    }
    printf("所有学生表达成功");
    system("pause");
}

student *sortlist(student *head) // 6.排序所有学生的数学成绩
{
    student *dummpy = (student *)malloc(sizeof(student));
    dummpy->next = NULL;
    dummpy->mathgrade = 0;
    head->mathgrade = 0;
    student *work = dummpy;
    while (head)
    {
        student *temp = head->next;
        work = dummpy;
        while (work->next && work->next->mathgrade < head->mathgrade)
        {
            work = work->next;
        }
        head->next = work->next;
        work->next = head;
        head = temp;
    }
    student *p = dummpy;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    p->next = NULL;
    return dummpy;
}

student *sorlist5(student *head)
{
    student *p = head->next;
    student *pre;
    student *r = p->next;
    p->next = NULL;
    p = r;
    while(p)
    {
        r = p->next;
        pre = head;
        while(pre->next && pre->next->mathgrade < p->mathgrade)
        {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
    return head;
}

void updatefile(student *head) //更新文件函数！
{
    FILE *fp;
    if ((fp = fopen("student.txt", " w")) == NULL)
    {
        printf("EROOR打开错误");
        exit(0);
    }
    student *p = head->next;
    while (p)
    {
        fprintf(fp, "%s %s %d %s %s\n", p->stu_acc, p->name, p->mathgrade, p->stu_pass, p->class);
        p = p->next;
    }
    printf("文件更新成功\n");
    fclose(fp);
}

void updatefile1(teacher *head1) //更新老师文件函数
{
    FILE *fp;
    if ((fp = fopen("teacherinfor.txt", " w")) == NULL)
    {
        printf("EROOR打开错误");
        exit(0);
    }
    teacher *p = head1->next;
    while (p)
    {
        fprintf(fp, "%s %s\n", p->account, p->password);
        p = p->next;
    }
    printf("文件更新成功\n");
    fclose(fp);
}

void scanffile(student *head) //第一次从文件读写函数，直接写入链表中去
{
    FILE *fp;
    if ((fp = fopen("student.txt", "r")) == NULL)
    {
        printf("EROOR打开错误");
        exit(0);
    }
    student *q = head;
    student *p = head;
    student *newhead1 = (student *)malloc(sizeof(student));
    p->next = newhead1;
    newhead1->next = NULL;
    while (fscanf(fp, "%s %s %d %s %s", newhead1->stu_acc, newhead1->name, &newhead1->mathgrade, newhead1->stu_pass, newhead1->class) != EOF)
    {
        q = q->next;
        student *newhead = (student *)malloc(sizeof(student));
        newhead->next = NULL;
        newhead1->next = newhead;
        newhead1 = newhead1->next;
    }
    q->next = NULL;
    fclose(fp);
}

void tea_face() //教师端登录界面
{
    printf("======================================\n");
    printf("--------------------------------------\n");
    printf("----------------1.增加学生信息------------\n");
    printf("--------------------------------------\n");
    printf("----------------2.删除学生信息------------\n");
    printf("--------------------------------------\n");
    printf("----------------3.修改学生信息----------\n");
    printf("--------------------------------------\n");
    printf("----------------4.查询学生信息----------\n");
    printf("--------------------------------------\n");
    printf("----------------5.查询所有学生信息----------\n");
    printf("--------------------------------------\n");
    printf("----------------6.排序本班学生的数学成绩----------\n");
    printf("--------------------------------------\n");
    printf("----------------7.退出登录----------\n");
    printf("--------------------------------------\n");
    printf("----------------0.退出文件----------\n");
    printf("======================================\n");
    printf("请输入0到7：    ");
}

void stu_face() //学生端登录界面
{
    printf("======================================\n");
    printf("--------------------------------------\n");
    printf("--------------1.查询信息--------------\n");
    printf("--------------------------------------\n");
    printf("--------------2.修改密码--------------\n");
    printf("--------------------------------------\n");
    printf("--------------0.关闭文件--------------\n");
    printf("--------------------------------------\n");
    printf("======================================\n");
    printf("请输入0到2：   ");
}

void admin_face() //管理员登录界面
{
    printf("======================================\n");
    printf("--------------------------------------\n");
    printf("--------------1.教师管理--------------\n");
    printf("--------------------------------------\n");
    printf("--------------2.学生管理--------------\n");
    printf("--------------------------------------\n");
    printf("--------------0.关闭文件--------------\n");
    printf("--------------------------------------\n");
    printf("======================================\n");
    printf("请输入0到2：   ");
}

void adminstu_face() //管理员学生端登录界面
{
    printf("========================================\n");
    printf("----------------------------------------\n");
    printf("----------------1.增加学生信息-----------\n");
    printf("----------------------------------------\n");
    printf("----------------2.删除学生信息-----------\n");
    printf("----------------------------------------\n");
    printf("----------------3.修改学生信息-----------\n");
    printf("----------------------------------------\n");
    printf("----------------4.查询学生信息-----------\n");
    printf("----------------------------------------\n");
    printf("----------------5.查询所有学生信息--------\n");
    printf("----------------------------------------\n");
    printf("----------------6.排序所有学生的数学成绩----------\n");
    printf("--------------------------------------\n");
    printf("----------------0.退出文件--------------\n");
    printf("========================================\n");
    printf("请输入0到5：    ");
}

void admintea_face() //管理员教师端登录界面
{
    printf("======================================\n");
    printf("---------------------------------------\n");
    printf("----------------1.增加教师信息----------\n");
    printf("---------------------------------------\n");
    printf("----------------2.删除教师信息----------\n");
    printf("---------------------------------------\n");
    printf("----------------3.修改教师信息----------\n");
    printf("---------------------------------------\n");
    printf("----------------4.查询教师信息-----------\n");
    printf("----------------------------------------\n");
    printf("----------------5.查询所有教师信息-------\n");
    printf("----------------------------------------\n");
    printf("----------------0.退出文件--------------\n");
    printf("=======================================\n");
    printf("请输入0到5：    ");
}

void facemain() //端口登录选择
{
    printf("======================================\n");
    printf("--------------------------------------\n");
    printf("--------------1.学生登录--------------\n");
    printf("--------------------------------------\n");
    printf("--------------2.教师登录--------------\n");
    printf("--------------------------------------\n");
    printf("--------------3.管理员登录--------------\n");
    printf("--------------------------------------\n");
    printf("--------------0.关闭文件--------------\n");
    printf("--------------------------------------\n");
    printf("======================================\n");
    printf("请输入0到3：   ");
}

void main_UI(teacher *head1, student *head, student *p, teacher *b) //主界面循环
{

    while (1)
    {
        facemain();
        int choice = 100;
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
        case 2:
            teacherland(head1, head, p, b);
            break;
        case 1:
            studentland(head);
            break;
        case 3:
            adminlan(head1, head, p, b);
            break;
        }
        system("cls");
        fflush(stdin);
    }
}

void studentUI(student *head, student *q) //学生端循环
{
    while (1)
    {
        stu_face();
        int choice = 100;
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            printf("现在的学生信息:\n学号           姓名        数学成绩\n");
            printf("%8s %10s %12d\n", q->stu_acc, q->name, q->mathgrade);
            system("pause");
            break;
        case 2:
            chongzhumima(head, q);
            break;
        }
        system("cls");
        fflush(stdin);
    }
}

void teacherUI(student *head, student *p, teacher *head1, teacher *b) //教师端循环
{
    printf("请输入你要选择的班级\n");
    char class[20] = {"0"};
    scanf("%s", class);
    student *newhead = NULL;
    while (1)
    {
        tea_face();
        int choice = 100;
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            creatclass(head, class);
            break;
        case 2:
            p = findclass(head, p, head1, b, class);
            deletelist(p, head);
            break;
        case 3:
            p = findclass(head, p, head1, b, class);
            correctlist(p, head);
            break;
        case 4:
            p = findclass(head, p, head1, b, class);
            break;
        case 5:
            printf("要重新改一下");
            printclass(head, class);
            break;
        case 6:
            newhead = sortclass(head, class);
            printlist(newhead);
            break;
        case 7:
            main_UI(head1, head, p, b);
            break;
        }
        system("cls");
        fflush(stdin);
    }
    system("cls");
    fflush(stdin);
}

student *sortclass(student *head, char *class) // 6.教师排序本班学生的数学成绩
{
    student *f = head->next;
    student *e = (student *)malloc(sizeof(student));
    student *a = e;
    student *b = NULL;
    while (f)
    {
        if (strcmp(f->class, class) == 0)
        {
            student *xin = (student *)malloc(sizeof(student));
            xin->next = NULL;
            b = xin;
            a->next = b;
            a = a->next;

            strcpy(b->stu_acc, f->stu_acc);
            strcpy(b->name, f->name);
            b->mathgrade = f->mathgrade;
            strcpy(b->stu_pass, f->stu_pass);
            strcpy(b->class, f->class);

            f = f->next;
        }
        else
        {
            f = f->next;
        }
    }

    // student *p = e->next;
    // student *pre;
    // student *r = p->next;
    // p->next = NULL;
    // p = r;
    // while(p)
    // {
    //     r = p->next;
    //     pre = e;
    //     while(pre->next && pre->next->mathgrade < p->mathgrade)
    //     {
    //         pre = pre->next;
    //     }
    //     p->next = pre->next;
    //     pre->next = p;
    //     p = r;
    // }
    // return e;

    student *a = head;
    student *b = head->next;
    while(b->next != NULL)
    {
        if(a->next->mathgrade >= b->next->mathgrade)
        {
            b = b->next;
        }
        else
        {
            student *houyan = a;
            student *cha = b;
            b = b->next;
            while(cha->mathgrade > houyan->mathgrade)
            {
            }
        }
    }
}

void adminUI(student *head, student *p, teacher *head1, teacher *b) //管理员循环
{
    while (1)
    {
        admin_face();
        int choice = 100;
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            adminUIone(head1, b);
            break;
        case 2:
            adminUItwo(head, p, head1);
            break;
        }
        system("pause");
        system("cls");
        fflush(stdin);
    }
    system("cls");
    fflush(stdin);
}

void adminUIone(teacher *head1, teacher *b) //管理员教师端循环
{
    while (1)
    {
        admintea_face();
        int choice = 100;
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            creatlist1(head1);
            break;
        case 2:
            b = findlist1(head1);
            deletelist1(b, head1);
            break;
        case 3:
            b = findlist1(head1);
            correctlist1(b, head1);
            break;
        case 4:
            b = findlist1(head1);
            break;
        case 5:
            printlist1(head1);
            break;
        }
        system("cls");
        fflush(stdin);
    }
    system("cls");
    fflush(stdin);
}

void adminUItwo(student *head, student *p, teacher *head1) //管理员学生端循环
{
    while (1)
    {
        adminstu_face();
        int choice = 100;
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            creatlist(head);
            break;
        case 2:
            p = findlist(head);
            deletelist(p, head);
            break;
        case 3:
            p = findlist(head);
            correctlist(p, head);
            break;
        case 4:
            p = findlist(head);
            break;
        case 5:
            printlist(head);
            break;
        case 6:
            head = sorlist5(head);
            printlist(head);
        }
        system("cls");
        fflush(stdin);
    }
    system("cls");
    fflush(stdin);
}

void chongzhumima(student *head, student *q) //重置学生密码函数
{
    printf("请输入重置密码验证码\n");
    char mima[20];
    scanf("%s", mima);
    int choice;
    if (strcmp(mima, "3gniubi") == 0)
    {
        printf("重置密码验证码正确，请输入要修改后的密码\n");
        char tpassword[20];
        scanf("%s", tpassword);
        strcpy(q->stu_pass, tpassword);
        printf("密码修改完成");
        updatefile(head);
    }
    else
    {
        printf("重置密码输入错误，请选择\n");
        printf("======================================\n");
        printf("--------------------------------------\n");
        printf("--------------1.重新输入--------------\n");
        printf("--------------------------------------\n");
        printf("--------------2.返回上一级--------------\n");
        printf("--------------------------------------\n");
        printf("--------------0.关闭文件--------------\n");
        printf("--------------------------------------\n");
        printf("======================================\n");
        printf("请输入0到2：   ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            chongzhumima(head, q);
            break;
        case 2:
            studentUI(head, q);
            break;
        }
        system("pause");
        system("cls");
        fflush(stdin);
    }
}

int main()
{
    creatfile();
    student *p = NULL;
    teacher *b = NULL;

    student *head = NULL;
    head = inithead(head);
    scanffile(head);

    teacher *head1 = NULL;
    head1 = inithead1(head1);
    scanffile1(head1);

    //上面都是初始化

    main_UI(head1, head, p, b);
}

// int main()//测试
// {
//     student *p = NULL;
//     student *head = NULL;
//     head = inithead(head);
//     scanffile(head);
//     teacher *head1 = NULL;
//     head1 = inithead1(head1);
//     scanffile1(head1);
//     //上面都是初始化
//     scanffile(head);
//     printlist(head);
//     head = sortlist(head);
//     printlist(head);
// }
