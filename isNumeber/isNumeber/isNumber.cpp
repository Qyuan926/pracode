#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

bool isNumber(string s) {
	int begin = s.find_first_not_of(' ');
	if (begin == string::npos)
		return false;
	int end = s.find_last_not_of(' ');
	s = s.substr(begin, end - begin + 1);
	if (s.empty())
	{
		return false;
	}
	int pos_e = s.find('e');
	if (pos_e == string::npos)
		return isBase(s.substr(0, pos_e));
	else
	{
		return isBase(s.substr(0, pos_e)) && isIndex(s.substr(pos_e + 1));
	}

}
bool  isBase(string s)
{
	bool result = false;
	string::iterator  begin = s.begin();
	string::iterator  end = s.end();
	string::iterator start = begin;
	int pointnum = 0;
	while (start<end)
	{
		if (*start == '+' || *start == '-')
		{
			if (start != begin)
				return false;
			++start;
		}
		else if (*start == '.')
		{
			++pointnum;
			if (pointnum>1)
				return false;
			++start;
		}
		else if (*start<'0' || *start>'9')
		{
			return false;
			++start;
		}
		else
		{
			result = true;
			++start;
		}

	}
	return result;
}
bool isIndex(string s)
{
	string::iterator  begin = s.begin();
	string::iterator  end = s.end();
	string::iterator start = begin;
	bool result = false;
	while (start<end)
	{
		if (*start == '+' || *start == '-')
		{
			if (start != begin)
				return false;
			++start;
		}
		else if (*start == '.')
		{
			return false;
			++start;
		}
		else if (*start<'0' || *start>'9')
		{
			return false;
			++start;
		}

		else
		{
			result = true;
			++start;
		}

	}
	return result;

}
	



int main()
{
	string s = ".1";
	isNumber(s);

 	return 0;
}