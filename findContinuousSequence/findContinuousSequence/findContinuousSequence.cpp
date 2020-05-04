#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
/*输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
*/


//滑动窗口的方法
vector<vector<int>> findContinuousSequence(int target) {
	vector<vector<int>> ret;
	if (target <= 0)
	{
		return ret;
	}
	int left = 1;
	int right = 1;
	int sum = 0;
	while (left <= target / 2)
	{
		//如果sum<target,右边界向右滑动，增加sum
		if (sum<target)
		{
			sum += right;
			right++;
		}
		//如果sum>target,左边界向右滑动，减小sum
		else if (sum>target)
		{
			sum -= left;
			left++;
		}
		else
		{
			//如果满足条件，将结果记录下来，将窗口左移一下，形成新的窗口
			vector<int> arr;
			for (size_t i = left; i<right; ++i)
			{
				arr.push_back(i);
			}
			ret.push_back(arr);
			sum -= left;
			left++;
		}
		
	}
	return ret;
}



int main()
{

	vector<vector<int>> ret =findContinuousSequence(9);

	return 0;
}