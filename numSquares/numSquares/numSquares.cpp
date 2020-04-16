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
		//申请一个n+1个元素的数组，初始化为0
		for (int i = 1; i <= n; ++i)
		{
			int minvalue = INT_MAX;
			for (int j = 1; j*j <= i; ++j)
				//求小于n的平方

				minvalue = min(minvalue, Sequence[i - j*j]);
			//将问题化简，求n的平方相加个数转化为 {    （n-j*j）的平方相加个数+1    }
			//遍历完，求出一个最优解

			Sequence[i] = minvalue + 1;
			//最优解+那个数的平方=n
			//故，最优解的平方相加个数+1=n的平方相加个数
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