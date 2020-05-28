#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<stack>
using namespace std;

void MOVE(int n, string& src, string& dest)
{
	cout << "Move" << " " << n << " from " << src << " to " << dest << endl;
}
//为了保证最优化解，两种相反的操作不能相邻：上次操作为左到中，这次不能中到左；至于是中到右，还是右到中看是否符合小盘在上，大盘在下的原则。
//               当前的操作        不允许的上次操作   上次操作
void stackStoD(int curAction, int prevNoAction, int& prevAction, stack<int>& srcs, stack<int>& dests,
	string& src, string& dest, int& count)
{        //不允许与上次进行相反的操作，
	if (prevNoAction != prevAction)
	{          //符合小盘在上大盘在下的原则。
		if ((!srcs.empty() && !dests.empty() && srcs.top()<dests.top()) || (!srcs.empty() && dests.empty()))
		{
			//将盘子从当前位置移动到目标位置
			int val = srcs.top();
			srcs.pop();
			dests.push(val);
			MOVE(val, src, dest);
			count++;
			prevAction = curAction;
		}
	}

}
void HanNuo(int n, string left, string mid, string right, int& count)
{
	stack<int> lefts;
	stack<int> mids;
	stack<int> rights;
	for (int i = n; i>0; --i)
	{
		lefts.push(i);
	}
	int prevAction = 0;
	int LM = 1;
	int RM = 2;
	int ML = 3;
	int MR = 4;
	while (rights.size() != n)
	{
		stackStoD(LM, ML, prevAction, lefts, mids, left, mid, count);
		stackStoD(ML, LM, prevAction, mids, lefts, mid, left, count);
		stackStoD(MR, RM, prevAction, mids, rights, mid, right, count);
		stackStoD(RM, MR, prevAction, rights, mids, right, mid, count);
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