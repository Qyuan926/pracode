#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*����һ���ɰ����ظ����ֵ����У��������в��ظ���ȫ���С�

ʾ��:

����: [1,1,2]
���:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*/

class Solution {

public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		if (nums.empty())
			return _ret;
		sort(nums.begin(), nums.end());
		_nums = nums;
		vector<bool> flags(nums.size(), false);
		trackback(flags);
		return _ret;
	}
private:
	void trackback(vector<bool>& flags)
	{
		if (_arr.size() == _nums.size())
		{
			_ret.push_back(_arr);
			return;
		}
		for (size_t i = 0; i<_nums.size(); ++i)
		{
			if (flags[i] == true)
			{//�����ǰ����ֵ�Ѿ���ʹ���ˣ�ֱ����������ֹ�ظ�ʹ��
				continue;
			}
			if (i>0 && _nums[i - 1] == _nums[i] && flags[i - 1] == false) //��ǰ��ֵ��ǰһ����ֵ��ȡ����һ����꣬ǰһ��ֵû�б�ʹ�ã���ʱӦ��������������ظ��Ľ��
				continue;
			//��֦�����
			_arr.push_back(_nums[i]);
			flags[i] = true;
			trackback(flags);
			_arr.pop_back();
			flags[i] = false;
		}

	}
private:
	vector<vector<int>> _ret;
	vector<int> _nums;
	vector<int> _arr;
};