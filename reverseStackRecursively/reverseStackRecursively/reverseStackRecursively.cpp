#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
/*
一个栈依次压入1,2,3,4,5那么从栈顶到栈底分别为5,4,3,2,1。将这个栈转置后，从栈顶到栈底为1,2,3,4,5，也就是实现了栈中元素的逆序，
请设计一个算法实现逆序栈的操作，但是只能用递归函数来实现，而不能用另外的数据结构。

给定一个栈Stack以及栈的大小top，请返回逆序后的栈。*/
class ReverseStack {
public:
	//翻转栈内元素，注意返回值要引用
	vector<int>& reverseStackRecursively(vector<int>& stack, int top) {
		//栈内没有元素直接返回空栈
		if (top == 0)
			return stack;
		int ret = getlast(stack);

		reverseStackRecursively(stack, top - 1);
		//将求得的栈底元素入栈
		stack.push_back(ret);
		//返回栈
		return stack;
	}
	//函数作用：获取栈底部的元素
	int getlast(vector<int>& stack)
	{
		//取得栈顶的元素,并在栈中删除它
		int ret = stack.back();
		stack.pop_back();
		//如果此时栈为空，说明ret为栈底元素直接返回
		if (stack.empty())
		{
			return ret;
		}
		else
		{   //栈不为空，栈底元素为其他，递归去找
			int last = getlast(stack);
			//将此时的ret重新放入栈中
			stack.push_back(ret);
			//返回栈底元素
			return last;
		}
	}
};

int main()
{
	vector<int> stack = { 1, 2, 3, 4 };
	ReverseStack  s;
	vector<int> ret=s.reverseStackRecursively(stack, 4);
	for (auto e : ret)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}