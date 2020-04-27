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
	//头结点为边界节点
	//叶节点为边界节点
	//树左边界延伸下去的路径为边界节点
	//树右边界延伸下去的路径为边界节点
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
namespace Printf2{
	//头结点为边界节点
	//叶节点为边界节点
	//树左边界延伸下去的路径为边界节点
	//树右边界延伸下去的路径为边界节点
	void printfleftEdge(TreeNode* Node,int print)
	{
		if (Node == nullptr)
		{
			return;
		}
		if (print || (Node->left == nullptr&&Node->right == nullptr))
		{
			printf("%c ", Node->value);
		}
		printfleftEdge(Node->left, print);
		printfleftEdge(Node->right, print&&Node->left == nullptr ? 1 : 0);

	}
	void printfrighttEdge(TreeNode* Node, int print)
	{
		if (Node == nullptr)
		{
			return;
		}
		printfrighttEdge(Node->left, print&&Node->right==nullptr?1:0);
		printfrighttEdge(Node->right, print);

		if (print || (Node->left == nullptr&&Node->right == nullptr))
		{
			printf("%c ", Node->value);
		}
		

	}
	void printfEdge2(TreeNode* root)
	{
		if (root == nullptr)
		{
			return;
		}
		printf("%c ", root->value);
		if (root->left)
		{
			printfleftEdge(root->left,1);
		}
		if (root->right!=nullptr)
		{
			printfrighttEdge(root->right, 1);
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
	printf("\n");
	Printf2::printfEdge2(root);

	return 0;
}