#include<stdio.h>
//树的孩子表示法的结构结点定义
#define MAX_TREE_SIZE 100//定义一个变量100
typedef int TElemType;//树节点的数据类型,目前暂定为整型
typedef struct CTNode//孩子结点
{
    int child;
    struct  CTNode *next;   
}*ChildPtr;
typedef struct//表头结构
{
    TElemType data;
    ChildPtr firstchild;
}CTBox;
typedef struct //树结构
{
    CTBox nodes[MAX_TREE_SIZE];
    int r, n;
}CTree;







int main (){
    printf("hello");
}