#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<limits>
using namespace std;
int min(int x1, int x2)
{
	if (x1 > x2)
		return x2;
	else
		return x1;
}




	int numSquares(int n) {
		vector <int> Sequence(n + 1, 0);
		//����һ��n+1��Ԫ�ص����飬��ʼ��Ϊ0
		for (int i = 1; i <= n; ++i)
		{
			int minvalue = INT_MAX;
			for (int j = 1; j*j <= i; ++j)
				//��С��n��ƽ��

				minvalue = min(minvalue, Sequence[i - j*j]);
			//�����⻯����n��ƽ����Ӹ���ת��Ϊ {    ��n-j*j����ƽ����Ӹ���+1    }
			//�����꣬���һ�����Ž�

			Sequence[i] = minvalue + 1;
			//���Ž�+�Ǹ�����ƽ��=n
			//�ʣ����Ž��ƽ����Ӹ���+1=n��ƽ����Ӹ���
		}
		int ret=Sequence[n];
		return ret;
	}





int main()
{
	int num = 15;
 
 cout << numSquares(num) << endl;

	return 0;
}