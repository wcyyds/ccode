void C






//单链表的遍历操作 
void displaynode 
{
	p = head->next;
	while (p != NULL)
	{
		printf("%d",p->next);
		p = p->next;
	}
}  
//单链表的元素个数
int length (Link head)
{
	p = head->next;
	int count = 0;
	while(p != NULL)
	{
		p = p->next;
		count++;
	 } 
	renturn count;
 } 
 //单链表的查找操作
int queryNode(Link head,Data Type X) 
{
	p = head ->next;
	count = 0;
	while (p!=NULL)
	{
		if(p->data==x)
		{
			print(data);//找到调用出函数，并提前返回true
			return true;
		}
	p = p->next;
	}
return false;
}
29.13
    






















