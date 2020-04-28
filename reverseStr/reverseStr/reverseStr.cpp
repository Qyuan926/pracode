#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include <algorithm>

//给定一个字符串和一个整数 k，你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转。如果剩余少于 k 个字符，则将剩余的所有全部反转。如果有小于 2k 但大于或等于 k 个字符，则反转前 k 个字符，并将剩余的字符保持原样。


using namespace std;
class Solution {
public:
	string reverseStr(string s, int k) {
		if (s.empty() || k <= 0)
		{
			return s;
		}
		//if(k>=s.size())     if(k<s.size<2k)
		//翻转前k个字符       k=s.size()            k=k
		//  s.size>2k    4k
		//    reverse(begin,begin+k)   begin+=k
		int n = 0;
		int flag = 1;
		while (n<s.size())
		{
			if (flag % 2 != 0)
			{
				//设置flag原因
				//  1    2         3      4   
				//(0,k) (k,2k)  (2k,3k) (3k,4k)
				//每2k的前k个旋转，即奇数次旋转。
				reverse(s.begin() + n, min(s.begin() + (n + k), s.end()));
			}
			flag++;
			n += k;
		}
		return s;
	}
};