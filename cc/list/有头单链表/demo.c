#include<stdio.h>
#include<stdlib.h>

typedef struct node_t{
	int data;
	struct node_t* next;
}node;

int insert(node* current, int data)
{
	node *new = NULL, *previous = current;
	while (current->data < data)                     //���Һ���λ��
	{
		previous = current;
		current = current->next;
	}

	new = (node*)malloc(sizeof(node));    //�����ڴ�
	if (new == NULL)
		return -1;
	new->data = data;
	new->next = current;
 	previous->next = new;

	return 1;
}



int main(void)
{	
	int i;
	node head = {3, NULL};
	for (i = 0; i < 10; i++)
	{
		insert(&head, i);
	}


	system("pause");
	return 0;
}
