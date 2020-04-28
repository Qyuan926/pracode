#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

/*输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。*/


string reverseWords(string s) {
	if (s.empty())
	{
		return s;
	}
	int wordlen = 0;
	string ret = "";
	for (int i = s.size() - 1; i >= 0; --i)
	{
		//截取一个单词
		if (s[i] == ' '&&wordlen != 0)
		{
			ret += s.substr(i + 1, wordlen);
			ret += ' ';
			wordlen = 0;
		}
		//计算一个单词的长度
		if (s[i] != ' ')
		{
			wordlen++;
		}
	}
	//单词前面没有空格的情况
	if (wordlen>0)
	{
		ret += s.substr(0, wordlen);
		return ret;
	}
	//单词前有空格的情况
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