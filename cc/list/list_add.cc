#include <iostream>


template <class T>
class listNode {
	listNode<T>* next;
	T data;

};

template <class T>
using LISTNODE = listNode<T>*;



template <class T>
LISTNODE<T> listADD(LISTNODE<T> list1, LISTNODE<T> list2)
{
	LISTNODE<T> list = nullptr;
	LISTNODE<T> curr = nullptr;
	list->next = nullptr;
	T num1 = 0;
	T num2 = 0;
	T carry = 0;

	while (list1 != nullptr || list2 != nullptr)
	{
		num1 = (list1 == nullptr ? 0 : list1->data);
		num2 = (list2 == nullptr ? 0 : list2->data);


		if (list == nullptr)
		{
			list = new LISTNODE<T>(0);
			curr = list;
		}
		else
		{
			curr = new LISTNODE<T>(0);
		}

		curr->data = (num1 + num2 + carry) % 10;
		carry = (num1 + num2) / 10;

		curr = curr->next;
		list1 = (list1 == nullptr ? nullptr : list1->next);
		list2 = (list2 == nullptr ? nullptr : list2->next);
	}

	if (carry > 0)
	{
		curr = new LISTNODE<int>(0);
		curr->data = carry;
	}


	return list;
}