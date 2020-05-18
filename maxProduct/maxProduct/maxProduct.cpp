#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//数组元素一次相乘,乘积为mul
	//相邻的情况
	//mul>0, 下一个元素大于0相乘 ，最大乘积可能改变，     其余情况，最大乘积不变
	//mul<0 ,下一个元素小于等于0相乘，最大乘积可能改变，   大于0，最大乘积不变
	//mul==0,一次更新元素 
	//间隔的特殊情况
	//    -3   4   -5  
	//最大乘积可能改变的情况    max*nums[i]   min*nums[i]   nums[i]
	int maxProduct(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int maxmul = nums[0];
		int minmul = nums[0];
		int ret = nums[0];
		for (int i = 1; i<nums.size(); ++i)
		{
			int ma = maxmul;
			int mi = minmul;
			maxmul = max(max(ma*nums[i], mi*nums[i]), nums[i]);
			minmul = min(min(ma*nums[i], mi*nums[i]), nums[i]);
			ret = max(maxmul, ret);
		}
		return ret;
	}
};



int main()
{
	vector<int> arr = { -4, -3, -2};
	Solution s;
	cout<<s.maxProduct(arr) << endl;
	return 0;

}