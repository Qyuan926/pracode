#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

/*请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。

示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。

*/

class Solution {
public:
	bool isMatch(std::string s, std::string p) {
		if (p.empty()) {
			return s.empty();
		}

		// 前面加某一相同字符，
		// 防止 (ab, c*ab) 这样的匹配，
		// 避免复杂的初始化操作
		s = " " + s;
		p = " " + p;
		int m = s.size(), n = p.size();

		// 定义记忆数组，并初始化为false
		vector< std::vector<bool> > dp(m + 1, vector<bool>(n + 1, false));

		// 设添加的字符为真
		dp[0][0] = true;

		// 记忆数组能保持字符串上一个字符的状态
		// 因此可以对下一个字符进行判断
		for (int i = 1; i < m + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				// 不带 '*' 号时的匹配
				if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else if (p[j - 1] == '*')
				{
					// 考虑 '*' 时的两种情况
					if (s[i - 1] != p[j - 2] && p[j - 2] != '.')
					{
						dp[i][j] = dp[i][j - 2];
					}
					else
					{
						dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
					}
				}

			}

		}

		// 返回最后字符的匹配状态
		return dp[m][n];
	}
};

int main()
{
	Solution s;
	s.isMatch("ab", "c*ab");
	return 0;
}