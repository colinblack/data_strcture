#ifndef _SINGLELISTNODE_H_
#define _SINGLELISTNODE_H_
#include<iostream>

template <class T> class SingleList;



template <class T>
class SingleListNode{
public:
	friend class SingleList<T>;
	SingleListNode(T s = NULL) 
		: data(s){
	}

	SingleListNode(T s = NULL, SingleListNode* ptr = nullptr)    //构造函数用于头部添加节点
	{
		data(T);
		next(ptr);
	}

	~SingleListNode()
	{		
	}
private:
	T data;
	SingleListNode* next = nullptr;
};


template <class T>

class SingleList{
public:
	SingleList(){
	}
	~SingleList()
	{
	
	}
	bool isEmpty();
	void addToTail(T);
	void addToHead(T);
	int  deleteFromHead();
	int deleteFromTail();
	void deleteNode(T);
	bool isInList(T) const;

private:
	SingleListNode<T> *head = nullptr, *tail = nullptr;
};

template <class T>

void SingleList<T>::addToTail(T data)
{
	if (tail != nullptr)
	{
		tail->next = new SingleListNode<T>(data);
		tail = tail->next;
	}
	else
	{
		head = tail = new SingleListNode<T>(data);	
	}
}

template <class T>

bool  SingleList<T>::isEmpty()
{
	return head == nullptr;
}


//template <class T>
//
//void SingleList<T>::addToHead(T data)
//{
//	head = new SingleListNode<T>(data, head);
//
//	if (tail == nullptr)
//	{
//		tail = head;
//	}
//
//}







#endif