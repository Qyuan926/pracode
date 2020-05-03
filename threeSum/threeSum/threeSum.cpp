#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> ret;
	//将数组元素排好序
	sort(nums.begin(), nums.end());
	//将问题转换为在数组中虚招两数之和为target值的问题
	size_t cur = 0;
	while (cur<nums.size())
	{
		//如果cur位置的数值大于0，则不可能满足条件：三数之和为零；直接break掉
		if (nums[cur]>0)
		{
			break;
		}
		
		
			//利用双向指针查找复杂度n^2
			size_t begin = cur + 1;
			size_t end = nums.size() - 1;
			while (begin<end)
			{
				if (nums[begin] + nums[end]<-nums[cur])
				{
					++begin;
				}
				else if (nums[begin] + nums[end] == -nums[cur])
				{    //去掉重复的数组
					//去掉cur重复的数组[-1,0,1,2,-1,-4]
					if (cur == 0 || (cur>0 && nums[cur] != nums[cur - 1]))
					{
						if (begin == cur + 1)
						{
							vector<int > arr;
							arr.push_back(nums[cur]);
							arr.push_back(nums[begin]);
							arr.push_back(nums[end]);
							ret.push_back(arr);
							arr.clear();

						}
						//去掉cur不变，其余两个元素重复的数组[-2,0,0,2,2]
						else if (nums[begin] != nums[begin - 1])
						{
							vector<int > arr;
							arr.push_back(nums[cur]);
							arr.push_back(nums[begin]);
							arr.push_back(nums[end]);
							ret.push_back(arr);
							arr.clear();
						}
					}
					++begin;
					--end;

				}
				else
				{
					--end;
				}
			
		}
		++cur;
	}
	return ret;

}


int main()
{
	vector<int> arr = { -1, 0, 1, 2, -1, -4 };
	threeSum(arr);
}