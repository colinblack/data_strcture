//定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
#include<iostream>
#include<ctime>
#include<stack>
#include<cstdlib>
class MyStack : public std::stack<int>
{
public:
	void MyPop();
	void MyPush(int num);
	int GetMin();
private:
	std::stack<int> MinStack;
	bool isEmpty = true;

};

void MyStack::MyPush(int num)
{
	push(num);
	if (isEmpty)
	{
		MinStack.push(num);
		isEmpty = false;
	}
	else
	{
		if (num < MinStack.top())
		{
			MinStack.push(num);
		}
	}

}

int MyStack::GetMin()
{
	return MinStack.top();
}


void MyStack::MyPop()
{
	int top_temp = top();
	if (top_temp == MinStack.top())
	{
		MinStack.pop();
	}
	pop();
}




void getRandNunber(MyStack& obj, int u32Num)
{
	int rand_temp;
	srand(static_cast<unsigned int>(time(nullptr)));
	for (int i = 0; i < u32Num; ++i)
	{
		rand_temp = (rand() + 1)% 100;

		obj.MyPush(rand_temp);
	}
}

int main()
{
	MyStack demo;
	getRandNunber(demo,10);
	std::cout << demo.GetMin() << std::endl;

	system("pause");
	return 0;
}