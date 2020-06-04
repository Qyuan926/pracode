#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*有一个整型数组arr和一个大小为w的窗口从数组的最左边滑到最右边，
窗口每次向右边滑一个位置，求每一种窗口状态下的最大值。（如果数组长度为n，窗口大小为w，则一共产生n-w+1个窗口的最大值）
8 3
4 3 5 4 3 3 6 7*/


int main()
{
	int n;
	int windowsize;
	cin >> n >> windowsize;

	vector<int> arr(n);
	vector<int> ret;
	deque<int>  que;
	for (int i = 0; i<n; ++i)
	{
		cin >> arr[i];
	}
	//函数解决问题的主体
	//如果双端队列是空的直接放入
	//如果双端队列不是空的 进行比较
	//这个数小于双端队列尾部，直接放入，
	//大于双端队列尾部，弹元素，重复上述规则
	for (int j = 0; j<n; ++j)
	{
		
		while (!que.empty() && arr[que.back()] <= arr[j])
		{
			que.pop_back();
		}
		que.push_back(j);

		if (que.front() == j - windowsize)
			que.pop_front();

		if (j >= windowsize - 1)
		{
			ret.push_back(arr[que.front()]);
		}

	}
	for (size_t k = 0; k<ret.size(); ++k)
	{
		cout << ret[k] << " ";
	}
	cout << endl;


	return 0;
}