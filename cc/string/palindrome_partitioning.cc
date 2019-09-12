#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::fill_n;

//¶¯¹æ
class Solution {
public:
	~Solution()
	{
		if (_p)
		{
			for (int i = 0; i < _n; ++i)
			{
				delete _p[i];
			}
			delete _p;
		}
	
		if (_cache)
		{
			delete _cache;
		}
	}
	vector<vector<string>> partition(string s) {
		const int n = s.size();
		_n = n;
		bool **p = new bool*[n];
		for (int i = 0; i < n; ++i)
		{
			p[i] = new bool[n];
		}

		fill_n(&p[0][0], n*n, false);

		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = i; j < n; ++j)
			{
				p[i][j] =  s[i] == s[j] && ((j-i < 2) || p[i+1][j-1]);
			}	
		}

		auto cache = new  vector<vector<string>>[n];
		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = i; j < n; ++j)
			{
				if (p[i][j])
				{
					auto palindrome = s.substr(i, j - i + 1);
					if (j+1 < n)
					{					
						for (auto v : cache[j+1])
						{
							v.insert(v.begin(), palindrome);
							cache[i].push_back(v);
						}
					}
					else
					{
						cache[i].push_back(vector<string>{palindrome});
					}

				}
			}
		
		}
		return cache[0];
	}
private:
	bool **_p = nullptr;
	vector<vector<string>> *_cache = nullptr;
	int _n;
};


class Solution_1 {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> output;
		dfs(0, 1, s, res, output);
		return res;
	}

	void dfs(int pre, int start, string& s, vector<vector<string>>& res, vector<string>& output)
	{
		if (start == s.size() )
		{
			if (isPalindrome(pre, start-1, s))
			{
				output.push_back(s.substr(pre, start - pre));
				res.insert(res.begin(), output);
				output.pop_back();			
			}
			return;
		}
		dfs(pre, start + 1, s, res, output);
		if (isPalindrome(pre, start-1, s))
		{
			output.push_back(s.substr(pre, start - pre));
			dfs(start, start+1, s, res, output);
			output.pop_back();
		}
	}

	bool isPalindrome(int start, int end , string s)
	{
		while (start < end)
		{
			if (s[start++] != s[end--])	return false;
		}
		return true;
	}

};

int main()
{
	Solution_1 test;

	auto res = test.partition("BB");
	//   std::cout << "size:"<< res.size() << std::endl;
#if 1
	for (auto v : res)
	{
		for (auto v1 : v)
		{
			std::cout << v1 << " ";

		}
		std::cout << std::endl;
	}
#endif
	return 0;
}
