#ifndef  _LIST_H_
#define  _LIST_H_


typedef struct DATA_T{
	int number;
	char* str;
}data;


typedef struct LIST_NODE_T{
	data* element;
	struct LIST_NODE_T* next;
}listNode;



int  init(listNode** head, data* element);
listNode* insertNode1(listNode* head, data* element);   
int insertNode2(listNode** head, data* element);
int tailNode1(listNode* head, data* element);   
int tailNode2(listNode** head,data* element);
listNode* topNode1(listNode* head, data* element);
int topNode2(listNode** head, data* element);

int topNode2(listNode** head, data* element);

listNode* deleteNode1(listNode* head, data* data);
int deleteNode2(listNode** head, data* data);
void showList(listNode* head);

listNode* getNode(listNode* head);

listNode* replaceNode1(listNode* head);
void replaceNode2(listNode** head);

int isEqual(data* des, data* src);

#endif