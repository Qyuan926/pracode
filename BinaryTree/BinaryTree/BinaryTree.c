#define _CRT_SECURE_NO_WARNINGS 1


#include"BinaryTree.h"
#include"Queue.h"
#include"Stack.h"




// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
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

//��������Ľڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->right) + BinaryTreeSize(root->left) + 1;
}

//������Ҷ�ӽ�����
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
//��������k��Ľڵ���
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL || k == 0)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root, k - 1) + BinaryTreeLevelKSize(root, k - 1);

}
// ������ǰ����� 
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
		printf("�ö�����Ϊ����\n");
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
// �������������
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
// �������������
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


//�������    �������н���ʵ��
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
//�ж�һ�����Ƿ�Ϊ��ȫ������
//�������ȫ���������������ʱ�����м䲻��Ϊ�ա�
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
	}
	//�������һ��������ǰ�������������ΪNULL����ֹѭ��
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		if (front == NULL)
			break;
		QueuePop(&q);
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}
	// �鿴ʣ�µĽڵ㣬���ȫΪNULL��Ϊ�������������Ƕ�����
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		if (front != NULL)
			return 0;
		QueuePop(&q);

	}
	return 1;
}