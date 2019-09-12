#ifndef  _SKIPLIST_H_
#define  _SKIPLIST_H_

typedef struct node_t{
	int level;
	int data;
	struct node_t *next;
	struct node_t *down;
}node;

struct SkipList {
	node* head;
	int level;    //��һ��Ԫ�صĸ���

};

void SkipListCreat(struct SkipList** , int, int*);
int countLevel(int);


#endif