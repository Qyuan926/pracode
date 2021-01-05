#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


	void Jump(vector<int>& nums, int index, bool& flag, vector<int>& visited)
	{
		if (index >= nums.size() - 1)
		{
			flag = true;
			return;
		}
		int num = nums[index];
		for (int i = num; i >= 1; --i)
		{
			if (visited[i] == 1)
				Jump(nums, index + i, flag, visited);
		}
		if (index<nums.size())
		visited[index] = 0;
		return;
	}

	bool canJump(vector<int>& nums) {
		if (nums.empty())
			return false;
		vector<int> visited(nums.size(), 1);
		bool flag = false;
		Jump(nums, 0, flag, visited);
		return flag;

	}



int main()
{
	vector<int> vv = {
		3, 0, 8, 2, 0, 0, 1
	};
	cout << canJump(vv) << endl;
	return 0;
}