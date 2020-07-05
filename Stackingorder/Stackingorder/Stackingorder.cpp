#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

void _Fullarrange(vector<string>& arr, string& str, int Index)
{
	if (Index == str.size())
	{
		arr.push_back(str);
		return;
	}
	for (int i = Index; i<str.size(); ++i)
	{
		swap(str[i], str[Index]);
		_Fullarrange(arr, str, Index + 1);
		swap(str[i], str[Index]);
	}
}
void Fullarrange(vector<string>& arr, string& str)
{
	if (str.empty())
		return;
	//回溯算法
	_Fullarrange(arr, str, 0);
}
bool isLaw(string& str, string& arrstr)
{
	if (str.empty() || arrstr.empty() || str.size() != arrstr.size())
		return false;
	int arri = 0;
	stack<char> s;
	for (int i = 0; i<str.size(); ++i)
	{
		s.push(arrstr[arri]);
		if (!s.empty() && str[i] == s.top())
		{
			s.pop();
		}
		++arri;
		if (arri == arrstr.size())
			break;
	}
	if (s.empty())
		return true;
	return false;
}

int main()
{
	string str;
	cin >> str;
	//将字符串进行全排列
	string str1 = str;
	vector<string> arr;
	Fullarrange(arr, str1);
	//判断字符串是否符合栈的顺序
	for (int i = 0; i<arr.size(); ++i)
	{
		if (isLaw(arr[i], str))
			cout << arr[i] << endl;
	}

	return 0;
}