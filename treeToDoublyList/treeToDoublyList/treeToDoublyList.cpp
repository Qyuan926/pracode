#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
/*输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
要求不能创建任何新的节点，只能调整树中节点指针的指向转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。*/
class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node() {}

	Node(int _val) {
		val = _val;
		left = NULL;
		right = NULL;
	}

	Node(int _val, Node* _left, Node* _right) {
		val = _val;
		left = _left;
		right = _right;
	}
};
class Solution {
public:
	Node* treeToDoublyList(Node* root) {
		if (root == nullptr)
			return root;
		Node* pLastNodeInList = nullptr;//记录双向链表中的最后一个节点位置
		_treeToDoublyList(root, &pLastNodeInList);

		//利用最后一个节点位置寻找头结点，头结点的特征是left指针指向nullptr
		Node* head = pLastNodeInList;
		while (head != nullptr&&head->left != nullptr)
		{
			head = head->left;
		}
		//找到头结点，连接成完整的双向链表
		head->left = pLastNodeInList;
		pLastNodeInList->right = head;
		return head;
	}
	void _treeToDoublyList(Node* root, Node** pLastNodeInList)
	{
		//在二叉搜索树中左节点的值小于父节点，右节点的值大于父节点
		//采用中序遍历树，可保持有序的关系
		if (root == nullptr)
			return;
		Node* curNode = root;

		if (curNode->left != nullptr)
			_treeToDoublyList(curNode->left, pLastNodeInList);
		//递归左子树，找到树种最小值的节点，此时pLastNodeInList为空，可用此方法记录头结点
		//链表节点链接前一个节点
		curNode->left = *pLastNodeInList;
		//链表节点链接后一个节点
		if (*pLastNodeInList != nullptr)
		{
			(*pLastNodeInList)->right = curNode;
		}

		(*pLastNodeInList) = curNode;

		if (curNode->right != nullptr)
			_treeToDoublyList(curNode->right, pLastNodeInList);
	}
};


int main()
{
	Node* root = new Node;
	root->val = 4;
	Node* node1 = new Node;
	node1->val = 1;
	Node* node2 = new Node;
	node2->val = 2;
	Node* node3 = new Node;
	node3->val = 3;
	Node* node5 = new Node;
	node5->val = 5;
	root->left = node2;
	root->right = node5;
	node5->left = nullptr;
	node5->right = nullptr;
	node2->left = node1;
	node2->right = node3;
	node1->left = nullptr;
	node1->right = nullptr;
	node3->left = nullptr;
	node3->right = nullptr;
	Solution s;
	Node* ret=s.treeToDoublyList(root);
	return 0;
}