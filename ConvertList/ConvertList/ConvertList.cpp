#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
//����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
class Solution {
	void  Inorder(TreeNode* cur, TreeNode*& prev, TreeNode*& head)
	{
		if (cur == nullptr)
			return;
		Inorder(cur->left, prev, head);
		cur->left = prev;
		if (prev == nullptr)
			head = cur;
		else
			prev->right = cur;
		prev = cur;
		Inorder(cur->right, prev, head);
	}
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == nullptr)
			return nullptr;
		TreeNode* prev = nullptr;
		TreeNode* head = nullptr;
		Inorder(pRootOfTree, prev, head);
		return head;
	}
};