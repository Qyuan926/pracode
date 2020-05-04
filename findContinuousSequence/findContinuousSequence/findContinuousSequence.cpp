#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
/*����һ�������� target ��������к�Ϊ target ���������������У����ٺ�������������

�����ڵ�������С�������У���ͬ���а����׸����ִ�С�������С�
���룺target = 15
�����[[1,2,3,4,5],[4,5,6],[7,8]]
*/


//�������ڵķ���
vector<vector<int>> findContinuousSequence(int target) {
	vector<vector<int>> ret;
	if (target <= 0)
	{
		return ret;
	}
	int left = 1;
	int right = 1;
	int sum = 0;
	while (left <= target / 2)
	{
		//���sum<target,�ұ߽����һ���������sum
		if (sum<target)
		{
			sum += right;
			right++;
		}
		//���sum>target,��߽����һ�������Сsum
		else if (sum>target)
		{
			sum -= left;
			left++;
		}
		else
		{
			//��������������������¼����������������һ�£��γ��µĴ���
			vector<int> arr;
			for (size_t i = left; i<right; ++i)
			{
				arr.push_back(i);
			}
			ret.push_back(arr);
			sum -= left;
			left++;
		}
		
	}
	return ret;
}



int main()
{

	vector<vector<int>> ret =findContinuousSequence(9);

	return 0;
}