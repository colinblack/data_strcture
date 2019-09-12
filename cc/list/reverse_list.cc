//链表逆置
#include <iostream>

using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

void add_to_linklist(ListNode** head, int e);
void show_link_list(const ListNode* head);
void recurse_reverse_linklist(ListNode** head);
ListNode* recurse_reverse_linklist(ListNode* head);

int main(){

	try
	{
		ListNode* head = NULL;
		add_to_linklist(&head, 1);
		add_to_linklist(&head, 2);
		add_to_linklist(&head, 3);
		add_to_linklist(&head, 4);
		add_to_linklist(&head, 5);
		cout << "原始链表" << endl;
		show_link_list(head);

		// cout << endl << "有返回逆置,递归" << endl;
		// head = recurse_reverse_linklist(head);
		// show_link_list(head);
		// head = recurse_reverse_linklist(head);
		// show_link_list(head);

		cout << endl << "原地逆置,递归" << endl;
		// cout << &head << endl;
		recurse_reverse_linklist(&head);
		// cout << &head << endl;
		show_link_list(head);

		// recurse_reverse_linklist(&head);
		// show_link_list(head);

	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	// system("pause");
	return 0;
}

void recurse_reverse_linklist(ListNode** head)
{ // 无返回,原地逆置,递归
	if (*head == NULL || (*head)->m_pNext == NULL)
	{
		// cout << "diu" << (*head)->m_nValue << endl;

		//cout << (*s)->m_nValue << endl;
		// cout << "dd s:" << s << endl;
		return;
	}

	// ?????????????????????????????????
	// 此处怎样才能实现就地逆置
	// 代码不能正确逆置

	ListNode *p = *head;

	//cout << head << endl;
	recurse_reverse_linklist(&(p->m_pNext));
	//	cout << *s << endl;
	//cout << p->m_pNext->m_nValue << endl;
	// cout << p->m_nValue << endl;
	p->m_pNext->m_pNext = p;
	head = &(p->m_pNext);
	// cout << *head << endl;
	p->m_pNext = NULL;
}

ListNode* recurse_reverse_linklist(ListNode* head)
{ // 有返回,原地逆置,递归
	if (head == NULL || head->m_pNext == NULL)
		return head;

	ListNode* newHead = recurse_reverse_linklist(head->m_pNext);
	head->m_pNext->m_pNext = head;

	head->m_pNext = NULL;

	return newHead;
}

void add_to_linklist(ListNode** head, int e)
{
	if (*head == NULL)
	{
		*head = new ListNode();
		(*head)->m_nValue = e;
		(*head)->m_pNext = NULL;
	}
	else
	{
		ListNode* p = *head;
		while (p->m_pNext)
			p = p->m_pNext;

		ListNode* pEle = new ListNode();
		pEle->m_nValue = e;
		pEle->m_pNext = p->m_pNext;
		p->m_pNext = pEle;
	}
}

void show_link_list(const ListNode* head)
{
	const ListNode* p = head;
	std::cout << "-------------------------------------------" << std::endl;

	while (p != NULL) {
		std::cout << p->m_nValue << ",";
		p = p->m_pNext;
	}
	std::cout << std::endl;
}
