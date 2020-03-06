#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
typedef struct ListNode Node;
struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
	int len = 0;//记录链表的长度
	Node* cur = head;
	Node* pre_m = NULL;
	Node* next_n = NULL;
	//找出第m个节点的前一个节点
	//找出第n个节点的后一个节点
	while (cur != NULL)
	{
		++len;
		if (len == m - 1)
		{
			pre_m = cur;//如果m为1则pre_m为NULL；
		}
		if (len == n + 1)
		{
			next_n = cur;
		}
		cur = cur->next;
	}
	cur = pre_m == NULL ? head : pre_m->next;
	//
	Node* cur_n = cur->next;
	Node* cur_nn = NULL;
	cur->next = next_n;
	while (cur_n != next_n)
	{
		cur_nn = cur_n->next;
		cur_n->next = cur;
		cur = cur_n;
		cur_n = cur_nn;

	}
	if (pre_m == NULL)
	{
		return cur;
	}
	pre_m->next = cur;
	return head;
}
int main()
{
	Node* n1 = (Node*)malloc(sizeof(Node));
	n1->val = 1;

	Node* n2 = (Node*)malloc(sizeof(Node));
	n2->val = 2;

	Node* n3 = (Node*)malloc(sizeof(Node));
	n3->val =3;

	Node* n4 = (Node*)malloc(sizeof(Node));
	n4->val = 4;

	Node* n5 = (Node*)malloc(sizeof(Node));
	n5->val = 5;

	Node* n6 = (Node*)malloc(sizeof(Node));
	n6->val = 6;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = NULL;
	reverseBetween(n1, 2, 4);
	return 0;
}