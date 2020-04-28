#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	

};


namespace Solution{
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> ret;
		if (root == nullptr)
			return ret;
		vector<int> arr;
		_pathSum(root, sum, ret, arr, 0);
		return ret;
	}

	void _pathSum(TreeNode* root, int sum, vector<vector<int>>& ret, vector<int>& arr, int addarr)
	{

		arr.push_back(root->val);
		addarr += root->val;
		if (root->left == nullptr&&root->right == nullptr&&addarr == sum)
		{
			ret.push_back(arr);
			arr.pop_back();
			return;
		}
		if (root->left != nullptr)
			_pathSum(root->left, sum, ret, arr, addarr);
		if (root->right != nullptr)
			_pathSum(root->right, sum, ret, arr, addarr);
		arr.pop_back();
		return;
	}
};