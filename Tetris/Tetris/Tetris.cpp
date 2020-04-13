#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#if 0
小易有一个古老的游戏机，上面有着经典的游戏俄罗斯方块。因为它比较古老，所以规则和一般的俄罗斯方块不同。
荧幕上一共有 n 列，每次都会有一个 1 x 1 的方块随机落下，在同一列中，后落下的方块会叠在先前的方块之上，当一整行方块都被占满时，这一行会被消去，并得到1分。
有一天，小易又开了一局游戏，当玩到第 m 个方块落下时他觉得太无聊就关掉了，小易希望你告诉他这局游戏他获得的分数。
#endif
int main()
{
	int n, m;
	int c;
	while (cin >> n >> m)
	{
		int score = 0;

		int* C = new int[n + 1];
		int i = 0;
		for (i = 0; i<n + 1; i++)
		{
			C[i] = 0;
		}
		for (i = 0; i<m; i++)
		{
			cin >> c;
			C[c] += 1;
		}
		int min = C[1];
		for (i = 2; i<n + 1; i++)
		{
			if (min>C[i])
			{
				min = C[i];
			}
		}
		score = min;
		cout << score << endl;
		delete[] C;
	}
	return 0;
}