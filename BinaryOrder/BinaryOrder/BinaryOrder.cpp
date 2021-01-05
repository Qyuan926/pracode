#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	char value;
};
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
TreeNode* BinaryTreeCreate(char* a, int* Index)
{
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	if (a[*Index] == '#')
		return NULL;

	root->value = a[*Index];
	++(*Index);
	root->left = BinaryTreeCreate(a, Index);
	++(*Index);
	root->right = BinaryTreeCreate(a, Index);
	return root;
}
void inorderTraversal(TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	TreeNode* Node1 = root;
	TreeNode* Node2 = nullptr;
	while (Node1 != nullptr)
	{
		//指向左子树
		Node2 = Node1->left;
		if (Node2 != nullptr)
		{
			//找左子树的最右节点
			while (Node2->right != nullptr&&Node2->right != Node1)
			{
				Node2 = Node2->right;
			}
			//如果最右节点指向空，将最右节点的右指针指向Node1(即该子树的根节点)
			if (Node2->right == nullptr)
			{
				Node2->right = Node1;
				Node1 = Node1->left;
				continue;
			}
			else //(Node2->right == Node1)//如果最右节点的右指针指向Node1，即将该子树遍历完毕，将右指针指向nullptr（恢复原状）

			{
				Node2->right = nullptr;

			}
			
		}
		//cout << (Node1->value) << " " << endl;
		printf("%c ", Node1->value);
		Node1 = Node1->right;
		
	}
	cout << endl;
}
int main()
{
	char* a = "ABD##E#H##CF##G##";
	int Index = 0;
	TreeNode* root = BinaryTreeCreate(a, &Index);
	inorderTraversal(root);


	return 0;
}