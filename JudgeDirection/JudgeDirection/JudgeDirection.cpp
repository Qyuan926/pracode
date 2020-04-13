#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int length = 0;
	string str;
	char arr[4][2] = { { 'S', 'N' }, { 'W', 'E' }, { 'N', 'S' }, { 'E', 'W' } };
	char dir = 'N';
	while (cin >> length >> str)
	{
		for (int i = 0; i<length; ++i)
		{
			if (dir == 'N')
			{
				if (str[i] == 'L')
					dir = arr[3][1];
				else
					dir = arr[3][0];
			}
			else if (dir == 'W')
			{
				if (str[i] == 'L')
					dir = arr[2][1];
				else
					dir = arr[2][0];

			}
			else if (dir == 'S')
			{
				if (str[i] == 'L')
					dir = arr[1][1];
				else
					dir = arr[1][0];
			}
			else
			{
				if (str[i] == 'L')
					dir = arr[0][1];
				else
					dir = arr[0][0];
			}

		}
		cout << dir << endl;

	}

	return 0;
}