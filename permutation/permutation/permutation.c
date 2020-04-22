#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//����һ���ַ�������ӡ�����ַ������ַ����������С������������˳�򷵻�����ַ������飬�����治�����ظ�Ԫ�ء�
//���룺s = "abc"
//�����["abc", "acb", "bac", "bca", "cab", "cba"]
vector<string> permutation(string s) {
	vector<string>ret;
	if (s.empty())
	{
		return ret;
	}
	set<string> str;//ʹ��set��ֹ���ظ���Ԫ�ء�

	BackTrack(str, s, 0);
	return vector<string>(str.begin(), str.end());

}
void BackTrack(set<string>&str, string& s, size_t Index)
{
	if (Index == s.size())
	{
		str.insert(s);
		return;
	}
	
	for (size_t i = Index; i<s.size(); ++i)
	{
		//��һ��Ԫ�غ�����Ԫ�����ν���
		swap(s[i], s[Index]);
		//����
		BackTrack(str, s, Index + 1);
		//������������Ϊԭ�������ӡ�
		swap(s[Index], s[i]);
	}
}

int main()
{
	char* s = "abc";
	int  n = 0;
	
	permutation(s);
	
	return 0;
}