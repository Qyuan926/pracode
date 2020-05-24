#define _CRT_SECURE_NO_WARNINGS 1
/*
如果一个字符串由两个相同字符串连接而成,就称这个字符串是偶串。例如"xyzxyz"和"aaaaaa"是偶串,但是"ababab"和"xyzxy"却不是。
牛牛现在给你一个只包含小写字母的偶串s,你可以从字符串s的末尾删除1和或者多个字符,保证删除之后的字符串还是一个偶串,牛牛想知道删除之后得到最长偶串长度是多少。*/


#include<iostream>
#include<string>
using namespace std;

class Solution{
	bool Islaw()
	{
		if (_str.size() % 2 != 0)
			return false;
		int mid = _str.size() / 2;
		string str1 = _str.substr(0, mid);
		string str2 = _str.substr(mid);
		return str1 == str2;
	}

public:
	int Fun(string str)
	{
		int size = str.size();
		if (size <= 1)
			return 0;
		_str = str;
		while (size>0)
		{

			_str.pop_back();
			--size;
			if (Islaw())
			{
				return _str.size();
			}
		}
		return 0;
	}
private:
	string _str;
};

int main()
{
	string str;
	while (cin >> str)
	{
		Solution s;
		int ret = s.Fun(str);
		cout << ret << endl;
	}
	return 0;
}