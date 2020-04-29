#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，
//1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
//一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

//1068385902
// 1 0 6 8 3 8 8 5 9 0 2
// 10 6 8 3 8 8 5 9 0 2
//数字字符串的第一位翻译的符号只能是一个字母
//数字字符串从第二位开始与前一位结合，范围为"10"------"25",即代表了两个字符
int translateNum(int num) {
	if (num<0)
	{
		num = -num;
	}
	//将数字转变为字符串
	string str = to_string(num);
	vector<int> dp(str.size() + 1, 1);
	for (size_t i = 1; i<str.size(); ++i)
	{
		if (str.substr(i - 1, 2) >= "10"&&str.substr(i - 1, 2) <= "25")
		{
			dp[i + 1] = dp[i - 1] + dp[i];
		}
		else
		{
			dp[i + 1] = dp[i];
		}

	}
	return dp[str.size()];
}

int main()
{
	cout << translateNum(1068385902) << endl;
	return 0;
}