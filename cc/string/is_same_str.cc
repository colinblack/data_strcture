//实现一个算法，确定一个字符串的所有字符是否相同。见识不允许使用额外的数据结构又该如何处理
#include<iostream>
#include<stdlib.h>
#include<string.h>

class demo{
public:
	demo()
	{
		char_set = new bool[256];
		memset(char_set,0, sizeof(char_set));
	/*	for (int i = 0; i < 256; ++i)
		{
			std::cout << char_set[i] << std::endl;   // 为什么初始化为0没用？
		}
		*/
	}
	~demo()
	{
		delete [] char_set;
	}
	void inputStr(std::string input)
	{
		str = input;
	}
	bool isDiff();

	void outputStr()
	{
		std:: cout << str.c_str() << std::endl;
	}
private:
	std::string str;
	bool *char_set = nullptr;

};


bool demo::isDiff()
{
	int val;
	for (int i = 0; i < str.size(); ++i)
	{
		val = str.at(i);
		std::cout << val << std::endl;
		if (char_set[val])
		{
			return false;
		}
		char_set[val] = true;
	}
	return true;

}



int main(void)
{
	std::string a;
	char str_buf[1024] = { 0 };
	std::cin.get(str_buf,1024);
	demo example;
	example.inputStr(str_buf);
	std::cout << example.isDiff() << std::endl;
	system("pause");
	return 0;
}

