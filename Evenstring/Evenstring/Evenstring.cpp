#define _CRT_SECURE_NO_WARNINGS 1
/*
���һ���ַ�����������ͬ�ַ������Ӷ���,�ͳ�����ַ�����ż��������"xyzxyz"��"aaaaaa"��ż��,����"ababab"��"xyzxy"ȴ���ǡ�
ţţ���ڸ���һ��ֻ����Сд��ĸ��ż��s,����Դ��ַ���s��ĩβɾ��1�ͻ��߶���ַ�,��֤ɾ��֮����ַ�������һ��ż��,ţţ��֪��ɾ��֮��õ��ż�������Ƕ��١�*/


#include<iostream>
#include<string>
using namespace std;

class Solution{
	bool Islaw()
	{
		if (_str.size() % 2 != 0)
			return false;
		int mid = _str.size() / 2;
		string str1 = _str.substr(0, mid);
		string str2 = _str.substr(mid);
		return str1 == str2;
	}

public:
	int Fun(string str)
	{
		int size = str.size();
		if (size <= 1)
			return 0;
		_str = str;
		while (size>0)
		{

			_str.pop_back();
			--size;
			if (Islaw())
			{
				return _str.size();
			}
		}
		return 0;
	}
private:
	string _str;
};

int main()
{
	string str;
	while (cin >> str)
	{
		Solution s;
		int ret = s.Fun(str);
		cout << ret << endl;
	}
	return 0;
}