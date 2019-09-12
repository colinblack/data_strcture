#include <iostream>

template <class T>
class ListNode {
public:
	ListNode<T>* next;
	T data;
};

template <class T>
void revertList(ListNode<T>*& node, int groupNum, int groupGap)
{
	ListNode<T>* pTemp = nullptr;
	ListNode<T>* pCurr = node;
	ListNode<T>* pNext = nullptr;
	ListNode<T>* pTail = nullptr;
	ListNode<T>* pHead = nullptr;
	//	ListNode<T>* pReserve[groupNum + 1] = {nullptr};

	bool isHead = 1;
	int cnt = groupNum;
	int gap = groupGap;

	while (pCurr != nullptr)
	{
		if (!cnt)
		{
			break;
		}
		pTail = pCurr;
		while (gap)
		{
			pNext = pCurr->next;
			pCurr->next = pTemp;
			pTemp = pCurr;
			pCurr = pNext;

			--gap;
		}

		if (isHead)
		{
			node = pTemp;
			isHead = 0;
		}
		pTail->next = pNext;
		gap = groupGap;
		--cnt;
	}
}

int main()
{
	int seqNum = 0;
	int listNum = 5;

	ListNode<int>* list = new ListNode<int>;
	list->data = 1;

	list->next = new ListNode<int>;
	list->next->data = 2;

	list->next->next = new ListNode<int>;
	list->next->next->data = 3;

	list->next->next->next = new ListNode<int>;
	list->next->next->next->data = 4;

	list->next->next->next->next = new ListNode<int>;
	list->next->next->next->next->data = 4;
	list->next->next->next->next->next = nullptr;


	//std::cin >> seqNum;

	revertList(list, 2, 2);


	for (auto tail = list; tail != nullptr; tail = tail->next)
	{
		std::cout << tail->data << std::endl;
	}

	return 0;
}
