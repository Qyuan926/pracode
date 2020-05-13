#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
/*����һ�ö��������������ö���������ת����һ�������ѭ��˫������
Ҫ���ܴ����κ��µĽڵ㣬ֻ�ܵ������нڵ�ָ���ָ��ת������Ժ����нڵ����ָ����Ҫָ��ǰ�������нڵ����ָ����Ҫָ���̡�����Ҫ���������еĵ�һ���ڵ��ָ�롣*/
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
		Node* pLastNodeInList = nullptr;//��¼˫�������е����һ���ڵ�λ��
		_treeToDoublyList(root, &pLastNodeInList);

		//�������һ���ڵ�λ��Ѱ��ͷ��㣬ͷ����������leftָ��ָ��nullptr
		Node* head = pLastNodeInList;
		while (head != nullptr&&head->left != nullptr)
		{
			head = head->left;
		}
		//�ҵ�ͷ��㣬���ӳ�������˫������
		head->left = pLastNodeInList;
		pLastNodeInList->right = head;
		return head;
	}
	void _treeToDoublyList(Node* root, Node** pLastNodeInList)
	{
		//�ڶ�������������ڵ��ֵС�ڸ��ڵ㣬�ҽڵ��ֵ���ڸ��ڵ�
		//����������������ɱ�������Ĺ�ϵ
		if (root == nullptr)
			return;
		Node* curNode = root;

		if (curNode->left != nullptr)
			_treeToDoublyList(curNode->left, pLastNodeInList);
		//�ݹ����������ҵ�������Сֵ�Ľڵ㣬��ʱpLastNodeInListΪ�գ����ô˷�����¼ͷ���
		//����ڵ�����ǰһ���ڵ�
		curNode->left = *pLastNodeInList;
		//����ڵ����Ӻ�һ���ڵ�
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