#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int equal(double x, double y)
{
	if ((x - y>-0.000001) && (x - y<0.000001))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
double DoublePow(double x, unsigned long n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	double ret = DoublePow(x, n / 2);
	ret *= ret;
	if (n & 0x1 == 1)
		ret *= x;
	return ret;
}
double myPow(double x, int n){

	if (equal(x, 0.0) == 1 && n<0)
		return 0.0;
	unsigned long  abs_n = (unsigned long)n;
	if (n<0)
		abs_n = -abs_n;

	double ret = DoublePow(x, abs_n);
	if (n<0)
		ret = 1.0 / ret;
	return ret;
}
int main()
{
	double x = 0.123;
	int n = 7;
	int m = 0;
	int r = -7;
	printf("x的%d次方为%lf\n",n, myPow(x, n));
	printf("x的%d次方为%lf\n", m, myPow(x, m));
	printf("x的%d次方为%lf\n", r, myPow(x, r));
}