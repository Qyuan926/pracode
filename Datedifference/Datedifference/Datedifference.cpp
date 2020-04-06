#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int yearday(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return 366;
	}
	return 365;
}
int yearStartday(int year, int month, int day)
{
	int monthday[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		monthday[2] = 29;
	}
	int retday = 0;
	for (int i = 1; i<month; ++i)
	{
		retday += monthday[i];
	}
	retday += day;
	return retday;
}

char a[9], b[9];
int main()
{
	int gapday = 1;
	int year1, month1, day1, year2, month2, day2;


	while (cin >> a >> b){

		sscanf(a, "%4d%2d%2d", &year1, &month1, &day1);//格式化读入
		sscanf(b, "%4d%2d%2d", &year2, &month2, &day2);

		int min = year1;
		int max = year2;
		int minday = yearStartday(year1, month1, day1);
		int maxday = yearStartday(year2, month2, day2);
		if (min>max)
		{
			int tmp = min;
			min = max;
			max = tmp;
			tmp = minday;
			minday = maxday;
			maxday = tmp;
		}
		for (int i = min; i<max; ++i)
		{
			gapday += yearday(i);
		}
		cout << gapday + maxday - minday << endl;

	}



	return 0;
}