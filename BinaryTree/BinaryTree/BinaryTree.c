#define _CRT_SECURE_NO_WARNINGS 1


#include"BinaryTree.h"
#include"Queue.h"
#include"Stack.h"




// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int* Index)
{
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (a[*Index] == '#')
		return NULL;
	
	root->_Data = a[*Index];
	++(*Index);
	root->left = BinaryTreeCreate(a, Index);
	++(*Index);
	root->right = BinaryTreeCreate(a, Index);
	return root;
}

//求二叉树的节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->right) + BinaryTreeSize(root->left) + 1;
}

//二叉树叶子结点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL&&root->right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);

}
//二叉树第k层的节点数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL || k == 0)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root, k - 1) + BinaryTreeLevelKSize(root, k - 1);

}
// 二叉树前序遍历 
//void BinaryTreePrevOrder(BTNode* root)
//{
//
//	if (root == NULL)
//		return;
//	printf("%c ", root->_Data);
//	BinaryTreePrevOrder(root->left);
//	BinaryTreePrevOrder(root->right);
//}
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("该二叉树为空树\n");
		return;
	}
	Stack s;
	StackInit(&s);
	StackPush(&s, root);
	while (!StackEmpty(&s))
	{
		root = StackTop(&s);
		printf("%c ",root->_Data );
		StackPop(&s);
		if (root->right != NULL)
			StackPush(&s, root->right);
		if (root->left != NULL)
			StackPush(&s, root->left);
	}

}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeInOrder(root->left);
	printf("%c ", root->_Data);
	BinaryTreeInOrder(root->right);

}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeInOrder(root->left);
	
	BinaryTreeInOrder(root->right);
	printf("%c ", root->_Data);
}


//层序遍历    依靠队列进行实现
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		printf("%c ", front->_Data);
		QueuePop(&q);
		if (front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q, front->right);
	}



}
//判断一棵树是否为完全二叉树
//如果是完全二叉树，层序遍历时数据中间不会为空。
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
	}
	//层序遍历一棵树，当前遍历的数据如果为NULL，终止循环
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		if (front == NULL)
			break;
		QueuePop(&q);
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	// 查看剩下的节点，如果全为NULL则为二叉树，否则不是二叉树
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		if (front != NULL)
			return 0;
		QueuePop(&q);

	}
	return 1;
}