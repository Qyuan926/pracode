#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


int coinChange(vector<int>& coins, int amount) {
	if (coins.empty())
	{
		return -1;
	}
	vector <int > dp(amount + 1, amount + 1);
	dp[0] = 0;
	for (int i = 1; i<dp.size(); ++i)
	{
		for (int j = 0; j<coins.size(); ++j)
		{
			int flag = i - coins[j];
			if (flag<0)
				continue;
			dp[i] = min(dp[i], 1 + dp[flag]);

		}
	}
	return dp[amount] == amount + 1 ? -1 : dp[amount];
}

int main()
{
	int amount = 11;
	vector <int> coins(3);
	coins[0] = 1;
	coins[1] = 2;
	coins[2] = 5;
	cout << coinChange(coins, amount) << endl;
}