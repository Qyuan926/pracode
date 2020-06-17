#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void Luckybag(vector<int>& arr, int Index, long long sum, long long mul, int& ret)
{

	for (int i = Index; i<arr.size(); ++i)
	{
		sum += arr[i];
		mul *= arr[i];
		if (sum>mul)
		{
			ret = ret + 1;
			Luckybag(arr, i + 1, sum, mul, ret);
		}
		//单独一个数，不可能符合要求；一组数中如果不含有1，不可能符合要求
		//由于我们是排序号的数组，一组数据中sum<mul如果加入的数不是1的话，不可能在符合要求直接break
		else if (arr[i] == 1)
		{
			Luckybag(arr, i + 1, sum, mul, ret);
		}
		else
			break;
		sum -= arr[i];
		mul /= arr[i];
		//两个数相同时，需要去除一个两棵相同的部分。
		while (i<arr.size() && arr[i] == arr[i + 1])
			++i;
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	long long mul = 1;
	long long sum = 0;
	for (size_t i = 0; i<n; ++i)
	{
		cin >> arr[i];//全部为正整数
	}
	int ret = 0;
	sort(arr.begin(), arr.end());
	Luckybag(arr, 0, sum, mul, ret);
	cout << ret << endl;
	return 0;

}