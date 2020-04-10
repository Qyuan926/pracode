#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
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

int main()
{
	string num1 = "123";
	string num2 = "456";
	string ret=multiply(num1, num2);
	cout << ret << endl;
}