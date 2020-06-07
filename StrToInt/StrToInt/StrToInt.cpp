#define _CRT_SECURE_NO_WARNINGS 1
#include<string>
#include<iostream>
using namespace std;


int StrToInt(string str) {
	if (str.empty())
		return 0;
	int ret = INT_MIN;
	int flag = 1;
	for (size_t i = 0; i<str.size(); ++i)
	{
		if (i == 0 && str[i] == '+')
			continue;
		else if (i == 0 && str[i] == '-')
			flag = -1;
		else if (str[i] >= '0'&&str[i] <= '9')
		{
			//主体处理函数
			if (ret == INT_MIN)
			{
				ret = str[i] - '0' + 0;
			}
			else
			{
				ret = ret * 10 + str[i] - '0' + 0;
			}
		}
		else
		{
			return 0;
		}
	}
	return flag*ret;
}


int main()
{
	string str = "-1234";
	cout << StrToInt( str) << endl;
		
	return 0;
}