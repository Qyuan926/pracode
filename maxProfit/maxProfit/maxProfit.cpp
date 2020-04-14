#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<vector>

int maxProfit(vector<int>& prices) 
{
	if (prices.empty())
	{
		return 0;
	}

	int Size = prices.size();
	int* ret = new int[Size];
	memset(ret, 0, sizeof(int)*Size);
	int min = prices[0];
	for (int i = 1; i<Size; ++i)
	{
		if (min>prices[i])
		{
			min = prices[i];
		}
		ret[i] = (prices[i] - min)>ret[i - 1] ? (prices[i] - min) : ret[i - 1];


	}
	int maxprofit = ret[Size - 1];
	delete[] ret;
	return maxprofit;
}