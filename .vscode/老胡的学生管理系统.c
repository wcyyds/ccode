#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//创建链表
typedef struct Node
{
    char ID[50];             //身份证号
    char name[50];           //姓名
    char sex[50];            //性别
    char site[10], time[10]; //违章地点 & 时间
    int sum;                 //扣分

    struct Node *next;
} node;

node List;
node *pHead;
//创建密码
void code()
{
    char password[10];
    printf("\t请输入密码:");
    gets(password);
    for (; strcmp(password, "rwc");)
    {
        printf("\t请重新输入:");
        gets(password);
    }
    printf("\t密码正确\n\t欢迎光临  (′?｀)\n");
    printf("\n");
}

//文件输入
int readFile(node *L)
{
    FILE *fp = fopen("2022年5月酒驾违章记录.txt", "r");

    node st;
    node *s;
    node *t = L;

    if (fp == NULL)
    {
        printf("出现错误!\n好好看看，再出错给你抓起来\n\n(?￣-￣? ?) 傻子吧? 嫌弃你\n");
        return 0;
    }
    else
    {
        while (fscanf(fp, "%s %s %s %s %s %d \n", st.ID, st.name, st.sex, st.site, st.time, &st.sum) != EOF)
        {
            s = (node *)malloc(sizeof(node));

            *s = st;
            s->next = t->next;
            t->next = s;
        }
    }
    fclose(fp);
    return 0;
}

//保存缓存内容至文件
int saveFile(node *L)
{
    printf("验证是否运行到这");
    FILE *fp = fopen("2022年5月酒驾违章记录.txt", "w");
    if (fp == NULL)
        return 0;

    node *p = pHead->next;

    while (p != NULL)
    {

        fprintf(fp, "%s %s %s %s %s %d \n", p->ID, p->name, p->sex, p->site, p->time, p->sum);

        p = p->next;
    }
    fclose(fp);
    return 0;
}

