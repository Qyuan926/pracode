#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


class Solution{
public:
	//两个数相除如果结果为ret
	//dividend-divisor次ret的结果一定小于divisor
	/* int ret=0;
      while(a>=b)
      {
          a=a-b;
          ret++;
      }
        return ret*sign;
		时间复杂度过高，尤其是b很小的时候
		每次进行翻倍，会有所改善*/
	int divide(int dividend, int divisor) {
		if (divisor == 0 || dividend == 0)
			return  0;
		if (divisor == 1)
			return dividend;
		if (divisor == -1)
		{
			if (dividend == INT_MIN)
				return INT_MAX;
			else
				return -dividend;
		}
		int sign = 1;
		long a = dividend;
		long b = divisor;
		if ((a<0 && b>0) || (a>0 && b<0))
			sign = -1;

		a = a>0 ? a : -a;
		b = b>0 ? b : -b;
		//将除数和被除数全部转换为正数，并判断结果为正还是负
		//进行二分查找
		int ret = Binarysearch(a, b);
		return ret*sign;
	}
	int Binarysearch(long a, long b)
	{
		if (a<b)
			return 0;
		int count = 1;
		long B = b;
		while ((B + B) <= a)
		{
			count *= 2;
			B *= 2;
		}
		return count + Binarysearch(a - B, b);
	}
};




int main()
{
	Solution s;
	s.divide(7, 3);
	return 0;
}