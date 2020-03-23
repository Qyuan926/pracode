#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
 struct ListNode {
	int val;
	struct ListNode *next;
	
};
 typedef struct ListNode Node;
struct ListNode* insertionSortList(struct ListNode* head){
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	struct ListNode*  sortHead = (struct ListNode*)malloc(sizeof(struct ListNode));
	sortHead->next = head;
	struct ListNode* cur = head->next;
	head->next = NULL;
	while (cur != NULL)
	{
		struct ListNode*  curNext = cur->next;
		struct ListNode* sortPrev = sortHead;
		struct ListNode* sortCur = sortHead->next;
		while (sortCur != NULL)
		{
			if (sortCur->val<cur->val)
			{

				sortPrev = sortPrev->next;
				sortCur = sortCur->next;
			}
			else
			{
				break;
			}
		}
		sortPrev->next = cur;
		cur->next = sortCur;
		cur = curNext;
	}
	head = sortHead->next;
	free(sortHead);
	return head;
}


int main()
{
	
		Node* n1 = (Node*)malloc(sizeof(Node));
		n1->val = 1;
		Node* n2 = (Node*)malloc(sizeof(Node));
		n2->val = 2;
		Node* n3 = (Node*)malloc(sizeof(Node));
		n3->val = 3;
		Node* n4 = (Node*)malloc(sizeof(Node));
		n4->val = 3;
		Node* n5 = (Node*)malloc(sizeof(Node));
		n5->val = 4;
		Node* n6 = (Node*)malloc(sizeof(Node));
		n6->val = 4;
		Node* n7 = (Node*)malloc(sizeof(Node));
		n7->val = 5;

		n1->next = n2;
		n2->next = n3;
		n3->next = n4;
		n4->next = n5;
		n5->next = n6;
		n6->next = n7;
		n7->next = NULL;
		insertionSortList(n1);
		return 0;
	
}