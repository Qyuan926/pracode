#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct ListNode {
	int val;
	struct ListNode *next;
};


typedef struct ListNode  Node;
struct ListNode* deleteDuplicates(struct ListNode* head){
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	Node* slow = head;
	Node* fast = head->next;
	while (fast != NULL)
	{
		while (slow->val == fast->val&&fast != NULL)
		{
			Node* next = fast->next;
			slow->next = next;
			fast = fast->next;
			if (fast == NULL)
				break;

		}
		if (fast == NULL)
			break;
		slow = slow->next;
		fast = fast->next;
	}
	return head;
}