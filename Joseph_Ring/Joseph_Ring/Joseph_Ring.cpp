#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
using namespace std;
void Joseph_Ring(list<int>& head, int& m)
{
	//仅有一个人的时候
	if (head.size() <= 1)
	{
		cout << 0 << endl;
		return;
	}
	list<int>::iterator  it = head.begin();
	int countnum = 1;
	while (head.size() != 1)
	{

		if (countnum == m)
		{
			head.erase(it);
			countnum = 1;
			++it;
		}
		else
		{
			++it;
			countnum++;
		}
		if (it == head.end())
		 it = head.begin();
	}
	it = head.begin();
	cout << *it << endl;


}


int main()
{
	// n 表示环形链表的长度， m 表示每次报数到 m 就自杀。
	int n, m;
	cin >> n >> m;
	//构造环形链表
	list<int> head;
	for (int i = 0; i<n; ++i)
	{
		head.push_back(i);
	}
	Joseph_Ring(head, m);
	return 0;
}