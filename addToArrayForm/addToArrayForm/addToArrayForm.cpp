#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


vector<int> addToArrayForm(vector<int>& A, int K) {
	if (K == 0)
	{
		return A;
	}
	//��Kֵת��Ϊ������ʽ������
	vector<int> arrK;
	while (K>0)
	{
		arrK.push_back(K % 10);
		K /= 10;
	}
	//���AΪ�գ�ֻ��Ҫ����Kֵ��������ʽ������
	if (A.empty())
	{
		vector<int> ::iterator  begin = arrK.begin();
		vector<int> ::iterator  end = arrK.end();
		reverse(begin, end);
		return arrK;
	}
	//��A����
	vector<int> ::iterator  beginA = A.begin();
	vector<int> ::iterator  endA = A.end();
	reverse(beginA, endA);


	//����������������
	vector<int> ret;
	vector<int> ::iterator beginK = arrK.begin();

	int numK = 0;
	int numA = 0;
	int carry = 0;
	while (beginK != arrK.end() || beginA != A.end())
	{
		numA = beginA != A.end() ? *beginA : 0;
		numK = beginK != arrK.end() ? *beginK : 0;
		int num = numA + numK + carry;
		ret.push_back(num % 10);
		carry = num / 10;
		if (beginA != A.end())
		{
			++beginA;
		}
		if (beginK != arrK.end())
		{
			++beginK;
		}
	}
	if (carry != 0)
	{
		ret.push_back(carry);
	}
	vector<int> ::iterator  begin = ret.begin();
	vector<int> ::iterator  end = ret.end();
	reverse(begin, end);
	return ret;
}







