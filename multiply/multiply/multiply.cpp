#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
/*给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
输入: num1 = "123", num2 = "456"
输出: "56088"
*/
string multiply(string num1, string num2)
{

	int end1 = num1.size();
	int end2 = num2.size();
	string retstr(end1 + end2, '0');

	for (int i = end2 - 1; i >= 0; --i)
	{

		for (int j = end1 - 1; j >= 0; --j)
		{
			int mul = (num2[i] - '0')*(num1[j] - '0') + retstr[i + j + 1] - '0';
			retstr[i + j + 1] = mul % 10 + '0';
			retstr[i + j] += mul / 10;
		}
	}
	for (int k = 0; k<end1 + end2; ++k)
	{
		if (retstr[k] != '0')
			return  retstr.substr(k);
	}
	return "0";
}