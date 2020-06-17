#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
int Pathsum(int n, int m)
{
	if (n == 0 || m == 0)
		return 0;
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));

	for (int i = 1; i<n + 1; ++i)
	{
		for (int j = 1; j<m + 1; ++j)
		{
			if (i == 1 || j == 1)
				dp[i][j] = i + j;
			else
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[n][m];
}







int Pathsum1(int n, int m)
{
	if (n == 0 || m == 0)
		return 0;
	vector<int>dp(m + 1);
	int k = 1;
	while (k<n + 1)
	{
		for (int i = 1; i<m + 1; ++i)
		{
			if (k == 1 || i == 1)
				dp[i] = k + i;
			else
				dp[i] = dp[i - 1] + dp[i];

		}
		k++;
	}
	return dp[m];
}


int main()
{
	int n, m;
	while (cin >> n >> m)
		cout << Pathsum(n, m) << endl;
	return 0;
}