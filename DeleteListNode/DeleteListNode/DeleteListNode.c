#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
	int val;
	struct ListNode * next;
};

typedef struct ListNode Node;
struct ListNode* deleteNode(struct ListNode* head, int val){
	if (head == NULL)
		return head;
	struct ListNode* cur = head;
	while (cur->next != NULL)
	{
		if (cur->val == val&&cur->next != NULL)
		{
			cur->val = cur->next->val;
			cur->next = cur->next->next;
			return head;
		}

		cur = cur->next;
	}
	if (cur->val == val&&cur->next == NULL)
	{
		cur = head;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = NULL;
		return head;
	}
	return NULL;

}
void Print(Node* L)
{
	while (L != NULL)
	{
		printf("%d ->", L->val);
		L = L->next;
	}
	printf("NULL\n");
}

int main()
{
	Node* n1 = (Node*)malloc(sizeof(Node));
	n1->val = 1;

	Node* n2 = (Node*)malloc(sizeof(Node));
	n2->val = 2;

	Node* n3 = (Node*)malloc(sizeof(Node));
	n3->val = 3;
	
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;
	//Node* ret1 = deleteNode(n1, 1);
	//Print(ret1);
	Node* ret2 = deleteNode(n1, 3);
	
	Print(ret2);
}