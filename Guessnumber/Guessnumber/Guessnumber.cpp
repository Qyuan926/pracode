#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*

牛牛和羊羊在玩一个有趣的猜数游戏。在这个游戏中,牛牛玩家选择一个正整数,羊羊根据已给的提示猜这个数字。第i个提示是"Y"或者"N",表示牛牛选择的数是否是i的倍数。
例如,如果提示是"YYNYY",它表示这个数使1,2,4,5的倍数,但不是3的倍数。
注意到一些提示会出现错误。例如: 提示"NYYY"是错误的,因为所有的整数都是1的倍数,所以起始元素肯定不会是"N"。此外,例如"YNNY"的提示也是错误的,因为结果不可能是4的倍数但不是2的倍数。
现在给出一个整数n,表示已给的提示的长度。请计算出长度为n的合法的提示的个数。
例如 n = 5:
合法的提示有:
YNNNN YNNNY YNYNN YNYNY YYNNN YYNNY
YYNYN YYNYY YYYNN YYYNY YYYYN YYYYY
所以输出12

输入描述:
输入包括一个整数n(1 ≤ n ≤ 10^6),表示已给提示的长度。


输出描述:
输出一个整数,表示合法的提示个数。因为答案可能会很大,所以输出对于1000000007的模
*/

const int mod = 1000000007;
const int N = 1000001;

int Fun(int& n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	long long  ret = 1;
	vector<int> arr(N, 1);
	//查找n区间内的素数
	for (size_t i = 2; i <= n; ++i)
	{
		if (arr[i])//是素数进入
		{
			for (int j = 2 * i; j <= n; j += i)
			{
				arr[j] = 0;
			}
		}
		else
			continue;
		long long pow = i;
		long long powIndex = 1;
		while (pow <= n)
		{
			pow *= i;
			powIndex++;
		}
		ret = ret*powIndex%mod;
	}
	return (int)ret;
}
int main(){
	int n;
	while (cin >> n)
	{
		int ret = Fun(n);
		cout << ret << endl;
	}

	return 0;
}
#if 0
const int mod = 1000000007;
bool isprime(int num)
{
	if (num<2)
		return false;
	for (int i = 2; i <= sqrt(num); ++i)
	{
		if (num%i == 0 && num != 2)
			return false;
	}
	return true;
}


int Fun(int& n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	long long  ret = 1;
	vector<int> arr;
	//查找n区间内的素数
	for (size_t i = 2; i <= n; ++i)
	{
		if (isprime(i))
		{

			//查找n区间内的该素数的次幂数
			int Pow = i;
			for (int j = 2; j <= n; ++j)
			{
				Pow = pow(i, j);
				if (j == 2 && Pow>n)
				{
					ret = 2 * ret%mod;
					break;
				}
				if (Pow>n)
				{
					ret = ret*(j) % mod;
					break;
				}

			}
		}
	}
	return (int)ret;
}
int main(){
	int n=16;
	//while (cin >> n)
	{
		int ret = Fun(n);
		cout << ret << endl;
	}

	return 0;
}
#endif