#define _CRT_SECURE_NO_WARNINGS 1
#include<string>
#include<vector>
#include<iostream>
using namespace std;
/*实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

*/
int strStr(string haystack, string needle) {
	if (needle.empty())
		return 0;
	if (haystack.empty())
		return -1;

	int j = -1, i = 0;
	vector<int> b(needle.size() + 1);
	b[i] = j;
	while (i<needle.size())
	{
		while (j >= 0 && needle[i] != needle[j])
			j = b[j];
		i++;
		j++;
		b[i] = j;
	}
	int Index1 = 0;
	int Index2 = 0;
	while (Index1<haystack.size())
	{
		while (Index2 >= 0 && needle[Index2] != haystack[Index1])
			Index2 = b[Index2];
		Index1++;
		Index2++;
		if (Index2 == needle.size())
		{
			return Index1 - needle.size();
		}
	}
	return -1;
}

int main()
{
	string str1 = "ababbabaa";
	string str2 = "ababac";
	strStr(str1, str2);
	return 0;
}

