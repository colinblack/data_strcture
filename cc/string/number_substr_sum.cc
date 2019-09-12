//字符串数字子串求和
#include <iostream>

int FirstNumPos(const char* str)             //相对位置
{
	int pos = 0;

	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			break;
		}
		++pos;
		++str;
	}
	return pos;
}

int LastNumPos(const char* str)
{
	int pos = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			break;
		}
		++pos;
		++str;
	}

	return pos;
}


int Sum(const char* str)
{
	int sum = 0;
	int total = 0;
	int begin_pos = 0;
	int end_pos = 0;
	int gap = 0;
	const char* str_temp = nullptr;

	while (*str)
	{
		sum = 0;
		begin_pos = FirstNumPos(str);
		end_pos = LastNumPos(str + begin_pos);
		gap = end_pos - begin_pos;
	
		for (int i = 0; i < gap; ++i)
		{
			sum = sum * 10 + (*(str + begin_pos + i) - '0');
		}
				
		total += sum;

		str = str + begin_pos + end_pos;
	}
	return total;
}


int main()
{
	char test[] = "he123hju12iopj34";
	int ret = Sum(test);

	std::cout << ret << std::endl;

//	system("pause");




//	system("pause");
	return 0;
}
