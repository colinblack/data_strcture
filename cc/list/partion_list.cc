//分割链表
#include <iostream>

template <class T>
class listNode {
public:
	listNode<T>* next;
	T data;
};

template <class T>
using LISTNODE = listNode<T>*;


template <class T>
LISTNODE<T> partionList(LISTNODE<T> list, int x)
{
	listNode<T> left_dummy(-1);
	listNode<T>	right_dummy(-1);

	LISTNODE<T> left_pointer = &left_dummy;
	LISTNODE<T> right_pointer = &right_dummy;

	for (LISTNODE<T> curr = list; curr != nullptr; curr = curr->next)
	{
		if (curr->data < x)
		{
			left_pointer->next = curr;
			left_pointer = left_pointer->next;
		}
		else
		{
			right_pointer->next = curr;
			right_pointer = right_pointer->next;
		}
	}

	left_pointer->next = right_dummy.next;
	right_pointer->next = nullptr;


	return left_dummy.next;
}