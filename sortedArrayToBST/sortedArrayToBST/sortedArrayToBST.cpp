#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
    TreeNode *right;
	
	
};
//前序遍历的思想
TreeNode*  _sortedArrayToBST(vector<int>& nums, int begin, int end)
{
	if (begin>end)
	{
		return nullptr;
	}
	//找出数组中间的位置,为树的根
	int mid = (begin + end) / 2;
	TreeNode* root = new TreeNode;
	root->val = nums[mid];
	//数组左边的即为左子树
	root->left = _sortedArrayToBST(nums, begin, mid - 1);
	//数组右边的即为右子树
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


