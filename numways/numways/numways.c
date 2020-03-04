#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//青蛙跳问题
int numWays(int n){
	if (n < 0)
		return 0;
	if (n == 1 || n == 0)
	{
		return 1;
	}
	if (n == 2)
	{
		return 2;
	}
	int n1 = 1;
	int n2 = 2;
	int sum = 0;
	for (int i = 3; i <= n; ++i)
	{
		sum = (n1 + n2) % 1000000007;
		n1 = n2;
		n2 = sum;
	}
	return sum;
}
int fib(int n){
	if (n == 0 || n < 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	int n1 = 0;
	int n2 = 1;
	int sum = 0;
	for (int i = 2; i <= n; ++i)
	{
		sum = (n1 + n2) % 1000000007;
		n1 = n2;
		n2 = sum;
	}
	return sum;
}

int  main()
{
	int n = 100;
	printf("斐波那契第[%d]个数为%d\n", n,fib(n));
	printf("青蛙跳%d阶台阶有%d中跳法\n", n,numWays(n));
}
