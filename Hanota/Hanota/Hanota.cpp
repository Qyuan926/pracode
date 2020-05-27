#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;
void MOVE(int n, string& src, string& dest)
{
	cout << "Move" << " " << n << " from " << src << " to " << dest << endl;
}

void HanNuo(int n, string src, string mid, string dest, int& count)
{
	count++;
	//Ų�����������ӣ�
	if (n == 1)
	{   //�����С����ҵ��С����е��󡢴��е��ҡ�ֱ��Ų������
		if (src == "mid" || dest == "mid")
		{
			MOVE(n, src, dest);
		}
		else
		{//�����ҡ����ҵ��󣻶���ҪŲ����������ΪҪ�����м�ڵ�
			count++;
			MOVE(n, src, mid);
			MOVE(n, mid, dest);
		}
		return;
	}

	//Ų����������ʣ������ӣ�������ƶ��м䣬���м��Ƶ���ߣ������Ƶ��ң������Ƶ���
	if (src == "mid" || dest == "mid")
	{
		HanNuo(n - 1, src, dest, mid, count);
		MOVE(n, src, dest);
		HanNuo(n - 1, mid, src, dest, count);
	}
	else
	{
		//��n-1�����Ӵӵ�ǰ�ƶ���Ŀ�Ķˣ����ҡ������м䣬��Ϊ����
		count++;		
		HanNuo(n - 1, src, mid, dest, count);
		//����n�����Ӵ�����
		MOVE(n, src, mid);
		//��n-1�����Ӵ����ƶ������
		HanNuo(n - 1, dest, mid, src, count);
		//����n�����Ӵ��е���
		MOVE(n, mid, dest);
		//��n-1�����Ӵ����ƶ�����
		HanNuo(n - 1, src, mid, dest, count);
	}
}

int main()
{
	//Բ�̵���Ŀ
	int n;
	cin >> n;
	//�� �� ������֧��
	string left = "left";
	string mid = "mid";
	string right = "right";
	//��¼�߹��Ĳ���
	int count = 0;
	HanNuo(n, left, mid, right, count);
	cout << "It will move " << count << " steps.";
	return 0;
}