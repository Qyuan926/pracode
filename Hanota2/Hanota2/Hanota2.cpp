#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<stack>
using namespace std;

void MOVE(int n, string& src, string& dest)
{
	cout << "Move" << " " << n << " from " << src << " to " << dest << endl;
}
//Ϊ�˱�֤���Ż��⣬�����෴�Ĳ����������ڣ��ϴβ���Ϊ���У���β����е����������е��ң������ҵ��п��Ƿ����С�����ϣ��������µ�ԭ��
//               ��ǰ�Ĳ���        ��������ϴβ���   �ϴβ���
void stackStoD(int curAction, int prevNoAction, int& prevAction, stack<int>& srcs, stack<int>& dests,
	string& src, string& dest, int& count)
{        //���������ϴν����෴�Ĳ�����
	if (prevNoAction != prevAction)
	{          //����С�����ϴ������µ�ԭ��
		if ((!srcs.empty() && !dests.empty() && srcs.top()<dests.top()) || (!srcs.empty() && dests.empty()))
		{
			//�����Ӵӵ�ǰλ���ƶ���Ŀ��λ��
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