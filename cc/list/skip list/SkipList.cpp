#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"SkipList.h"


int countLevel(int num)
{
	static int cnt = 1;
	if (num == 0)
	{
		return 1;
	}
	else
	{
		countLevel(num / 2);
		return cnt++;
	}

}



void SkipListCreat(struct SkipList** list, int num, int* member)
{
	node *tail = NULL;
	int i, j;
	int level = countLevel(num);
	if (NULL == *list)	
	{
		*list = (struct SkipList*)malloc(sizeof(SkipList));
	}
//	(*list)->head = (node*)malloc(sizeof(node));
//	(*list)->head->level = level;
	tail = (*list)->head;
	for (i = level; i > 0; i--)
	{
		for (j = 0; j < num / (2 * (level - 1)); j++)
		{
			if (NULL == tail)
			{
				tail = (node*)malloc(sizeof(node));
			}
			if (NULL == tail->next)
			{
				tail->next = (node*)malloc(sizeof(node));
			}
			if (NULL == tail->down)
			{
				tail->down = (node*)malloc(sizeof(nodek));
			}
		}
	
	}



}



int main(void)
{
	int num;
	int member[10] = {1,3,9,10,15,17,21,32,61,76};
	struct SkipList* list = NULL;

	printf("please input level1 num");
	scanf("%d",&num);
	SkipListCreat(&list,num);

	
	system("pause");
	return 0;
}