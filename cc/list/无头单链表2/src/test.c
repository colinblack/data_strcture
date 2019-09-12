#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "list.h"

int main(void)
{
	
	listNode *head = NULL;

	data* temp = (data*)malloc(sizeof(data));
	temp->number = 1;
	temp->str = (char*)malloc(sizeof(char) * 10);
	strcpy(temp->str, "hello1");
	
	int ret = init(&head, temp);

	temp = (data*)malloc(sizeof(data));
	temp->number = 2;
	temp->str = (char*)malloc(sizeof(char) * 10);
	strcpy(temp->str, "hello2");
	tailNode1(head, temp);

	temp = (data*)malloc(sizeof(data));
	temp->number = 3;
	temp->str = (char*)malloc(sizeof(char) * 10);
	strcpy(temp->str, "hello3");
	//head = topNode1(head, temp);
	//tailNode1(head, temp);
	topNode2(&head, temp);


	temp = (data*)malloc(sizeof(data));
	temp->number = 4;
	temp->str = (char*)malloc(sizeof(char) * 10);
	strcpy(temp->str, "hello4");
	tailNode1(head, temp);
	showList(head);

	return 0;

}
