#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
//给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。

#if 0
思路：
1，去除重的字母
2.每个字母只出现且必须出现一次
3.字典序最小

前两者我们可以通过一个标志数组来完成，字母放入容器之后，该字母标志为true，没有放入则为false
通过遍历字符串s我们就可以去除重复的字母且每个字母都只出现一次

字典序最小
我们要插入的字符如果小于容器末尾的字符，则将容器末尾的字符取出，直至容器为空或者容器末尾的字符小于要插入的字符；
但特别要注意的是，如果容器末尾的字符在后续中不存在了，则该字符不能取出
#endif
class Solution {
public:
	string removeDuplicateLetters(string s) {
		if (s.empty())
			return "";
		//统计各个字母出现的次数
		vector<int> vv(26, 0);
		for (int i = 0; i<s.size(); ++i)
		{
			int index = s[i] - 'a' + 0;
			vv[index]++;
		}

		stack<char>  ss;
		//标志数组，栈中是否有该字母
		vector<bool> falg(26, false);
		for (int i = 0; i<s.size(); ++i)
		{
			
			int index = s[i] - 'a' + 0;
			vv[index] -= 1;
			//如果，栈中有该字母，则跳过，处理下一个
			if (falg[index] == true)
				continue;
			//要插入的字符如果小于容器末尾的字符，则将容器末尾的字符取出，直至容器为空或者容器末尾的字符小于要插入的字符；
			while (!ss.empty() && ss.top()>s[i])
			{
				//如果该字母在剩余遍历的字符串中不存在了，不能取出该字母
				if (vv[ss.top() - 'a'] == 0)
					break;
				falg[ss.top() - 'a'] = false;
				ss.pop();
			}
			//栈中没有存储该字母，则放入栈中
			if (falg[s[i] - 'a'] == false)
			{
				ss.push(s[i]);
				falg[s[i] - 'a'] = true;
			}
		}

		string ret;
		while (!ss.empty())
		{
			ret += ss.top();
			ss.pop();
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};
int main()
{
	Solution s;
	cout<<s.removeDuplicateLetters("cbacdcbc")<<endl;
	cout << s.removeDuplicateLetters("bbcaac") << endl;
	return 0;
}