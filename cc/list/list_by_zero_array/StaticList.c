#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include "StaticList.h"

#define AVALIABLE -1

typedef struct Tag_StaticListNode{
	int data;
	int next;   
}TStaticListNode;


typedef struct Tag_StaticList{
	int capacity;
	TStaticListNode header;
	TStaticListNode node[];
} TStaticList;


StaticList* StaticListCreate(int capacity)
{
	TStaticList* ret = NULL;
	int i;
	ret = (TStaticList*)malloc(sizeof(TStaticList) + sizeof(TStaticListNode) * (capacity + 1));
	if (ret != NULL)
	{
		ret->capacity = capacity;
		ret->header.data = 0;
		ret->header.next = 0;
	}
	for (i = 1; i <= capacity; i++)
	{
		ret->node[i].next = AVALIABLE;
	}


	return ret;
}
void  StaticListClear(StaticList* list)
{
	TStaticList* slist = (TStaticList*)list;
	int i;
	if (slist != NULL)
	{
		slist->header.data = 0;
		slist->header.next = 0;
		for (i = 0; i <= slist->capacity; i++)
		{
			slist->node[i].next = AVALIABLE;
		}
	}
}

int GetLength(StaticList* list)
{
	TStaticList* slist = (TStaticList*)list;
	int ret = -1;
	if (slist != NULL)
	{
		return slist->header.data;
	}

	return ret;
}

int GetCapacity(StaticList* list)
{
	TStaticList* slist = (TStaticList*)list;
	int ret = -1;
	if (slist != NULL)
	{
		return slist->capacity;
	}

	return ret;

}

StaticListNode* StaticListNodeGet(StaticList* list , int pos)
{
	TStaticList* slist = (TStaticList*)list;
	TStaticListNode* ret = NULL;
	int current = 0;
	int i;
	if ((list != NULL) && (0 <= pos) && (pos < slist->header.data))
	{
		for (i = 0; i <= pos; i++)
		{
			current = slist->node[current].next;
		
		}
	
		ret = &(slist->node[current]);
	
	}
	return ret;

}

void StaticListDestory(StaticList* list)
{
	free(list);
}

int StaticListInsert(StaticList* list, StaticListNode* node, int pos)
{
	TStaticList* slist = (TStaticList*)(list);
	int ret = (list != NULL);
	ret = ret && (0 <= pos) && (pos <= slist->capacity) && (node != NULL);
	ret = ret && (slist->header.data + 1 <= slist->capacity);
	int current = 0, object = 0, index = 0;
	int i;
	
	if (ret)
	{
		slist->node[0] = slist->header;
		for (i = 1; i <= slist->capacity; i++)
		{
			if (slist->node[i].next != AVALIABLE)
			{
				index = i;
				break;
			}
		}
		slist->node[index].data = (unsigned int)node;
		for (i = 0; (i < pos )&&(slist->node[current].next != 0) ; i++)
		{
			current = slist->node[current].next;
		
		}
		slist->node[index].next = slist->node[current].next;
		slist->node[current].next = index;
 		
		slist->node[0].data++;
		slist->header = slist->node[0];
	
	}
}
StaticListNode* StaticListDelete(StaticList* list, int pos)
{
	TStaticList* slist = (TStaticList*) list;
	TStaticListNode* ret = NULL;
	int current = 0, object = 0,i = 0;
	if ((list != NULL ) && (pos < slist->header.data) &&(0 <= pos))
	{
		slist->node[0] = slist->header;
		for (i = 0; i < pos ; i++)
		{
			current = slist->node[current].next;
		}
		object = slist->node[current].next;
		slist->node[current].next = slist->node[object].next;
		slist->node[0].data--;
		slist->header = slist->node[0];
		slist->node[object].next = AVALIABLE;

		ret = &(slist->node[object]);
	}

	return ret;
}


