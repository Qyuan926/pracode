#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	
};



typedef  struct TreeNode Node;

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){

	if (preorder == NULL || inorder == NULL || preorderSize <= 0 || inorderSize <= 0)
	{
		return NULL;
	}
	//ǰ������ĵ�һ��Ԫ��Ϊ���ڵ㣬���úø��ڵ�
	Node* root = (Node*)malloc(sizeof(Node));
	root->val = *preorder;
	root->left = root->right = NULL;
	if (preorder[0] == preorder[preorderSize - 1])
		return root;
	//�����������Ѱ�Ҹ��ڵ��λ�ã��ҳ����������������Ľڵ�
	int Index = 0;
	while (Index<inorderSize&&inorder[Index] != root->val)
		++Index;
	int leftlength = Index;
	int rightlength = preorderSize - 1 - Index;
	if (leftlength>0)
	{
		root->left = buildTree(preorder + 1, leftlength, inorder, leftlength);
	}
	if (rightlength>0)
	{
		root->right = buildTree(preorder + Index + 1, rightlength, inorder + Index + 1, rightlength);
	}
	return root;
}



int main()
{

	int pre[5] = { 3, 9, 20, 15, 7 };
	int in[5] = { 9, 3, 15, 20, 7 };
	Node* ret = buildTree(pre, 5, in, 5);
	printf("%d", ret->val);
	return 0;
}