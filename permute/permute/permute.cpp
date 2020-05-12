#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
/*给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ret;
		if (nums.size() <= 1)
		{
			ret.push_back(nums);
			return ret;
		}
		backtrack(ret, nums, 0);
		return ret;
	}
	void backtrack(vector<vector<int>>& ret, vector<int>& nums, int index)
	{
		if (index == nums.size())
		{
			ret.push_back(nums);
			return;
		}
		for (int Index = index; Index<nums.size(); ++Index)
		{
			swap(nums[index], nums[Index]);
			backtrack(ret, nums, index + 1);
			swap(nums[index], nums[Index]);

		}
	}
};

int main()
{
	vector<int> arr = { 1, 2 };
	Solution s;
	s.permute(arr);
	return 0;
}