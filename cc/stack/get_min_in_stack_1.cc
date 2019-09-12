#if 0
//定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
#include<iostream>
#include<ctime>
#include<stack>
#include<cstdlib>
class MyStack : public std::stack<int>
{
public:
	int GetMin(std::stack<int>&);
private:
	std::stack<int> MinStack;
};

void getRandNunber(std::stack<int>& obj, int u32Num)
{
	int u32RandTemp;
	srand(static_cast<unsigned int>(time(nullptr)));
	for (int i = 0; i < u32Num; ++i)
	{
		u32RandTemp = rand();

		obj.push(rand());
	}
}

int MyStack::GetMin(std::stack<int>& obj)
{
	int u32Min = obj.top();
	obj.pop();
	while (obj.size())
	{
		u32Min = (obj.top() < u32Min ? obj.top() : u32Min);
		obj.pop();
	}
	return u32Min;
}

int main()
{
	MyStack demo;
	getRandNunber(demo, 10);
	std::cout << demo.GetMin(static_cast<std::stack<int>>(demo));


	system("pause");
	return 0;
}

#endif