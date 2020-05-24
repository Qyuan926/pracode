#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


class Solution{
public:
	//���������������Ϊret
	//dividend-divisor��ret�Ľ��һ��С��divisor
	/* int ret=0;
      while(a>=b)
      {
          a=a-b;
          ret++;
      }
        return ret*sign;
		ʱ�临�Ӷȹ��ߣ�������b��С��ʱ��
		ÿ�ν��з���������������*/
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
		//�������ͱ�����ȫ��ת��Ϊ���������жϽ��Ϊ�����Ǹ�
		//���ж��ֲ���
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