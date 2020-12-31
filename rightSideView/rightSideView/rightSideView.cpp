#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;
/*
给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
    /   \
	2     3         <---
	 \     \
	   5     4       <---

	   来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/binary-tree-right-side-view
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

vector<int> rightSideView1(TreeNode* root) {
	vector<int> ret;
	if (root == nullptr)
		return ret;

	queue<TreeNode*> que;
	que.push(root);
	TreeNode* end = root;
	TreeNode* tmpend = nullptr;
	while (!que.empty())
	{
		TreeNode* node = que.front();
		que.pop();
		if (node->left != nullptr)
		{
			que.push(node->left);
			tmpend = node->left;
		}
		if (node->right != nullptr)
		{
			que.push(node->right);
			tmpend = node->right;
		}
		if (end == node)
		{
			ret.push_back(node->val);
			end = tmpend;
		}
	}
	return ret;
}

vector<int> rightSideView2(TreeNode* root) {
	vector<int> ret;
	if (root == nullptr)
		return ret;

	unordered_map<int, int> rightView;
	stack<TreeNode*> treestack;
	stack<int>       depthstack;

	treestack.push(root);
	depthstack.push(1);
	int max_depth = -1;

	while (!treestack.empty())
	{
		TreeNode* node = treestack.top();
		treestack.pop();
		int depth = depthstack.top();
		depthstack.pop();
		max_depth = max(max_depth, depth);

		if (rightView.find(depth) == rightView.end())
		{
			rightView.insert(make_pair(depth, node->val));
			//cout<<depth<<" "<<node->val<<endl;
		}
		if (node->left != nullptr)
		{
			treestack.push(node->left);
			depthstack.push(depth + 1);
		}

		if (node->right != nullptr)
		{
			treestack.push(node->right);
			depthstack.push(depth + 1);
		}

	}
	// for(auto& e:rightView)
	// {
	//     ret.push_back(e.second);
	// }
	for (int i = 1; i <= max_depth; ++i)
	{
		ret.push_back(rightView[i]);
	}
	return ret;
}


int main()
{
	return 0;
}