#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

/*��ʵ��һ����������ƥ�����'. '��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ���0�Σ����ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬����"aa.a"��"ab*a"����ƥ�䡣

ʾ�� 1:

����:
s = "aa"
p = "a"
���: false
����: "a" �޷�ƥ�� "aa" �����ַ�����

*/

class Solution {
public:
	bool isMatch(std::string s, std::string p) {
		if (p.empty()) {
			return s.empty();
		}

		// ǰ���ĳһ��ͬ�ַ���
		// ��ֹ (ab, c*ab) ������ƥ�䣬
		// ���⸴�ӵĳ�ʼ������
		s = " " + s;
		p = " " + p;
		int m = s.size(), n = p.size();

		// ����������飬����ʼ��Ϊfalse
		vector< std::vector<bool> > dp(m + 1, vector<bool>(n + 1, false));

		// ����ӵ��ַ�Ϊ��
		dp[0][0] = true;

		// ���������ܱ����ַ�����һ���ַ���״̬
		// ��˿��Զ���һ���ַ������ж�
		for (int i = 1; i < m + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				// ���� '*' ��ʱ��ƥ��
				if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else if (p[j - 1] == '*')
				{
					// ���� '*' ʱ���������
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

		// ��������ַ���ƥ��״̬
		return dp[m][n];
	}
};

int main()
{
	Solution s;
	s.isMatch("ab", "c*ab");
	return 0;
}