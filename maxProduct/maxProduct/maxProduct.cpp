#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//����Ԫ��һ�����,�˻�Ϊmul
	//���ڵ����
	//mul>0, ��һ��Ԫ�ش���0��� �����˻����ܸı䣬     ������������˻�����
	//mul<0 ,��һ��Ԫ��С�ڵ���0��ˣ����˻����ܸı䣬   ����0�����˻�����
	//mul==0,һ�θ���Ԫ�� 
	//������������
	//    -3   4   -5  
	//���˻����ܸı�����    max*nums[i]   min*nums[i]   nums[i]
	int maxProduct(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int maxmul = nums[0];
		int minmul = nums[0];
		int ret = nums[0];
		for (int i = 1; i<nums.size(); ++i)
		{
			int ma = maxmul;
			int mi = minmul;
			maxmul = max(max(ma*nums[i], mi*nums[i]), nums[i]);
			minmul = min(min(ma*nums[i], mi*nums[i]), nums[i]);
			ret = max(maxmul, ret);
		}
		return ret;
	}
};



int main()
{
	vector<int> arr = { -4, -3, -2};
	Solution s;
	cout<<s.maxProduct(arr) << endl;
	return 0;

}