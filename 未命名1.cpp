#include<stdio.h>

int main()
{
	FILE *p1, *p2;                        //���������ļ�ָ��
    char filename[30], filename1[30], ch; //���������ַ��������������ļ�����
    printf("������Ҫ���Ƶ��ļ���\n");
    gets(filename);
    printf("�����븴�ƺ���ļ���\n");
    gets(filename1);
    if ((p1 = fopen(filename, "rb")) == NULL) //�򿪱����Ƶ��ļ�
    {
        printf("ERROR");

    }
    if ((p2 = fopen(filename1, "wb")) == NULL) //д��Ҫ���Ƶ��ļ���
    {
        printf("ERROR");

    }
    while (!feof(p1)) //��һ������ļ��Ƿ�����ĺ����������ж�
    {
        ch = fgetc(p1); //����ÿһ��p1ָ����ļ����ֽڣ���p1д�뵽p2ָ����ļ���ȥ
                        //���û��p2�ļ�����Ὠ��һ����filename1�ַ������������ļ�
        fputc(ch, p2);
        printf("���Ƴɹ�");
        fclose(p1); //����֮��Ϊ�˱��ⲻ��Ҫ�Ĳ������Ŷ�д��Ҫ�ر��ļ������ϵ��ļ�ָ�����ļ�����ϰ
        fclose(p2);
    }
 } 
