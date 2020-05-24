#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*

ţţ����������һ����Ȥ�Ĳ�����Ϸ���������Ϸ��,ţţ���ѡ��һ��������,��������Ѹ�����ʾ��������֡���i����ʾ��"Y"����"N",��ʾţţѡ������Ƿ���i�ı�����
����,�����ʾ��"YYNYY",����ʾ�����ʹ1,2,4,5�ı���,������3�ı�����
ע�⵽һЩ��ʾ����ִ�������: ��ʾ"NYYY"�Ǵ����,��Ϊ���е���������1�ı���,������ʼԪ�ؿ϶�������"N"������,����"YNNY"����ʾҲ�Ǵ����,��Ϊ�����������4�ı���������2�ı�����
���ڸ���һ������n,��ʾ�Ѹ�����ʾ�ĳ��ȡ�����������Ϊn�ĺϷ�����ʾ�ĸ�����
���� n = 5:
�Ϸ�����ʾ��:
YNNNN YNNNY YNYNN YNYNY YYNNN YYNNY
YYNYN YYNYY YYYNN YYYNY YYYYN YYYYY
�������12

��������:
�������һ������n(1 �� n �� 10^6),��ʾ�Ѹ���ʾ�ĳ��ȡ�


�������:
���һ������,��ʾ�Ϸ�����ʾ��������Ϊ�𰸿��ܻ�ܴ�,�����������1000000007��ģ
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
	//����n�����ڵ�����
	for (size_t i = 2; i <= n; ++i)
	{
		if (arr[i])//����������
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
	//����n�����ڵ�����
	for (size_t i = 2; i <= n; ++i)
	{
		if (isprime(i))
		{

			//����n�����ڵĸ������Ĵ�����
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