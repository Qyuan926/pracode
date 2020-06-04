#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*��һ����������arr��һ����СΪw�Ĵ��ڴ����������߻������ұߣ�
����ÿ�����ұ߻�һ��λ�ã���ÿһ�ִ���״̬�µ����ֵ����������鳤��Ϊn�����ڴ�СΪw����һ������n-w+1�����ڵ����ֵ��
8 3
4 3 5 4 3 3 6 7*/


int main()
{
	int n;
	int windowsize;
	cin >> n >> windowsize;

	vector<int> arr(n);
	vector<int> ret;
	deque<int>  que;
	for (int i = 0; i<n; ++i)
	{
		cin >> arr[i];
	}
	//����������������
	//���˫�˶����ǿյ�ֱ�ӷ���
	//���˫�˶��в��ǿյ� ���бȽ�
	//�����С��˫�˶���β����ֱ�ӷ��룬
	//����˫�˶���β������Ԫ�أ��ظ���������
	for (int j = 0; j<n; ++j)
	{
		
		while (!que.empty() && arr[que.back()] <= arr[j])
		{
			que.pop_back();
		}
		que.push_back(j);

		if (que.front() == j - windowsize)
			que.pop_front();

		if (j >= windowsize - 1)
		{
			ret.push_back(arr[que.front()]);
		}

	}
	for (size_t k = 0; k<ret.size(); ++k)
	{
		cout << ret[k] << " ";
	}
	cout << endl;


	return 0;
}