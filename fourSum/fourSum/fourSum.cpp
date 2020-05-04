#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
四数之和
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

*/

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> ret;
	if (nums.size()<4)
	{
		return ret;
	}
	//对数组元素进行排序
	sort(nums.begin(), nums.end());

	int size = nums.size();
	for (int Index1 = 0; Index1<size - 3; ++Index1)
	{   //将四数之和转换为三数之和问题
		//去重、如果Index1不是初始位置，且与前一位置的值相同跳过本次操作
		if (Index1>0 && nums[Index1] == nums[Index1 - 1])
			continue;
		for (int Index2 = Index1 + 1; Index2<size - 2; ++Index2)
		{
			//将三数之和转换为两数之和问题
			//去重、如果Index1不是初始位置，且与前一位置的值相同跳过本次操作
			if (Index2>Index1 + 1 && nums[Index2] == nums[Index2 - 1])
				continue;
			int Index3 = Index2 + 1;
			int Index4 = size - 1;
			int tar = target - nums[Index1] - nums[Index2];
			//在有序数组中寻找两数之和为tar值的情况
			while (Index3<Index4)
			{
				int  sum = nums[Index3] + nums[Index4];
				if (sum == tar)
				{
					
					ret.push_back(vector<int>{nums[Index1], nums[Index2], nums[Index3], nums[Index4]});
					//去重操作
					while (Index3<size - 2 && nums[Index3] == nums[Index3 + 1])
					{
						++Index3;
					}
					while (Index4>Index2&&nums[Index4] == nums[Index4 - 1])
					{
						--Index4;
					}
					++Index3;
					--Index4;
				}
				else if (sum>tar)
				{
					--Index4;
				}
				else
				{
					++Index3;
				}
			}

		}
	}
	return ret;
}

int main()
{
	vector<int> arr{ 0, 0, 0, 0 };
	fourSum(arr, 0);
	return 0;
}