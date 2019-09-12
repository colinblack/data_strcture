//任意输入一个数，在数组中找到两数相加等于这个数的两数集合

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<functional>
#include<time.h>


using namespace std;


class array{
public:
	 void  setMember();
	 void  setNum(int);
	 void  dealProcess();

private:
	int num;
	vector<int> menber;
};

void array::setMember()
{
	int  tmp;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		//tmp = rand() % 100;
		scanf("%d", &tmp);
		
		this->menber.push_back(tmp);
	}
	
}

void array::setNum(int n)
{
	this->num = n;

}

void array::dealProcess()
{
	sort(this->menber.begin(), this->menber.end(), greater<int>());
	vector<int>::iterator ita = this->menber.begin();
	vector<int>::iterator itb = this->menber.end() - 1;
	sort(ita, itb + 1, less<int>());

	while (ita < itb)
	{
		int a = *ita, b = *itb;
		int c = a + b;
		int n = this->num;
		if (c == n)
		{
			cout << *ita <<" " << *itb << endl;
			++ita;
			--itb;
		}
		else if (c < n )
		{
			++ita;
		}
		else
		{
			--itb;
		}
	
	}

}


int main(void)
{
	array *obj = new  array;
	obj->setNum(10);
	obj->setMember();
	obj->dealProcess();




}