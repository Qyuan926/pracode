#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> ret;
	//������Ԫ���ź���
	sort(nums.begin(), nums.end());
	//������ת��Ϊ����������������֮��Ϊtargetֵ������
	size_t cur = 0;
	while (cur<nums.size())
	{
		//���curλ�õ���ֵ����0���򲻿�����������������֮��Ϊ�㣻ֱ��break��
		if (nums[cur]>0)
		{
			break;
		}
		
		
			//����˫��ָ����Ҹ��Ӷ�n^2
			size_t begin = cur + 1;
			size_t end = nums.size() - 1;
			while (begin<end)
			{
				if (nums[begin] + nums[end]<-nums[cur])
				{
					++begin;
				}
				else if (nums[begin] + nums[end] == -nums[cur])
				{    //ȥ���ظ�������
					//ȥ��cur�ظ�������[-1,0,1,2,-1,-4]
					if (cur == 0 || (cur>0 && nums[cur] != nums[cur - 1]))
					{
						if (begin == cur + 1)
						{
							vector<int > arr;
							arr.push_back(nums[cur]);
							arr.push_back(nums[begin]);
							arr.push_back(nums[end]);
							ret.push_back(arr);
							arr.clear();

						}
						//ȥ��cur���䣬��������Ԫ���ظ�������[-2,0,0,2,2]
						else if (nums[begin] != nums[begin - 1])
						{
							vector<int > arr;
							arr.push_back(nums[cur]);
							arr.push_back(nums[begin]);
							arr.push_back(nums[end]);
							ret.push_back(arr);
							arr.clear();
						}
					}
					++begin;
					--end;

				}
				else
				{
					--end;
				}
			
		}
		++cur;
	}
	return ret;

}


int main()
{
	vector<int> arr = { -1, 0, 1, 2, -1, -4 };
	threeSum(arr);
}