#ifndef _STATICLIST_H_
#define _STATICLIST_H_
//此链表非静态链表， 用StaticList命名有误


typedef void StaticList;
typedef void StaticListNode;


StaticList* StaticListCreate(int);
void  StaticListClear(StaticList*);
int GetLength(StaticList*);
int GetCapacity(StaticList*);
StaticListNode* StaticListNodeGet(StaticList*, int);
void StaticListDestory(StaticList*);
int StaticListInsert(StaticList*, StaticListNode*, int);
StaticListNode* StaticListDelete(StaticList*, int);







#endif