//目录设计
void makeMenu()
{
    printf("		    老话说:道路千万条,安全第一条。\n");
    printf("	       老话说:葡萄美酒夜光杯，借问醉驾几人回。\n");
    printf("		    所以说啊:别酒驾,酒驾你就无啦!\n");
    printf("\n");
    printf("  	          |2022.5月内酒驾违章查询,敬待君来|\n");
    printf("\n");
    printf("\n");
    printf("  ___________________________------------___________________________\n");
    printf(" |                                                                  |\n");
    printf(" |     乾杯 []~（￣▽￣）~*----菜单目录----*~（￣▽￣）~[] 乾杯     |\n");
    printf(" |                                                                  |\n");
    printf(" |	\t\t1.--[录入违章信息]--                        |\n");
    printf(" |	\t\t2.--[修改违章记录]--                        |\n");
    printf(" |	\t\t3.--[删除违章记录]--                        |\n");
    printf(" |	\t\t4.--[查询违章记录]--                        |\n");
    printf(" |	\t\t5.--[导出违章记录]--                        |\n");
    printf(" |	\t\t0.------[退出]------                        |\n");
    printf(" |__________________________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("请输入输入对应功能键(0~5):");
}

//录入违章记录
//头插法
void insertInfo(node *L, node e)
{
    node *h = L;
    node *s = (node *)malloc(sizeof(node));
    *s = e;

    if (pHead == NULL)
    {
        pHead->next = s;
    }
    else
    {
        s->next = pHead->next;
        pHead->next = s;
    }

    saveFile(pHead);
}

void add()
{

    node st;
    printf("请开始输入新增违章信息\n");
    printf("身份证件号: ");
    scanf("%s", st.ID);
    printf("姓名: ");
    scanf("%s", st.name);
    printf("性别: ");
    scanf("%s", st.sex);
    printf("地点: ");
    scanf("%s", st.site);
    printf("时间: ");
    scanf("%s", st.time);
    printf("扣分: ");
    scanf("%d", &st.sum);
    insertInfo(&List, st);
}

//查询违章记录
//按身份证件号查询
node *searchInfoByID(char ID[50], node *L)
{
    node *p = L;
    while (p != NULL)
    {
        if (strcmp(p->ID, ID) == 0)
        {

            return p;
        }

        p = p->next;
    }
    return NULL;
}

//按姓名查询
node *searchInfoByname(char name[50], node *L)
{
    node *p = L;
    while (p != NULL)
    {
        if (strcmp(name, p->name) == 0)
        {
            return p;

            break;
        }

        p = p->next;
    }
    return NULL;
}

void search(node *L)
{
    int choice;
    char ID[50], name[50];
    node *st;
    printf("请选择查询违章记录方式:  \n");
    printf("按身份证件号查询---1\n");
    printf("按姓名查询---------2\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("请输入要查询的身份证件号: \n");
        scanf("%s", ID);
        st = searchInfoByID(ID, L);

        if (st == NULL)
        {
            printf("查无此人 !\n");
        }
        else
        {

            printf("_________________________________________________\n");
            printf("|身份证件号\t|姓名\t|性别\t|地点\t|时间\t|扣分\t|\n");
            printf("_________________________________________________\n");
            printf("%s|%s\t|%s\t|%s\t|%s\t|%d\t|\n", st->ID, st->name, st->sex, st->site, st->time, st->sum);
            printf("_________________________________________________\n");
        }
    }
    else if (choice == 2)
    {
        printf("请输入要查询的姓名: \n");
        scanf("%s", name);
        st = searchInfoByname(name, L);

        if (st == NULL)
        {
            printf("查无此人 !\n");
        }
        else
        {

            printf("_________________________________________________\n");
            printf("|身份证件号\t|姓名\t|性别\t|地点\t|时间\t|扣分\t|\n");
            printf("_________________________________________________\n");
            printf("%s|%s\t|%s\t|%s\t|%s\t|%d\t|\n", st->ID, st->name, st->sex, st->site, st->time, st->sum);
            printf("_________________________________________________\n");
        }
    }
    else if (choice != 2 && choice != 1)
    {
        printf("出现错误！\n好好看看，再出错给你抓起来\n\n(?￣-￣? ?) 傻子吧? 嫌弃你");
    }
}

////////////////////////////////////////////////////////////
////////////////////
void search1(node *L) //查询函数,返回的是要查询的上一个结点
{
    int choice;
    char ID[50], name[50];
    node *st;
    printf("请选择查询违章记录方式:  \n");
    printf("按身份证件号查询---1\n");
    printf("按姓名查询---------2\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("请输入要查询的身份证件号: \n");
        scanf("%s", ID);
        st = searchInfoByID(ID, L);

        if (st == NULL)
        {
            printf("查无此人 !\n");
        }
        else
        {

            printf("_________________________________________________\n");
            printf("|身份证件号\t|姓名\t|性别\t|地点\t|时间\t|扣分\t|\n");
            printf("_________________________________________________\n");
            printf("%s|%s\t|%s\t|%s\t|%s\t|%d\t|\n", st->ID, st->name, st->sex, st->site, st->time, st->sum);
            printf("_________________________________________________\n");
        }
    }
    else if (choice == 2)
    {
        printf("请输入要查询的姓名: \n");
        scanf("%s", name);
        st = searchInfoByname(name, L);

        if (st == NULL)
        {
            printf("查无此人 !\n");
        }
        else
        {

            printf("_________________________________________________\n");
            printf("|身份证件号\t|姓名\t|性别\t|地点\t|时间\t|扣分\t|\n");
            printf("_________________________________________________\n");
            printf("%s|%s\t|%s\t|%s\t|%s\t|%d\t|\n", st->ID, st->name, st->sex, st->site, st->time, st->sum);
            printf("_________________________________________________\n");
        }
    }
    else if (choice != 2 && choice != 1)
    {
        printf("出现错误！\n好好看看，再出错给你抓起来\n\n(?￣-￣? ?) 傻子吧? 嫌弃你");
    }
}

node *searchInfoByID1(char ID[50], node *L)
{
    node *p = L->next;
    node *n = L;
    while (p != NULL)
    {
        if (strcmp(p->ID, ID) == 0)
        {
            return n;
        }
        n = n->next;
        p = p->next;
    }
    return NULL;
}

node *searchInfoByname1(char name[50], node *L)
{
    node *p = L->next;
    node *n = L;
    while (p != NULL)
    {
        if (strcmp(name, p->name) == 0)
        {
            return n;
            break;
        }
        n = n->next;
        p = p->next;
    }
    return NULL;
}
////////////////////返回的是查询结点的上一个结点
////////////////////////////////////////////////////////////

// 修改违章记录
void fix(node *L)
{
    char ID[50];
    int choice;
    printf("请输入要查询者的身份证件号: \n");
    scanf("%s", ID);
    node *st = searchInfoByID(ID, L);

    if (st == NULL)
    {
        printf("查无此人!\n");
        return;
    }

    while (1)
    {
        printf("_________________________________________________\n");
        printf("|身份证件号\t|姓名\t|性别\t|地点\t|时间\t|扣分\t|\n");
        printf("_________________________________________________\n");
        printf("%s|%s\t|%s\t|%s\t|%s\t|%d\t|\n", st->ID, st->name, st->sex, st->site, st->time, st->sum);
        printf("_________________________________________________\n");
        printf("修改身份证件号-----1\n");
        printf("修改姓名-----------2\n");
        printf("修改性别-----------3\n");
        printf("修改违章地点-------4\n");
        printf("修改违章时间-------5\n");
        printf("修改违章所扣分数---6\n");
        printf("想要离开-----------0\n");
        printf("请选择需要修改的内容: \n(输入对应数字0~6)\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("\n");
            break;
        case 1:
            printf("请输入修改后的身份证件号:  \n");
            scanf("%s", st->ID);
            break;
        case 2:
            printf("请输入修改后的姓名:  \n");
            scanf("%s", st->name);
            break;
        case 3:
            printf("请输入修改后的性别:  \n");
            scanf("%s", st->sex);
            break;
        case 4:
            printf("请输入修改后的违章地点:  \n");
            scanf("%s", st->site);
            break;
        case 5:
            printf("请输入修改后的违章时间:  \n");
            scanf("%s", st->time);
            break;
        case 6:
            printf("请输入修改后的扣分数:  \n");
            scanf("%d", st->sum);
            break;
        }
        // printf("%s", st->site);
        break;
    }
    saveFile(pHead);
}

//删除违章记录
void eraseInFo(node *pr, node *st) // eraseInFo(st,L);
{
    pr->next = pr->next->next;
}

void erase(node *L)
{
    char ID[50];
    int choice;
    node *p;
    printf("请输入需要删除信息者的身份证件号: \n");
    scanf("%s", ID);
    node *st = searchInfoByID1(ID, L);
    p = st;

    if (st == NULL)
    {
        printf("查无此人!\n");

        return;
    }
    printf("_________________________________________________\n");
    printf("|身份证件号\t|姓名\t|性别\t|地点\t|时间\t|扣分\t|\n");
    printf("_________________________________________________\n");
    printf("%s|%s\t|%s\t|%s\t|%s\t|%d\t|\n", st->ID, st->next->name, st->next->sex, st->next->site, st->next->time, st->next->sum);
    printf("_________________________________________________\n");
    eraseInFo(st, L);
    printf("\n删除成功!\n");
    saveFile(L);
}

//导出违章记录
void print(node *L)
{
    node *p = L->next;
    printf("\n");
    printf("________________________________________________________\n");
    printf("|身份证件号\t|姓名\t|性别\t|地点\t|时间\t|扣分\t|\n");
    printf("________________________________________________________\n");
    if (p != NULL)
    {
        while (p != NULL)
        {
            printf("%s|%s|%s|%s|%s|%d\n", p->ID, p->name, p->sex, p->site, p->time, p->sum);
            printf("________________________________________________________\n");
            p = p->next;
        }
    }
}

//目录跳转
void keyDown()
{
    int userkey = 0;
    scanf("%d", &userkey);
    switch (userkey)
    {
    case 1:
        printf("---[录入违章记录]---\n");
        printf("\n");
        add();
        break;
    case 2:
        printf("---[修改违章记录]---\n");
        fix(&List);
        printf("\n");
        break;
    case 3:
        printf("---[删除违章记录]---\n");
        erase(&List);
        printf("\n");
        break;
    case 4:
        printf("---[查询违章记录]---\n");
        search(&List);
        printf("\n");

        break;
    case 5:
        printf("---[导出违章记录]---\n");
        printf("\n");
        print(&List);
        break;
    case 0:
        printf("---[退出]---\n");
        printf("\n");
        exit(0); //直接退出模块本程序
        break;
    default:
        printf("出现错误！\n好好看看，再出错给你抓起来\n\n(?￣-￣? ?) 傻子吧? 嫌弃你\n");
        printf("\n");
        break;
    }
}
int main()
{
    int choice = 0;
    // scanf ("%d",&choice);

    // code();
    pHead = &List;
    pHead->next = NULL;
    readFile(pHead);
    while (1)
    {
        makeMenu();
        keyDown();
        // getchar();//按任意键继续
        system("pause"); //按任意键继续
    }
    readFile(&List);
    return 0;
}
