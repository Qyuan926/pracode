#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
/*第N个数字
在无限的整数序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...中找到第 n 个数字。

注意:
n 是正数且在32位整数范围内 ( n < 231)。

输入:
11

输出:
0

说明:
第11个数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是0，它是10的一部分。

*/
int findNthDigit(int n){
	//如果n《10，直接返回
	if (n<10)
		return n;
	int bit = 1;
	for (long long i = 9; n>bit*i;)
	{
		if (n>bit*i)
		{
			n -= (i*bit);
			++bit;
			i = i * 10;

		}

	}
	//即要找的是一个bit位数字的第n个位置的数字

	//先构造一个最小的bit位数字
	int num = 1;
	int j = bit - 1;
	while (j--)
		num *= 10;

	num += n / bit;//构造要找的数字
	int index = n%bit;

	if (index == 0)//即num的前一个数字的最后一位  
	{
		return (num - 1) % 10;
	}
	//num的第index位
	int ret = 0;
	for (int i = bit;; --i)
	{
		ret = num % 10;
		num /= 10;
		if (index == i)
			break;
	}

	return ret;
}

int main()
{
	cout <<  findNthDigit(12) << endl;

	return 0;
}
