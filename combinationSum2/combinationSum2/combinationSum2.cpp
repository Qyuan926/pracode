#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
[1,2,2],
[5]
]
*/

	class Solution {
	public:
		vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
			vector<vector<int>> ret;
			if (candidates.empty())
			{
				return ret;
			}
			vector<int> arr;
			sort(candidates.begin(), candidates.end());
			Bracktrace(candidates, 0, arr, target, 0, ret);
			return ret;
		}
		void Bracktrace(vector<int>& candidates, int Index, vector<int>& arr, int target, int sum, vector<vector<int>>& ret)
		{
			if (sum>target)
			{
				return;
			}
			if (sum == target)
			{

				ret.push_back(arr);
				return;
			}
			for (int i = Index; i<candidates.size(); ++i)
			{
				//剪枝、剪去不同位置，且相同的元素使用多次
				// 1  2 2 2   target=5
				
				if (i>Index&&candidates[i - 1] == candidates[i])
					continue;
				arr.push_back(candidates[i]);
				sum += candidates[i];
				Bracktrace(candidates, i + 1, arr, target, sum, ret);
				sum -= candidates[i];
				arr.pop_back();
			}

		}
	};


int main()
{
	Solution s;
	vector<int> arr = { 2, 5, 2, 1, 2 };

	s.combinationSum2(arr, 5);


	return 0;
}

