#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#define INT_MAX   8388607
#define INT_MIN  -8388608
int myAtoi(char * str){
	long ret = 0;
	int  flag = 1;
	int change = 0;
	while (*str == ' ')
	{
		str++;
	}
	while (*str == '-' || *str == '+')
	{
		if (change)
			return 0;
		if (*str == '-')
		{
			flag = -1;

		}
		str++;
		change = 1;
	}
	if (*str && (*str <= '0'&&*str >= '9'))
	{
		return 0;
	}

	while (*str && (*str >= '0'&&*str <= '9'))
	{
		ret = (*str - '0') + ret * 10;
		str++;
		if (flag == 1 && ret>INT_MAX)
		{
			return INT_MAX;
		}
		if (flag == -1 && ret>INT_MAX)
		{
			return  INT_MIN;
		}
	}


	return (int)(ret*flag);

}


int main()
{
	char* str = "999";
	printf("%d\n", myAtoi(str));
	return 0;
}