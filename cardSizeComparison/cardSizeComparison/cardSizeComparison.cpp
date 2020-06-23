#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


int main()
{
	string str;
	while (getline(cin, str))
	{
		//如果有大小王的话，最大直接输出大小王
		if (str.find("joker JOKER") != string::npos)
		{
			cout << "joker JOKER" << endl;
			continue;
		}
		else
		{
			int Index = str.find('-');
			string str1 = str.substr(0, Index);
			string str2 = str.substr(Index + 1);
			int CountBrand1 = count(str1.begin(), str1.end(), ' ') + 1;
			int CountBrand2 = count(str2.begin(), str2.end(), ' ') + 1;
			//如果双方牌数相同的话，不管是顺子还是单和对子，都是可以比较的
			string Compared = "3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER";
			if (CountBrand1 == CountBrand2)
			{
				//谁的第一张牌大，谁最后一定赢
				//if(str1[0]>str2[0])
				//{
				//   cout<<str1<<endl;
				//}
				if (Compared.find(str1.substr(0, str1.find(' ')))>Compared.find(str2.substr(0, str2.find(' '))))
					cout << str1 << endl;
				else
					cout << str2 << endl;
			}
			else
			{
				//即使双方牌数不等，一放为4张牌即炸弹，一定赢
				if (CountBrand1 == 4)
					cout << str1 << endl;
				else if (CountBrand2 == 4)
					cout << str2 << endl;
				else
					cout << "ERROR" << endl;
			}
		}

	}
	return 0;
}