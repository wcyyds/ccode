void C






//������ı������� 
void displaynode 
{
	p = head->next;
	while (p != NULL)
	{
		printf("%d",p->next);
		p = p->next;
	}
}  
//�������Ԫ�ظ���
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
 //������Ĳ��Ҳ���
int queryNode(Link head,Data Type X) 
{
	p = head ->next;
	count = 0;
	while (p!=NULL)
	{
		if(p->data==x)
		{
			print(data);//�ҵ����ó�����������ǰ����true
			return true;
		}
	p = p->next;
	}
return false;
}
29.13
    






















