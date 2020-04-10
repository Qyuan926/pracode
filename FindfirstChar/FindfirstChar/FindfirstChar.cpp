#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;



#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		size_t i = 0;
		int CountArr[256] = { 0 };
		for (i = 0; i<s.size(); ++i)
		{
			CountArr[s[i]] += 1;
		}
		for (i = 0; i<s.size(); ++i)
		{
			if (CountArr[s[i]] == 1)
			{
				cout << s[i] << endl;
				break;
			}
		}
		if (i == s.size())
			cout << -1 << endl;

	}

	return 0;
}