#define _CRT_SECURE_NO_WARNINGS 1
/*链接：https://www.nowcoder.com/questionTerminal/5fe02eb175974e18b9a546812a17428e
来源：牛客网

给定数组 arr 和整数 num，共返回有多少个子数组满足如下情况：
max(arr[i...j] - min(arr[i...j]) <= num
max(arr[i...j])表示子数组arr[i...j]中的最大值，min[arr[i...j])表示子数组arr[i...j]中的最小值。
两个双端队列解决问题*/
#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n, num;
	cin >> n >> num;
	vector<int> arr(n);
	for (int i = 0; i<n; ++i)
	{
		cin >> arr[i];
	}
	deque<int>  minque;
	deque<int>  maxque;
	int i = 0, j = 0, ret = 0;
	while (i<n)
	{
		while (j<n)
		{
			while (!minque.empty() && arr[minque.back()] >= arr[j])
			{
				minque.pop_back();
			}
			minque.push_back(j);
			while (!maxque.empty() && arr[maxque.back()] <= arr[j])
			{
				maxque.pop_back();
			}
			maxque.push_back(j);
			if (arr[maxque.front()] - arr[minque.front()]>num)
			{
				break;
			}
			++j;
		}

		if (minque.front() == i)
		{
			minque.pop_front();
		}
		if (maxque.front() == i)
		{
			maxque.pop_front();
		}
		ret += j - i;
		++i;

	}
	cout << ret << endl;
	return 0;

}