#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
输入: "pwwkew"
输出 : 3
解释 : 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。*/




	int lengthOfLongestSubstring(string s) {
		vector<int> Hash(256, 0);
		int right = 0;
		int left = 0;
		int retlen = 0;
		for (; right<s.size(); ++right)
		{
			//记录右侧窗口元素出现的次数
			Hash[s[right]]++;
			//该元素如果出现一次以上，缩小窗口，直至窗口内每个元素出现的次数全为1；
			while (left<right&&Hash[s[right]]>1)
			{
				Hash[s[left]]--;
				++left;
			}
			retlen = max(retlen, right - left + 1);
		}
		return retlen;
	}

	int main()
	{
		string  str1 = "aaaaaaaa";
		cout << lengthOfLongestSubstring(str1) << endl;
		string str2 = "pwwkew";
		cout << lengthOfLongestSubstring(str2) << endl;
		string str3 = "abcabcbb";
		cout << lengthOfLongestSubstring(str3) << endl;
	}