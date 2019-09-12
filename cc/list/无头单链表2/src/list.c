#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "err.h"


int init(listNode** head, data* element)    
{
	ERRMEMORY_2((*head) != NULL, "list is inited");
	*head = (listNode*)malloc(sizeof(listNode));
	ERRMEMORY_2(*head == NULL, "malloc is failed");
	(*head)->element = element;
	(*head)->next = NULL;
	
	return 0;
}

int tailNode1(listNode* head, data* element)   //ÔÚÁ´±íÎ²×·¼Ó
{	
	while(head->next != NULL)
	{	
		head = head->next;
	}

	
	listNode* pNewNode = (listNode*)malloc(sizeof(listNode));
	ERRMEMORY_2(pNewNode == NULL, "pNewNode is NULL");
	pNewNode->element = element;
	head->next = pNewNode;
	
	return 0;
}

int tailNode2(listNode ** head, data * element)
{
	listNode** pCur = head;
	for(;*pCur != NULL;pCur = (&(*pCur)->next))
			;
	listNode* pNewNode = (listNode*)malloc(sizeof(listNode));
	ERRMEMORY_2(pNewNode == NULL, "pNewNode is NULL");

	 pCur = &pNewNode;
}

void showList(listNode * head)
{
	for(; head != NULL; head = head->next)	 
	{	
		printf("%d \n", head->element->number);
	}
	
}

int isEqual(data * des, data * src)
{
	int result_1 = (des->number == src->number);
	
	int result_2 = !strcmp(des->str, src->str);
	
	return (result_1 && result_2) ? 0 : 1;
}


listNode* deleteNode1(listNode * head, data* data)  
{
	listNode* pre =  NULL;
	listNode* curr = head;

	while(isEqual(head->element, data))
	{
		pre = curr;
		curr = curr->next;
	}

	if(pre)
	{
		pre->next = curr;
	}
	else
	{
		head = curr->next;	
	}
	
	free(curr->element->str);
	free(curr->element);
	free(curr);

	return head;
}


int deleteNode2(listNode ** head, data* data)
{
	listNode **pCurr = head;
	listNode *pTemp = NULL;

	while(isEqual((*pCurr)->element, data))
	{
		*pCurr = (*pCurr)->next;
	}
	
	 pTemp = *pCurr;
	*pCurr = (*pCurr)->next;
	free(pTemp->element->str);
	free(pTemp->element);
	free(pTemp);
}


listNode* topNode1(listNode *head, data * element)
{
	ERRMEMORY_1(head == NULL, "list is not inited");
	
	listNode* pNewNode = (listNode*)malloc(sizeof(listNode));
	ERRMEMORY_1(pNewNode == NULL, "pNewNode is NULL");
	pNewNode->element = element;
	pNewNode->next = head;

	return pNewNode;

}

int topNode2(listNode ** head, data * element)
{
	ERRMEMORY_2(*head == NULL, "list is not inited");

	listNode* pTemp = NULL;
	listNode* pNewNode = (listNode*)malloc(sizeof(listNode));
	ERRMEMORY_2(pNewNode == NULL, "pNewNode is NULL");
	pNewNode->element = element;
	pNewNode->next = head;

	pTemp = *head;
	*head = pNewNode;
	(*head)->next = pTemp;

	return 0;
}