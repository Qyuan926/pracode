#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>



struct ListNode {
int val;
struct ListNode *next;

};
typedef struct ListNode ListNode;

ListNode* partition(ListNode* pHead, int x) {
		// write code here
		ListNode* cur = pHead;
		if (cur==NULL)
		{
			return pHead;;
		}

		ListNode* lessHead = (ListNode*)malloc(sizeof(ListNode));
		lessHead->next = NULL;
		ListNode* lessTail = lessHead;


		ListNode*  moreHead = (ListNode*)malloc(sizeof(ListNode));
		moreHead->next = NULL;
		ListNode* moreTail = moreHead;


		while (cur)
		{
			if (cur->val<x)
			{
				lessTail->next = cur;
				lessTail = cur;

			}
			else{
				moreTail->next = cur;
				moreTail = cur;
			}
			cur = cur->next;
		}
		moreTail->next = NULL;
		lessTail->next = moreHead->next;

		ListNode* newhead = lessHead->next;
		free(lessHead);
		free(moreHead);
		return newhead;
	}



int main()
{
	ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));
	n1->val = 1;

	ListNode* n2 = (ListNode*)malloc(sizeof(ListNode));
	n2->val = 3;

	ListNode* n3 = (ListNode*)malloc(sizeof(ListNode));
	n3->val = 5;

	ListNode* n4 = (ListNode*)malloc(sizeof(ListNode));
	n4->val = 2;

	ListNode* n5 = (ListNode*)malloc(sizeof(ListNode));
	n5->val = 7;

	ListNode* n6 = (ListNode*)malloc(sizeof(ListNode));
	n6->val = 9;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = NULL;
	ListNode* ret=partition(n1, 4);
	return 0;
}