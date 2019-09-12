//大数的最长回文子串

#include<iostream>
#include<stdlib.h>

using namespace std; 

int main()
{
	const char strbuf[] = "1561234651564789";
	unsigned int len = strlen(strbuf);

	//创建一个动态数组
	bool **is_palindrome = new bool*[len];   

	for (int i = 0; i < len; ++i)
	{
		is_palindrome[i] = new bool[i];
	}
	//初始化动态数组

	for (int i = 0; i < len; ++i)
	{
		is_palindrome[i][i] = true;
	}
	
	int tail = 0;
	for (int i = 2; i <= len; ++i)
	{
		for (int j = 0; j < len - i + 1; ++j)
		{
			tail = i + j - 1;
			if (i == 2)
			{
				is_palindrome[j][tail] = (strbuf[j] == strbuf[tail]);			
			}
			else
			{
				is_palindrome[j][tail] = (strbuf[j] == strbuf[tail] 
					&& is_palindrome[j + 1][tail - 1]);			
			}
		
		}
	}

	int max_head = 0, max_tail = 0, max_len = 0;   //最长字串及首位位置

	for (int i = 0; i < len; ++i)
	{
		for (int j = i; j < len; ++j)
		{
			if (is_palindrome[i][j] 
				&& max_len < (j - i + 1))
			{
				max_len = j - i;
				max_head = i;
				max_tail = j;
			}
		}	
	}

	cout << max_len <<" " <<  max_head << " "<< max_tail << endl;



	system("pause");
	return 0;
}