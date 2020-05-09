#define _CRT_SECURE_NO_WARNINGS 1
#include<string>
#include<vector>
#include<iostream>
using namespace std;
//回溯算法
/*数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

示例：

输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]

*/
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string>ret;
		if (n <= 0)
			return ret;
		string str = "(";
		backtrack(n, ret, str, 1, 0);
		return ret;

	}
	void backtrack(int n, vector<string>& ret, string str, size_t lbracket, size_t rbracket)
	{
		//如果当前的str右括号个数大于左括号个数，右或者左括号个数超过总体的一半，则当前str非法
		if (rbracket>lbracket || lbracket>n || rbracket>n)
			return;
		if (rbracket == lbracket&&lbracket == n)
			//if(str.size()==2*n&&lbracket==n)
		{
			ret.push_back(str);

			return;
		}
		backtrack(n, ret, str += "(", lbracket + 1, rbracket);
		str.pop_back();
		backtrack(n, ret, str += ")", lbracket, rbracket + 1);
	}
};

int main()
{
	int n = 3;
	Solution s;
	s.generateParenthesis(n);
	return 0;
}