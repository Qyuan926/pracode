#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
/*输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。

例如，输入12，
1～12这些整数中包含1 的数字有1、10、11和12，
1一共出现了5次。

*/

/*
针对题目中数字最大为2^31次方，最多只有10位数。所以综上所述我们可以列出f(n)
f(1) = 1;
f(2) = 20;
f(3) = 300;
f(4) = 4000;
f(5) = 50000;
f(6) = 600000;
f(7) = 7000000;
f(8) = 80000000;
f(9) = 900000000;
f(10) = ‭10,000,000,000‬;

f(n)= （  f(n-1)/位制+1 ）*位制*10    位制是指f(n-1)的位制

1234
对于4，因为是个位数 所以只与是否大于1有关系  大于等于1就是1 否则为0   所以结果为1
对于34，因为3大于1  所以第一位为1  共10种情况，  再加上第一位取任意非零，剩下的为上一层的结果  得到 3 * 1  结果为10 + 3 = 13
对于234 因为2大于1  所以第一位为1  共100种情况， 再加上第一位取任意非零，剩下的为上一层的结果  得到 2 * 20  结果为 40 + 100 = 140
对于1234  因为1等于1 ，所以第一位为1的情况由余数234决定  0 - 234 共235个，再加上第一位取任意非零，剩下的为上一层的结果  得到 1 * 300 结果为 300 + 235 = 535
所以最终答案为 1 + 13 + 140 + 535 = 689

*/
int countDigitOne1(int n) {
	int ret = 0;
	long digit = 1;
	long cur_countDigitone = 1;
	long pre_countDigitone = 0;
	while (digit <= n)
	{
		//求取当前位上的数值
		int num = n % (digit * 10);
		//
		int reminder = num%digit;
		int quo = num / digit;

		//如果判断的是个位的情况：商quo大于等于1则有1个，否则0个
		if (digit == 1)
			ret += quo >= 1 ? 1 : 0;
		else
		{
			//判断最高位的情况
			//最高位为1，出现1个次数就由余数reminder决定
			if (quo == 1)
			{
				ret += reminder + 1;
			}
			//最高位不等于1,0;则最高位出现1的情况全部包含
			if (quo != 1 && quo != 0)
			{
				ret += digit;
			}
			ret += quo*pre_countDigitone;
		}
		pre_countDigitone = cur_countDigitone;
		cur_countDigitone = ((cur_countDigitone / digit) + 1)*digit * 10;
		digit *= 10;
	}
	return ret;

}
//按照位制依次进行计算
/*
*/
    int countDigitOne(int n) {
	int ret = 0;
	long long cur = n % 10;
	long long high = n / 10;
	long long low = 0;
	long long digit = 1;
	while (high != 0 || cur != 0)
	{
		if (cur == 0)
		{
			ret += high*digit;
		}
		else if (cur == 1)
		{
			ret += (high*digit + low + 1);
		}
		else
		{
			ret += (high + 1)*digit;
		}
		digit *= 10;
		low = n % (digit);
		cur = (n % (digit * 10) - low) / (digit);
		high = n / (digit * 10);


	}
	return ret;
}

int main()
{
	int x = 12;
	cout<<countDigitOne(x) << endl;
	return 0;
}