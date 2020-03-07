#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode *next;
	
};
//整体为快满指针的思想
typedef  struct ListNode  Node;
struct ListNode* deleteDuplicates(struct ListNode* pHead){
	if (pHead == NULL || pHead->next == NULL)
	{
		return pHead;
	}
	Node* pNode = pHead;
	Node* prev = NULL;
	//相当于在原链表上增加一个头结点。
	while (pNode != NULL)
	{
		Node* pNext = pNode->next;
		int flag = 1;
		if (pNext != NULL&&pNode->val == pNext->val)
		{
			flag = 0;
		}
		//如果不等，指针向下迭代
		if (flag)
		{
			prev = pNode;
			pNode = pNext;
		}
		else
		{
			while (pNext != NULL&&pNode->val == pNext->val)
			{
				pNext = pNext->next;
			}
			if (prev == NULL)
			{
				pHead = pNext;//如果从头结点开始两个或多个节点的值相等，则需要将头节点移动到第一个不等的位置。
			}
			else
			{
				prev->next = pNext;
			}
			pNode = pNext;
		}
	}
	return pHead;
}