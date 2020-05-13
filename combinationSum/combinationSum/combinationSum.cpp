#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
/*给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]

*/
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int> > ret;
		vector<int>arr;
		backtrace(ret, arr, 0, candidates, 0, target);
		return ret;

	}
	void backtrace(vector<vector<int>>& ret, vector<int> arr, int arrsum, vector<int>& candidates, int Index, int target)
	{
		//arrsum记录存储在数组中的元素之和
		//arrsum>target时，直接返回，当前数组中的元素绝不不符合条件
		if (arrsum>target)
		{
			return;
		}
		else if (arrsum == target)//相等时，符合要求，直接记录到返回结果里面
		{
			ret.push_back(arr);
		}
		for (int i = Index; i<candidates.size(); ++i)
		{
			arr.push_back(candidates[i]);
			arrsum += candidates[i];
			backtrace(ret, arr, arrsum, candidates, i, target);//回溯时，我们为了避免出现重复的情况，每次回溯都从包含当前位置开始往后回溯，不在判断前面的元素
			arr.pop_back();
			arrsum -= candidates[i];
		}

	}
};


int main()
{
	Solution s;
	vector<int> arr = { 2, 3, 6, 7 };
	s.combinationSum(arr, 7);

	return 0;
}