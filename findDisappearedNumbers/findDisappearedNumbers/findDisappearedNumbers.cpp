#define _CRT_SECURE_NO_WARNINGS 1

/*
给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。

找到所有在 [1, n] 范围之间没有出现在数组中的数字。

您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

*/

/*
思路一：
先将数组内的元素升序排序；声明一个元素count=1，表示从一开始，依次比较判断小时的数字
如果count和该位置对应元素相等，count++，判断下一个数是否存在
如果count比该位置对应元素大，也跳过，判断下一个位置
如果count比该位置元素小，说明有元素被跳过，将被跳过的元素保存起来

遍历完数组之后；
还要判断一下count是否等于数组大小
不等，说明有遗漏数据，再次判断并进行保存
*/
vector<int> findDisappearedNumbers1(vector<int>& nums) {
	vector<int> ret;
	if (nums.empty())
		return ret;
	int count = 1;
	sort(nums.begin(), nums.end());
	for (int i = 0; i<nums.size(); ++i)
	{
		if (count == nums[i])
		{
			count++;
		}
		else if (count<nums[i])
		{
			ret.push_back(count);
			count++;
			i = i - 1;
		}
	}
	while (count <= nums.size())
	{
		ret.push_back(count);
		count++;
	}
	return ret;
}

/*
循环判断数组，将该位置元素对应位置的元素值为负数
再次循环判断，存有整数的位置就是我们要找的消失的数字
*/

vector<int> findDisappearedNumbers(vector<int>& nums) {
	vector<int> ret;
	if (nums.empty())
		return ret;
	int index = nums.size();
	for (int i = 0; i<nums.size(); ++i)
	{
		if (nums[i]>0)
			index = nums[i] - 1;
		else
			index = -nums[i] - 1;

		if (nums[index]>0)
		{
			nums[index] = -nums[index];
		}
	}
	for (int i = 0; i<nums.size(); ++i)
	{
		if (nums[i]>0)
		{
			ret.push_back(i + 1);
		}
	}
	return ret;

}