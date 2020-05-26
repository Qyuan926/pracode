#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
using namespace std;
/*

一个栈中元素的类型为整型，现在想将该栈从顶到底按从大到小的顺序排序，只许申请一个栈。除此之外，可以申请新的变量，但不能申请额外的数据结构。如何完成排序？

输入描述:
第一行输入一个N，表示栈中元素的个数
第二行输入N个整数a_ia 
i
​	
 表示栈顶到栈底的各个元素


输出描述:
输出一行表示排序后的栈中栈顶到栈底的各个元素。*/
int main()
{
	stack<int> Sorteds;
	stack<int> tmps;
	int n;
	cin >> n;
	for (int i = 0; i<n; ++i)
	{
		int val;
		cin >> val;
		tmps.push(val);
	}

	while (!tmps.empty())
	{
		if (Sorteds.empty())
		{
			Sorteds.push(tmps.top());
			tmps.pop();
		}
		else
		{
			//取待排序栈的顶部元素；与排序栈的顶部元素比较，大于直接入栈,否则需要把排序栈中小于这个带排序栈顶部元素的元素全部移动到待排序栈，将这个元素插入排序栈
			int Top = tmps.top();
			tmps.pop();
			while (!Sorteds.empty() && Sorteds.top()>Top)
			{
				tmps.push(Sorteds.top());
				Sorteds.pop();

			}
			Sorteds.push(Top);
		}

	}

	while (!Sorteds.empty())
	{
		cout << Sorteds.top() << " ";
		Sorteds.pop();
	}
	cout << endl;
	return 0;

}