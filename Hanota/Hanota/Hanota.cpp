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
	//挪动顶部的盘子，
	if (n == 1)
	{   //从左到中、从右到中、从中到左、从中到右。直接挪动即可
		if (src == "mid" || dest == "mid")
		{
			MOVE(n, src, dest);
		}
		else
		{//从左到右、从右到左；都需要挪动两步、因为要借助中间节点
			count++;
			MOVE(n, src, mid);
			MOVE(n, mid, dest);
		}
		return;
	}

	//挪动除顶部外剩余的盘子，从左边移动中间，从中间移到左边，从中移到右，从右移到中
	if (src == "mid" || dest == "mid")
	{
		HanNuo(n - 1, src, dest, mid, count);
		MOVE(n, src, dest);
		HanNuo(n - 1, mid, src, dest, count);
	}
	else
	{
		//将n-1个盘子从当前移动到目的端，左到右。经过中间，故为两步
		count++;		
		HanNuo(n - 1, src, mid, dest, count);
		//将第n个盘子从左到中
		MOVE(n, src, mid);
		//将n-1个盘子从右移动到左边
		HanNuo(n - 1, dest, mid, src, count);
		//将第n个盘子从中到右
		MOVE(n, mid, dest);
		//将n-1个盘子从左移动到右
		HanNuo(n - 1, src, mid, dest, count);
	}
}

int main()
{
	//圆盘的数目
	int n;
	cin >> n;
	//左 中 右三个支柱
	string left = "left";
	string mid = "mid";
	string right = "right";
	//记录走过的步数
	int count = 0;
	HanNuo(n, left, mid, right, count);
	cout << "It will move " << count << " steps.";
	return 0;
}