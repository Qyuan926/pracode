#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#if 0
С����һ�����ϵ���Ϸ�����������ž������Ϸ����˹���顣��Ϊ���ȽϹ��ϣ����Թ����һ��Ķ���˹���鲻ͬ��
ӫĻ��һ���� n �У�ÿ�ζ�����һ�� 1 x 1 �ķ���������£���ͬһ���У������µķ���������ǰ�ķ���֮�ϣ���һ���з��鶼��ռ��ʱ����һ�лᱻ��ȥ�����õ�1�֡�
��һ�죬С���ֿ���һ����Ϸ�����浽�� m ����������ʱ������̫���ľ͹ص��ˣ�С��ϣ��������������Ϸ����õķ�����
#endif
int main()
{
	int n, m;
	int c;
	while (cin >> n >> m)
	{
		int score = 0;

		int* C = new int[n + 1];
		int i = 0;
		for (i = 0; i<n + 1; i++)
		{
			C[i] = 0;
		}
		for (i = 0; i<m; i++)
		{
			cin >> c;
			C[c] += 1;
		}
		int min = C[1];
		for (i = 2; i<n + 1; i++)
		{
			if (min>C[i])
			{
				min = C[i];
			}
		}
		score = min;
		cout << score << endl;
		delete[] C;
	}
	return 0;
}