#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include <algorithm>

//����һ���ַ�����һ������ k������Ҫ�Դ��ַ�����ͷ�����ÿ�� 2k ���ַ���ǰk���ַ����з�ת�����ʣ������ k ���ַ�����ʣ�������ȫ����ת�������С�� 2k �����ڻ���� k ���ַ�����תǰ k ���ַ�������ʣ����ַ�����ԭ����


using namespace std;
class Solution {
public:
	string reverseStr(string s, int k) {
		if (s.empty() || k <= 0)
		{
			return s;
		}
		//if(k>=s.size())     if(k<s.size<2k)
		//��תǰk���ַ�       k=s.size()            k=k
		//  s.size>2k    4k
		//    reverse(begin,begin+k)   begin+=k
		int n = 0;
		int flag = 1;
		while (n<s.size())
		{
			if (flag % 2 != 0)
			{
				//����flagԭ��
				//  1    2         3      4   
				//(0,k) (k,2k)  (2k,3k) (3k,4k)
				//ÿ2k��ǰk����ת������������ת��
				reverse(s.begin() + n, min(s.begin() + (n + k), s.end()));
			}
			flag++;
			n += k;
		}
		return s;
	}
};