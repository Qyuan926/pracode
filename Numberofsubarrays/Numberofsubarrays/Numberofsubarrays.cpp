#define _CRT_SECURE_NO_WARNINGS 1
/*���ӣ�https://www.nowcoder.com/questionTerminal/5fe02eb175974e18b9a546812a17428e
��Դ��ţ����

�������� arr ������ num���������ж��ٸ��������������������
max(arr[i...j] - min(arr[i...j]) <= num
max(arr[i...j])��ʾ������arr[i...j]�е����ֵ��min[arr[i...j])��ʾ������arr[i...j]�е���Сֵ��
����˫�˶��н������*/
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