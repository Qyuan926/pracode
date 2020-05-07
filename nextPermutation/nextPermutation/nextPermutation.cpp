#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*�ҳ����������������������У��պñȵ�ǰ������Ǹ���

���統ǰ nums = [1,2,3]���������123���ҳ�1��2��3��3������������ܵ�������������󣬱�123����Ǹ��� Ҳ����132

�����ǰ nums = [3,2,1]�������1��2��3���������������Ǹ�������ô�ͷ���1��2��3���������������С���Ǹ���Ҳ����1��2��3 -> [1,2,3]
*/
void nextPermutation(vector<int>& nums) {
	if (nums.empty())
	{
		return;
	}
	//�ҵ���ǰλ�õ���ֵ����ǰһ��λ�ô�����
	int i = nums.size() - 1;
	for (; i >= 1; --i)
	{
		if (nums[i]>nums[i - 1])
			break;
	}
	//û��ͨ��break�˳�������ǰ������������������������������Ϊ�ܴ������С������
	if (i == 0)
	{
		sort(nums.begin(), nums.end());
	}
	else
	{
		//cur=i;��curλ�ÿ�ʼ,�ҵ�����cur-1λ�õ�ֵ����Сֵ��λ��
		int prev = i - 1;
		int min = i;
		for (; i<nums.size(); ++i)
		{
			if (nums[i]>nums[prev] && nums[min]>nums[i])
				min = i;
		}
		//����prevλ�ú�minλ�ã���curλ������λ���Ժ����prevλ��ֵ����С��һ������ֵ
		swap(nums[prev], nums[min]);
		//��prevλ��֮����������гɴ���������С�����
		sort(nums.begin() + prev + 1, nums.end());
	}
}

int main()
{
	vector<int> arr = { 2,3,1 };
	nextPermutation(arr);
	return 0;
}