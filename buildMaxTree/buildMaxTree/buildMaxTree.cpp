#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*链接：https://www.nowcoder.com/questionTerminal/a502c7c3c65e41fdaf65eec9e0654dcb
来源：牛客网

对于一个没有重复元素的整数数组，请用其中元素构造一棵MaxTree，MaxTree定义为一棵二叉树，其中的节点与数组元素一一对应，同时对于MaxTree的每棵子树，它的根的元素值为子树的最大值。现有一建树方法，对于数组中的每个元素，其在树中的父亲为数组中它左边比它大的第一个数和右边比它大的第一个数中更小的一个。若两边都不存在比它大的数，那么它就是树根。请证明这个方法的正确性，同时设计O(n)的算法实现这个方法。

给定一个无重复元素的数组A和它的大小n，请返回一个数组，其中每个元素为原数组中对应位置元素在树中的父亲节点的编号，若为根则值为-1。

测试样例：
[3,1,4,2],4
返回：[2,0,-1,2]*/
//解题思路：
	//对于数组中的每个元素，其在树中的父亲为数组中它左边比它大的第一个数和右边比它大的第一个数中更小的一个
	//[3,1,4,2],4
	//返回：[2,0,-1,2]
	//找每个数左边第一个比它大的数，从左到右遍历每个数，栈中保持递减序列，新来的
	//数不停地利用pop出栈顶，直到栈顶比新来的数大或没有数
	//以【3,2,1】为例，首先3入栈，接下来1比3小，无须pop出3,1入栈，并且确定了1往左第一个比它大的数为3
	//接下来2比1大，1出栈，2比3小，2入栈，并且确定了2往左第一个比它大的数为3.
	vector<int> buildMaxTree(vector<int> A, int n) {
		vector<int> ret;
		if (A.empty())
			return ret;
		stack<int> s;
		for (int i = 0; i<A.size(); ++i)
		{
			int pos = -1;
			//栈不为空时，栈顶所代表的元素小于当前元素是，应该被pop掉，直到栈为空或者栈顶所代表的元素大于当前元素的时候停止
			while (!s.empty() && A[s.top()]<A[i])
			{
				//获取要删除的下标
				int index = s.top();
				s.pop();
				//如果该位置在ret组值为-1表示他的左边没有比他大的数，而右边第一个比它大的数就是当前元素，下标为i
				//如果该位置在ret组值不为-1表示他的左边有比他大的数，和当前这个数比较，选出小的那个数
				if (ret[index] == -1 || A[ret[index]]>A[i])
					ret[index] = i;
			}
			if (!s.empty())
			{
				pos = s.top();
			}


			s.push(i);
			ret.push_back(pos);

		}
		return ret;
	}



int main()
{
	vector<int >A = { 3, 1, 4, 2 };
	vector<int >  ret = buildMaxTree(A, 4);
	for (auto e : ret)
	{
		cout << e << " ";
	}
	cout << endl;
}