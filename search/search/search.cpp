#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>

using namespace std;
/*假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4

*/
int search(vector<int>& nums, int target) {
	if (nums.empty())
		return -1;
	int begin = 0;
	int end = nums.size() - 1;
	int mid = begin + ((end - begin) >> 1);
	int pos = 0;
	//找到pos位置
	while (begin <= end)
	{
		mid = begin + ((end - begin) >> 1);
		if (nums[mid] >= nums[0])
		{
			begin = mid + 1;
		}
		else
		{
			pos = mid;
			end = mid - 1;
		}

	}
	//pos可能被找到，即发生了旋转
	//pos没有被找到，数组未发生过旋转
	//if (pos == 0)//pos=0 可能找到了在0的位置，可能没有找到
	//{
	//	begin = 0;
	//	end = nums.size() - 1;
	//}
	//else if (nums[0] <= target)
	//{
	//	begin = 0;
	//	end = pos - 1;
	//}
	//else //nums[begin]>target
	//{
	//	begin = pos;
	//	end = nums.size() - 1;
	//}
	if (pos == 0||nums[0]>target)//pos=0 可能找到了在0的位置，可能没有找到
	{
		begin = pos;
		end = nums.size() - 1;
	}
	else 
	{
		begin = 0;
		end = pos - 1;
	}
	

	while (begin <= end)
	{
		mid = begin + ((end - begin) >> 1);
		if (nums[mid] == target)
		{
			return mid;
		}
		else if (nums[mid]>target)
		{
			end = mid - 1;

		}
		else{
			begin = mid + 1;
		}
	}
	return -1;
}
int search1(vector<int>& nums, int target) {
	int numssize = nums.size();
	if (numssize == 0)
		return -1;
	if (numssize == 1)
	{
		if (nums[0] == target)
			return 0;
		else
			return -1;
	}
	int begin = 0;
	int end = numssize - 1;
	while (begin <= end)
	{
		int mid = begin + ((end - begin) >> 1);
		if (nums[mid] == target)
		{
			return mid;
		}
		if (nums[0] <= nums[mid])
		{//mid前的数组有序
			if (nums[0] <= target&&target<nums[mid])
			{//target在mid前有序的数组段
				begin = 0;
				end = mid - 1;
			}
			else
			{  //target在mid后面的序列段（可能有序，可能无序）
				begin = mid + 1;
			}

		}
		else
		{
			//mid后的数组有序
			if (nums[mid]<target&&target <= nums[numssize - 1])
			{
				begin = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
	}
	return -1;
}

int main()
{
	vector<int> arr = { 4, 5, 6, 7, 0, 1, 2 };
	cout<<search(arr,0)<<endl;
	return 0;
}
