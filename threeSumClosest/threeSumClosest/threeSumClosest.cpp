#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

*/
int threeSumClosest(vector<int>& nums, int target) {
	if (nums.size()<3)
	{
		return 0;
	}
	//给数组元素排好序
	sort(nums.begin(), nums.end());
	//排序好的数组，前三个元素之和最小，target<min则直接返回
	int min = nums[0] + nums[1] + nums[2];
	if (min>target)
		return min;
	//排序好的数组，最后三个元素之和最大，target>max直接返回
	size_t size = nums.size();
	int max = nums[size - 1] + nums[size - 2] + nums[size - 3];
	if (max<target)
		return max;
	//可以将问题转换为数组中两数之和为tar的问题
	int ret = min;
	for (size_t cur = 0; cur<nums.size() - 2; ++cur)
	{
		int tar = target - nums[cur];
		size_t begin = cur + 1;
		size_t end = size - 1;
		while (begin<end)
		{

			//找到了三数之和为target的情况
			if (nums[begin] + nums[end] == tar)
			{
				return target;
			}
			else
			{
				int sum = nums[cur] + nums[begin] + nums[end];
				if (abs(ret - target)>abs(sum - target))
					ret = sum;
				if (nums[begin] + nums[end]>tar)
					--end;
				else
					++begin;
			}
		}
	}
	return ret;
}