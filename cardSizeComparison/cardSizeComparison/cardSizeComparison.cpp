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
		//����д�С���Ļ������ֱ�������С��
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
			//���˫��������ͬ�Ļ���������˳�ӻ��ǵ��Ͷ��ӣ����ǿ��ԱȽϵ�
			string Compared = "3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER";
			if (CountBrand1 == CountBrand2)
			{
				//˭�ĵ�һ���ƴ�˭���һ��Ӯ
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
				//��ʹ˫���������ȣ�һ��Ϊ4���Ƽ�ը����һ��Ӯ
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