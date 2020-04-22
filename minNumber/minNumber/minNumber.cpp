#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <algorithm>
#include<vector>
#include<string>
using namespace std;
//����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
class Solution {

public:
	string minNumber(vector<int>& nums) {
		//�������Ϊ�գ�ֱ�ӷ���
		if (nums.empty())
		{
			return nullptr;
		}
		vector<string> strnum;
		string retstr;
		//�������е�Ԫ��ת��Ϊ�ַ�������
		for (size_t i = 0; i<nums.size(); ++i)
		{
			strnum.push_back(to_string(nums[i]));
		}
		//��������
		sort(strnum.begin(), strnum.end(), StrCmp);
		//������õ�����ַ���
		for (size_t i = 0; i<strnum.size(); ++i)
		{
			retstr += strnum[i];
		}
		return retstr;
	}
	static bool StrCmp(string str1, string str2)
	{
		string str12 = str1 + str2;
		string str21 = str2 + str1;
		return str12<str21;
	}
};


