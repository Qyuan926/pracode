#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	char value;
};
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
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
		//ָ��������
		Node2 = Node1->left;
		if (Node2 != nullptr)
		{
			//�������������ҽڵ�
			while (Node2->right != nullptr&&Node2->right != Node1)
			{
				Node2 = Node2->right;
			}
			//������ҽڵ�ָ��գ������ҽڵ����ָ��ָ��Node1(���������ĸ��ڵ�)
			if (Node2->right == nullptr)
			{
				Node2->right = Node1;
				Node1 = Node1->left;
				continue;
			}
			else //(Node2->right == Node1)//������ҽڵ����ָ��ָ��Node1������������������ϣ�����ָ��ָ��nullptr���ָ�ԭ״��

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