#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

/*����һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣Ϊ������������ź���ͨ��ĸһ���������������ַ���"I am a student. "�������"student. a am I"��
�����ַ���������ǰ����ߺ����������Ŀո񣬵��Ƿ�ת����ַ����ܰ�����
����������ʼ��ж���Ŀո񣬽���ת�󵥴ʼ�Ŀո���ٵ�ֻ��һ����*/


string reverseWords(string s) {
	if (s.empty())
	{
		return s;
	}
	int wordlen = 0;
	string ret = "";
	for (int i = s.size() - 1; i >= 0; --i)
	{
		//��ȡһ������
		if (s[i] == ' '&&wordlen != 0)
		{
			ret += s.substr(i + 1, wordlen);
			ret += ' ';
			wordlen = 0;
		}
		//����һ�����ʵĳ���
		if (s[i] != ' ')
		{
			wordlen++;
		}
	}
	//����ǰ��û�пո�����
	if (wordlen>0)
	{
		ret += s.substr(0, wordlen);
		return ret;
	}
	//����ǰ�пո�����
	if (ret.size()>0)
	{
		ret.erase(ret.size() - 1, 1);
	}
	return ret;
}

int main()
{
	string str1 = " Hello World";
	cout << reverseWords(str1) << endl;
	string str2 = "  Hello      World   ";
	cout << reverseWords(str2) << endl;
	return 0;
}