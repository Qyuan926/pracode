#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
using namespace std;
void Joseph_Ring(list<int>& head, int& m)
{
	//����һ���˵�ʱ��
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
	// n ��ʾ��������ĳ��ȣ� m ��ʾÿ�α����� m ����ɱ��
	int n, m;
	cin >> n >> m;
	//���컷������
	list<int> head;
	for (int i = 0; i<n; ++i)
	{
		head.push_back(i);
	}
	Joseph_Ring(head, m);
	return 0;
}