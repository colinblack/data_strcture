//3���� N�����Ѱ���С�����˳���źã�Ҫ������һ������ �������뵽ԭ�������У�������Ȼ��������
//ע��ṹ��ĳ�ʼ��
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 15


typedef struct array_t{
	int length;
	int data[MAXSIZE];
}array;

int DataSort(array* target, int size, int pos, int num)
{
	int ret = -1, i;
	if ((0 <= pos) && (pos < size) && (target->length < size))
	{
		if (pos > target->length - 1)
		{
			target->data[target->length] = num;
		}
		for (i = target->length; i >= pos; i--)
		{
			target->data[i + 1] = target->data[i];
		
		}
		target->data[pos] = num;
		target->length++;
		ret = 0;
	}

	return ret;
}


int main(void)
{
	int i; 
	array target = { 10,{0,1,2,3,4,5,6,7,8,9} };
	DataSort(&target, MAXSIZE, 4, 13);
	for (i = 0; i < target.length; i++)
	{
		printf("%4d, \n", target.data[i]);
	
	}
	system("pause");
	return 0;
}
