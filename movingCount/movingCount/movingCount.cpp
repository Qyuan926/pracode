#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//������һ��m��n�еķ��񣬴�����[0, 0] ������[m - 1, n - 1] ��һ�������˴�����[0, 0] �ĸ��ӿ�ʼ�ƶ�����ÿ�ο��������ҡ��ϡ����ƶ�һ�񣨲����ƶ��������⣩��Ҳ���ܽ�������������������λ֮�ʹ���k�ĸ��ӡ����磬��kΪ18ʱ���������ܹ����뷽��[35, 37] ����Ϊ3 + 5 + 3 + 7 = 18���������ܽ��뷽��[35, 38]����Ϊ3 + 5 + 3 + 8 = 19�����ʸû������ܹ�������ٸ����ӣ�

void move(vector<vector<int>>& rountine, int* ret, int row, int col, int m, int n, int k)
{
	//�����Ƿ��ڷ������棬���ڷ��أ��ڼ���ִ��
	if (!((row >= 0 && row<m) && (col >= 0 && col<n)))
	{
		return;
	}
	if ((row % 10 + row / 10 + col % 10 + col / 10)>k)
	{
		return;
	}

	if (rountine[row][col] == 1)
		return;

	rountine[row][col] = 1;
	(*ret)++;


	move(rountine, ret, row - 1, col, m, n, k);//��
	move(rountine, ret, row + 1, col, m, n, k);//��
	move(rountine, ret, row, col - 1, m, n, k);//��
	move(rountine, ret, row, col + 1, m, n, k);//��
}
int movingCount(int m, int n, int k) {
	//��������ͼ��m*n����¼����
	vector<vector<int>>rountine(m, vector<int>(n, 0));

	int ret = 0;
	move(rountine, &ret, 0, 0, m, n, k);
	return ret;
}


int main()
{
	cout<<movingCount(2, 3, 1)<<endl;
	return 0;
}