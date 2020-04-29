#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//����һ�����֣����ǰ������¹����������Ϊ�ַ�����0 ����� ��a�� ��
//1 ����� ��b����������11 ����� ��l����������25 ����� ��z����
//һ�����ֿ����ж�����롣����ʵ��һ����������������һ�������ж����ֲ�ͬ�ķ��뷽����

//1068385902
// 1 0 6 8 3 8 8 5 9 0 2
// 10 6 8 3 8 8 5 9 0 2
//�����ַ����ĵ�һλ����ķ���ֻ����һ����ĸ
//�����ַ����ӵڶ�λ��ʼ��ǰһλ��ϣ���ΧΪ"10"------"25",�������������ַ�
int translateNum(int num) {
	if (num<0)
	{
		num = -num;
	}
	//������ת��Ϊ�ַ���
	string str = to_string(num);
	vector<int> dp(str.size() + 1, 1);
	for (size_t i = 1; i<str.size(); ++i)
	{
		if (str.substr(i - 1, 2) >= "10"&&str.substr(i - 1, 2) <= "25")
		{
			dp[i + 1] = dp[i - 1] + dp[i];
		}
		else
		{
			dp[i + 1] = dp[i];
		}

	}
	return dp[str.size()];
}

int main()
{
	cout << translateNum(1068385902) << endl;
	return 0;
}