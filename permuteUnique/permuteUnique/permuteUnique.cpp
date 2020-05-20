#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*/

class Solution {

public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		if (nums.empty())
			return _ret;
		sort(nums.begin(), nums.end());
		_nums = nums;
		vector<bool> flags(nums.size(), false);
		trackback(flags);
		return _ret;
	}
private:
	void trackback(vector<bool>& flags)
	{
		if (_arr.size() == _nums.size())
		{
			_ret.push_back(_arr);
			return;
		}
		for (size_t i = 0; i<_nums.size(); ++i)
		{
			if (flags[i] == true)
			{//如果当前的数值已经被使用了，直接跳过，防止重复使用
				continue;
			}
			if (i>0 && _nums[i - 1] == _nums[i] && flags[i - 1] == false) //当前数值和前一个数值相等、并且回溯完，前一个值没有被使用，此时应该跳过放置造成重复的结果
				continue;
			//剪枝完毕了
			_arr.push_back(_nums[i]);
			flags[i] = true;
			trackback(flags);
			_arr.pop_back();
			flags[i] = false;
		}

	}
private:
	vector<vector<int>> _ret;
	vector<int> _nums;
	vector<int> _arr;
};