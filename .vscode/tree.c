#include<stdio.h>
//树的双亲法表示的结构结点定义
#define MAX_TREE_SIZE 100//定义一个变量100
typedef int TElemType;//树节点的数据类型,目前暂定为整型
typedef struct PTNode//结点结构
{
    TElemType data;//结点数据
    int parent;//双亲位置
}PTNode;
typedef struct //树结构
{
    PTNode node[MAX_TREE_SIZE];//结点数组
    int r, n;//根的位置和结点数
}PTree;





int main (){
    printf("hello");
}