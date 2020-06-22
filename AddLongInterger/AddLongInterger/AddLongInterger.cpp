#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
using namespace std;
string AddLongInterger(string add, string aug)
{
	if (add == "")
		return aug;
	if (aug == "")
		return add;

	int len1 = add.size();
	int len2 = aug.size();
	int len = len1;
	if (len2>len)
		len = len2;
	vector<char> arr(len + 1, '0');
	
	int Index1 = len1 - 1;
	int Index2 = len2 - 1;

	while (Index1 >= 0 || Index2>= 0)
	{
		int sum = 0;
		char addc = Index1>= 0 ? add[Index1] : '0';
		char augc = Index2 >= 0 ? aug[Index2] : '0';
		Index1--;
		Index2--;
		sum = addc - '0' + augc - '0' + 0 + arr[len] - '0';
		arr[len] = sum % 10+'0';
		if (sum / 10)
			arr[len - 1] = sum / 10+'0';
		len--;
	}

	string ret;
	for (int i = 0; i<arr.size(); ++i)
	{
		if (i == 0 && arr[i] == '0')
			continue;
		ret += arr[i];
	}

	return ret;
}



int main()
{
	string addend, augend;
	while (cin >> addend >> augend)
	{
		cout << AddLongInterger(addend, augend) << endl;
	}
	return 0;
}