#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


/*

ţţ��������������Ϊһ��������һ��������������,��������������Ƿǵ������߷ǵݼ�����ġ�ţţ��һ������Ϊn����������A,��������һ�������ǰ�����A��Ϊ���ɶ�����������,ţţ��֪�������ٿ��԰���������Ϊ��������������.
��������ʾ,ţţ���԰�����A����Ϊ[1,2,3]��[2,2,1]��������������,������Ҫ����Ϊ2������������,�������2*/


int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (size_t i = 0; i<n; ++i)
	{
		cin >> arr[i];
	}
	//�������

	//������������
	size_t Index = 1;
	bool minflags = false;
	bool greaterflags = false;
	bool equal = false;
	int count = 0;
	while (Index<n)
	{
		minflags = false;
		greaterflags = false;
		while (Index<n&&arr[Index - 1]<arr[Index])
		{
			++Index;
			minflags = true;
		}
		if (minflags)
		{
			count++;
			++Index;

		}
		while (Index<n&&arr[Index - 1] == arr[Index])
		{
			++Index;
			equal = true;
		}

		while (Index<n&&arr[Index - 1]>arr[Index])
		{
			++Index;
			greaterflags = true;
		}
		if (greaterflags)
		{
			count++;

			++Index;
		}
		if ((Index == n) && (equal || greaterflags || minflags))
			count++;


	}
	cout << count << endl;
	return 0;
}