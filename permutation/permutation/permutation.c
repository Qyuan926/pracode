#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//输入一个字符串，打印出该字符串中字符的所有排列。你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
//输入：s = "abc"
//输出：["abc", "acb", "bac", "bca", "cab", "cba"]
vector<string> permutation(string s) {
	vector<string>ret;
	if (s.empty())
	{
		return ret;
	}
	set<string> str;//使用set防止有重复的元素。

	BackTrack(str, s, 0);
	return vector<string>(str.begin(), str.end());

}
void BackTrack(set<string>&str, string& s, size_t Index)
{
	if (Index == s.size())
	{
		str.insert(s);
		return;
	}
	
	for (size_t i = Index; i<s.size(); ++i)
	{
		//第一个元素和其他元素依次交换
		swap(s[i], s[Index]);
		//迭代
		BackTrack(str, s, Index + 1);
		//撤销，交换成为原来的样子。
		swap(s[Index], s[i]);
	}
}

int main()
{
	char* s = "abc";
	int  n = 0;
	
	permutation(s);
	
	return 0;
}