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
		//����һ�����������ܷ���Ҫ��һ���������������1�������ܷ���Ҫ��
		//��������������ŵ����飬һ��������sum<mul��������������1�Ļ����������ڷ���Ҫ��ֱ��break
		else if (arr[i] == 1)
		{
			Luckybag(arr, i + 1, sum, mul, ret);
		}
		else
			break;
		sum -= arr[i];
		mul /= arr[i];
		//��������ͬʱ����Ҫȥ��һ��������ͬ�Ĳ��֡�
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
		cin >> arr[i];//ȫ��Ϊ������
	}
	int ret = 0;
	sort(arr.begin(), arr.end());
	Luckybag(arr, 0, sum, mul, ret);
	cout << ret << endl;
	return 0;

}