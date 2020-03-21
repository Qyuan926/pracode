#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
	
};

typedef struct ListNode Node;
struct ListNode *detectCycle(struct ListNode *head) {
	Node* slow = head;
	Node* fast = head;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
		{
			Node* meet = fast;
			Node* start = head;
			Node* meet_start = meet->next;
			size_t i = 0, j = 0;
			while (start != meet)
			{
				start = start->next;
				++i;
			}
			while (meet_start != meet)
			{
				meet_start = meet_start->next;
				++j;
			}
			meet_start = meet->next;
			start = head;
			if (i>j)
			{
				size_t k = i - j;
				while (k--)
				{
					start = start->next;
				}

			}
			else
			{
				size_t k = j - i;
				while (k--)
				{
					meet_start = meet_start->next;
				}
			}
			while (start != meet_start)
			{
				start = start->next;
				meet_start = meet_start->next;
			}
			return start;

		}
	}
	return NULL;
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
	n4->val = 4;
	Node* n5 = (Node*)malloc(sizeof(Node));
	n5->val = 5;
	Node* n6 = (Node*)malloc(sizeof(Node));
	n6->val = 6;
	Node* n7 = (Node*)malloc(sizeof(Node));
	n7->val = 7;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n4;
	detectCycle(n1);
	return 0;
}