#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
    TreeNode *right;
	
	
};
//ǰ�������˼��
TreeNode*  _sortedArrayToBST(vector<int>& nums, int begin, int end)
{
	if (begin>end)
	{
		return nullptr;
	}
	//�ҳ������м��λ��,Ϊ���ĸ�
	int mid = (begin + end) / 2;
	TreeNode* root = new TreeNode;
	root->val = nums[mid];
	//������ߵļ�Ϊ������
	root->left = _sortedArrayToBST(nums, begin, mid - 1);
	//�����ұߵļ�Ϊ������
	root->right = _sortedArrayToBST(nums, mid + 1, end);
	return root;
}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.empty())
		{
			return NULL;
		}
		return _sortedArrayToBST(nums, 0, ((int)nums.size()) - 1);

	}


