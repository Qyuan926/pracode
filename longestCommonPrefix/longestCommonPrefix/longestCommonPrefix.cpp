#define _CRT_SECURE_NO_WARNINGS 1
#include<string>
#include<iostream>
#include<vector>
using namespace std;
/*编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
string longestCommonPrefix(vector<string>& strs) {
	string ret;
	if (strs.empty())
		return ret;
	int minlen = strs[0].size();
	for (int i = 0; i<strs.size(); ++i)
	{
		if (minlen>strs[i].size())
		{
			minlen = strs[i].size();
		}
	}
	for (int i = 0; i<minlen; ++i)
	{
		char c = strs[0][i];
		for (int j = 1; j<strs.size(); ++j)
		{
			if (c != strs[j][i])
				return ret;
		}
		ret += c;

	}
	return ret;
}


int main()
{
	//vector<string> arr = { "flower", "flow", "flight" };
	vector<string> arr = { "aca", "cba" };
	cout << longestCommonPrefix(arr) << endl;
}