#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	char value;
};


namespace Printf1{
	int TreeHeight(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int left = TreeHeight(root->left);
		int right = TreeHeight(root->right);
		return 1 + max(left, right);
	}

	void setEdgemap(TreeNode* root, int Index, vector<vector<TreeNode*>> & map)
	{
		if (root == nullptr)
		{
			return;
		}
		map[0][Index] = map[0][Index] == nullptr ? root : map[0][Index];
		map[1][Index] = root;
		setEdgemap(root->left, Index + 1, map);
		setEdgemap(root->right, Index + 1, map);
	}
	void setmidEdgemap(TreeNode* root, int Index, vector<vector<TreeNode*>>& map)
	{
		if (root == nullptr)
		{
			return;
		}
		if (root->left == nullptr&&root->right == nullptr&&map[0][Index] != root&&map[1][Index] != root)
		{
			cout << (root->value) << ' ';
		}
		setmidEdgemap(root->left, Index + 1, map);
		setmidEdgemap(root->right, Index + 1, map);

	}

	void printfEdge1(TreeNode* root)
	{
		int height = TreeHeight(root);
		vector<vector<TreeNode*>> map(2, vector<TreeNode*>(height, nullptr));
		//确定边界的值
		setEdgemap(root, 0, map);
		for (int i = 0; i < height; ++i)
		{
			cout << map[0][i]->value << ' ';
		}
		setmidEdgemap(root, 0, map);
		for (int i = height - 1; i >= 0; --i)
		{
			if (map[0][i] != map[1][i])
			cout << map[1][i]->value << ' ';
		}

	}
	
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

int main()
{
	//char a[] = { '1', '2', '#', '4','7','#','#','8','#','b','d','#','#','e','#','#','3','5','9','c','f','#','#','g','#','#','#','a','#','#','6','#','#'};
	char* a = "12#47##8#bd##e##359cf##g###a##6##";
	int Index = 0;
	TreeNode* root=BinaryTreeCreate(a, &Index);
	Printf1::printfEdge1(root);

	return 0;
}