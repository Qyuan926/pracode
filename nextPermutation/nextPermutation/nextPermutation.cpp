#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*找出这个数组排序出的所有数中，刚好比当前数大的那个数

比如当前 nums = [1,2,3]。这个数是123，找出1，2，3这3个数字排序可能的所有数，排序后，比123大的那个数 也就是132

如果当前 nums = [3,2,1]。这就是1，2，3所有排序中最大的那个数，那么就返回1，2，3排序后所有数中最小的那个，也就是1，2，3 -> [1,2,3]
*/
void nextPermutation(vector<int>& nums) {
	if (nums.empty())
	{
		return;
	}
	//找到当前位置的数值比他前一个位置大的情况
	int i = nums.size() - 1;
	for (; i >= 1; --i)
	{
		if (nums[i]>nums[i - 1])
			break;
	}
	//没有通过break退出，即当前数组代表的是最大的情况，排序是数组称为能代表的最小的数字
	if (i == 0)
	{
		sort(nums.begin(), nums.end());
	}
	else
	{
		//cur=i;从cur位置开始,找到大于cur-1位置的值的最小值的位置
		int prev = i - 1;
		int min = i;
		for (; i<nums.size(); ++i)
		{
			if (nums[i]>nums[prev] && nums[min]>nums[i])
				min = i;
		}
		//交换prev位置和min位置（是cur位置以其位置以后大于prev位置值的最小的一个）的值
		swap(nums[prev], nums[min]);
		//将prev位置之后的数组排列成代表数字最小的情况
		sort(nums.begin() + prev + 1, nums.end());
	}
}

int main()
{
	vector<int> arr = { 2,3,1 };
	nextPermutation(arr);
	return 0;
}