#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode *next;
	
};
//����Ϊ����ָ���˼��
typedef  struct ListNode  Node;
struct ListNode* deleteDuplicates(struct ListNode* pHead){
	if (pHead == NULL || pHead->next == NULL)
	{
		return pHead;
	}
	Node* pNode = pHead;
	Node* prev = NULL;
	//�൱����ԭ����������һ��ͷ��㡣
	while (pNode != NULL)
	{
		Node* pNext = pNode->next;
		int flag = 1;
		if (pNext != NULL&&pNode->val == pNext->val)
		{
			flag = 0;
		}
		//������ȣ�ָ�����µ���
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
				pHead = pNext;//�����ͷ��㿪ʼ���������ڵ��ֵ��ȣ�����Ҫ��ͷ�ڵ��ƶ�����һ�����ȵ�λ�á�
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