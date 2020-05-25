#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;
/*����һ������Ϊ n �����ӣ�������Ӽ����������ȵ� m �Σ�m��n����������n>1����m>1����ÿ�����ӵĳ��ȼ�Ϊ k[0],k[1]...k[m] ��
���� k[0]*k[1]*...*k[m] ���ܵ����˻��Ƕ��٣����磬�����ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���ʱ�õ������˻���18

*/

//��̬�滮��������Ϊn��һ�ηֳ�len��n-len���ȣ������λ����Լ����֣��ҵ�����ֵ��
// dp[n]=max{dp[len]*dp[n-len],dp[n]};
// ������� cuttingRope��2��=1<2, ����������ܼ�����,Ҳ�����޷�ʹ������Ĺ�ʽ��������Ҫ�Դ˽��е���
int cuttingRope(int n) {
	vector<int> arr(n + 1, 0);
	arr[1] = 1;
	for (int len = 2; len <= n; ++len)
	{
		int i = 1;
		for (i = 1; i <= len / 2; ++i)
		{
			arr[len] = max(arr[len], arr[len - i] * arr[i]);
		}
		if (i != n)
			arr[len] = max(arr[len], len);
	}
	return arr[n];

}

int main()
{
	cuttingRope(10);
	return 0;
}