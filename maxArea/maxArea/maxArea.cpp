#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
盛最多水的容器
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和(i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
*/


int maxArea(vector<int>& height) {
	int left = 0;
	int right = height.size() - 1;
	int maxarea = 0;
	while (left<right)
	{
		int h = min(height[left], height[right]);
		int area = h*(right - left);
		if (area>maxarea)
		{
			maxarea = area;
		}
		if (h == height[left])
		{
			++left;
		}
		else
		{
			--right;
		}
	}
	return maxarea;
}


int main()
{
	vector<int> arr = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	cout << maxArea(arr) << endl;
}