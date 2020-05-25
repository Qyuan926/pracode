#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;
/*给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m] 。
请问 k[0]*k[1]*...*k[m] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18

*/

//动态规划：将长度为n的一段分成len和n-len长度；这两段还可以继续分，找到最大的值。
// dp[n]=max{dp[len]*dp[n-len],dp[n]};
// 特殊情况 cuttingRope（2）=1<2, 这种情况不能继续分,也就是无法使用上面的公式。我们需要对此进行调节
int cuttingRope(int n) {
	vector<int> arr(n + 1, 0);
	arr[1] = 1;
	for (int len = 2; len <= n; ++len)
	{
		int i = 1;
		for (i = 1; i <= len / 2; ++i)
		{
			arr[len] = max(arr[len], arr[len - i] * arr[i]);
		}
		if (i != n)
			arr[len] = max(arr[len], len);
	}
	return arr[n];

}

int main()
{
	cuttingRope(10);
	return 0;
}