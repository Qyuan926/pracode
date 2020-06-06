#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


/*

牛牛定义排序子序列为一个数组中一段连续的子序列,并且这段子序列是非递增或者非递减排序的。牛牛有一个长度为n的整数数组A,他现在有一个任务是把数组A分为若干段排序子序列,牛牛想知道他最少可以把这个数组分为几段排序子序列.
如样例所示,牛牛可以把数组A划分为[1,2,3]和[2,2,1]两个排序子序列,至少需要划分为2个排序子序列,所以输出2*/


int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (size_t i = 0; i<n; ++i)
	{
		cin >> arr[i];
	}
	//输入完成

	//处理问题主体
	size_t Index = 1;
	bool minflags = false;
	bool greaterflags = false;
	bool equal = false;
	int count = 0;
	while (Index<n)
	{
		minflags = false;
		greaterflags = false;
		while (Index<n&&arr[Index - 1]<arr[Index])
		{
			++Index;
			minflags = true;
		}
		if (minflags)
		{
			count++;
			++Index;

		}
		while (Index<n&&arr[Index - 1] == arr[Index])
		{
			++Index;
			equal = true;
		}

		while (Index<n&&arr[Index - 1]>arr[Index])
		{
			++Index;
			greaterflags = true;
		}
		if (greaterflags)
		{
			count++;

			++Index;
		}
		if ((Index == n) && (equal || greaterflags || minflags))
			count++;


	}
	cout << count << endl;
	return 0;
}