#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;

namespace Solution{
	//������  O��N^2�� 
	string longestPalindrome(string s) {
		if (s.empty() || s.size()<2)
		{
			return s;
		}
		string ret = "";
		string tmp = "";
		for (size_t i = 0; i<s.size(); ++i)
		{
			for (size_t j = i; j<s.size(); ++j)
			{
				tmp += s[j];
				string reverse_tmp = tmp;
				reverse(reverse_tmp.begin(), reverse_tmp.end());
				//�����ת���ַ�����ԭ�ַ�����ͬ����Ϊ�����ַ������򷵻س��ȴ����һ��
				if (reverse_tmp == tmp)
					ret = ret.size()>tmp.size() ? ret : tmp;
			}
			tmp = "";
		}

		return ret;
	}

}



string longestPalindrome1(string s) {
	int n = s.size();
	string res = "";
	int len = 0;  //len������¼��ǰ��Ļ����Ӵ�
	if (s.size() == 0) return res;
	if (s.size() == 1)return s;

	res = s[0];//�����Ӵ���ʼ��Ϊ��һ��Ԫ��
	vector<vector<int>> dp(n, vector<int>(n));
	for (int j = 0; j<n; j++) {
		for (int i = j; i >= 0; i--){

			                        //j-i<=2��������ԭ���������Ĵ���ż�����Ĵ�
			if ((s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1]))

			{
				dp[i][j] = 1;
				if (j - i>len)
				{
					res = s.substr(i, j - i + 1);
					len = j - i;
				}
			}
		}
	}
	return res;
}

string longestPalindrome(string s) {
	if (s.empty() || s.size() <= 1)
	{
		return s;
	}
	int startIndex = 0;
	int maxstrlen = 0;

	//����ż�����Ļ����ַ���
	for (int i = 0; i<s.size(); ++i)
	{
		if (s[i] == s[i + 1])
		{
			int gap = 1;
			while ((i - gap >= 0) && (i + gap + 1<s.size()) && (s[i - gap] == s[i + gap + 1]))
			{
				gap++;
			}
			if (2 * gap>maxstrlen)
			{
				startIndex = i - gap + 1;
				maxstrlen = 2 * gap;
			}

		}
	}
	//�����������Ļ����ַ���
	for (int i = 0; i<s.size() - 2; ++i)
	{
		if (s[i] == s[i + 2])
		{
			int gap = 1;
			
			while ((i - gap >= 0) && (i + 2 + gap<s.size()) && (s[i - gap] == s[i + 2 + gap]))
			{
				gap++;
			}
			if (2 * gap + 1>maxstrlen)
			{
				startIndex = i - gap + 1;
				maxstrlen = 2 * gap + 1;
			}

		}
	}
	if (maxstrlen == 0)
	{
		maxstrlen = 1;
	}

	return s.substr(startIndex, maxstrlen);
}


int main()
{
	string str = "babad";
	cout << longestPalindrome(str) << endl;
}