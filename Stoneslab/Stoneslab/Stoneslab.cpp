#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	//将0~m的位置初始化为给定值
	vector<int> arr(m + 1, INT_MAX);
	//将n的这个位置进行差异化
	arr[n] = 0;
	for (int i = 0; i<m + 1; ++i)
	{
		if (arr[i] == INT_MAX)
			continue;

		for (int j = 2; j <= sqrt(i); ++j)
		{
			if (i%j == 0)//j是当前值的非1非本身的约数
			{
				if (i + j <= m)
					arr[i + j] = min(arr[i] + 1, arr[i + j]);
				if (i + i / j <= m)
					arr[i + i / j] = min(arr[i] + 1, arr[i + i / j]);

			}

		}


	}
	if (arr[m] == INT_MAX)
		cout << -1 << endl;
	else
		cout << arr[m] << endl;

	return 0;
}