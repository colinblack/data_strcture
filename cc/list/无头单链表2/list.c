#include "list.h"
#include "err.h"

#include <stdio.h>
#include <stdlib.h>


void init(listNode ** head)
{
	*head = NULL;
	(*head)->element = NULL;
	(*head)->next = NULL;
}

listNode* tailNode1(listNode* head, data* element)
{	
	listNode* pre = NULL;     //一级指针需要维护一个pre
	while(head != NULL)
	{	
		pre = head;
		head = head->next;
	}

	listNode* pNewNode = (listNode*)malloc(sizeof(listNode));
	ERRMEMORY(pNewNode == NULL, "pNewNode is NULL");

	pre->next = pNewNode;
	pre->next = NULL;	
}

void tailNode2(listNode ** head, data * element)
{
	listNode** pCur = head;
	for(;*pCur != NULL;pCur = (&(*pCur)->next))
			;
	listNode* pNewNode = (listNode*)malloc(sizeof(listNode));
	ERRMEMORY(pNewNode == NULL, "pNewNode is NULL");

	 pCur = &pNewNode;
}

void showList(listNode * head)
{
	for(; head != NULL; head = head->next)	 
		 ;
	printf("%d", head->element->number);
}

