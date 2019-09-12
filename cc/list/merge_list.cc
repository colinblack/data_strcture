//合并两链表
#include <iostream>
#include <list>

using std::list;

void mergeList(list<int>& src1, list<int>& src2, list<int>& dest)
{
	auto pd = dest.begin();
	auto p1 = src1.begin(), p2 = src2.begin();

	while (p1 != src1.end() && p2 != src2.end())
	{
		if (*p1 < *p2)
		{
			pd = p1;
			++p1;
		}
		else
		{
			pd = p2;
			++p2;
		}
		++pd;
	}

	if (p1 != src1.end())
	{
		pd = p1;
	}
	else if (p2 != src2.end())
	{
		pd = p2;
	}

}



int main()
{
	list<int> list1;
	list<int> list2;
	list<int> list3;

	list1.push_back(0);
	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(3);

	list2.push_back(0);
	list2.push_back(1);
	list2.push_back(2);
	list2.push_back(3);

	mergeList(list1, list2, list3);


	std::cout << list3.size() << std::endl;
	for (auto p = list3.begin(); p != list3.end(); ++p)
	{
		std::cout << "hehe" << std::endl;
		std::cout << *p << std::endl;
	}

	system("pause");
	return 0;
}