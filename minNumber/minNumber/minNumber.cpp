#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <algorithm>
#include<vector>
#include<string>
using namespace std;
//输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
class Solution {

public:
	string minNumber(vector<int>& nums) {
		//如果数组为空，直接返回
		if (nums.empty())
		{
			return nullptr;
		}
		vector<string> strnum;
		string retstr;
		//将数组中的元素转换为字符串类型
		for (size_t i = 0; i<nums.size(); ++i)
		{
			strnum.push_back(to_string(nums[i]));
		}
		//进行排序
		sort(strnum.begin(), strnum.end(), StrCmp);
		//将排序好的组成字符串
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


