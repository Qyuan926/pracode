#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
//����һ���ַ��� s ������ȥ���ַ������ظ�����ĸ��ʹ��ÿ����ĸֻ����һ�Ρ��豣֤ ���ؽ�����ֵ�����С��Ҫ���ܴ��������ַ������λ�ã���

#if 0
˼·��
1��ȥ���ص���ĸ
2.ÿ����ĸֻ�����ұ������һ��
3.�ֵ�����С

ǰ�������ǿ���ͨ��һ����־��������ɣ���ĸ��������֮�󣬸���ĸ��־Ϊtrue��û�з�����Ϊfalse
ͨ�������ַ���s���ǾͿ���ȥ���ظ�����ĸ��ÿ����ĸ��ֻ����һ��

�ֵ�����С
����Ҫ������ַ����С������ĩβ���ַ���������ĩβ���ַ�ȡ����ֱ������Ϊ�ջ�������ĩβ���ַ�С��Ҫ������ַ���
���ر�Ҫע����ǣ��������ĩβ���ַ��ں����в������ˣ�����ַ�����ȡ��
#endif
class Solution {
public:
	string removeDuplicateLetters(string s) {
		if (s.empty())
			return "";
		//ͳ�Ƹ�����ĸ���ֵĴ���
		vector<int> vv(26, 0);
		for (int i = 0; i<s.size(); ++i)
		{
			int index = s[i] - 'a' + 0;
			vv[index]++;
		}

		stack<char>  ss;
		//��־���飬ջ���Ƿ��и���ĸ
		vector<bool> falg(26, false);
		for (int i = 0; i<s.size(); ++i)
		{
			
			int index = s[i] - 'a' + 0;
			vv[index] -= 1;
			//�����ջ���и���ĸ����������������һ��
			if (falg[index] == true)
				continue;
			//Ҫ������ַ����С������ĩβ���ַ���������ĩβ���ַ�ȡ����ֱ������Ϊ�ջ�������ĩβ���ַ�С��Ҫ������ַ���
			while (!ss.empty() && ss.top()>s[i])
			{
				//�������ĸ��ʣ��������ַ����в������ˣ�����ȡ������ĸ
				if (vv[ss.top() - 'a'] == 0)
					break;
				falg[ss.top() - 'a'] = false;
				ss.pop();
			}
			//ջ��û�д洢����ĸ�������ջ��
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