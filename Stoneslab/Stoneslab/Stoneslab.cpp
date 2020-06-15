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
	//��0~m��λ�ó�ʼ��Ϊ����ֵ
	vector<int> arr(m + 1, INT_MAX);
	//��n�����λ�ý��в��컯
	arr[n] = 0;
	for (int i = 0; i<m + 1; ++i)
	{
		if (arr[i] == INT_MAX)
			continue;

		for (int j = 2; j <= sqrt(i); ++j)
		{
			if (i%j == 0)//j�ǵ�ǰֵ�ķ�1�Ǳ����Լ��
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