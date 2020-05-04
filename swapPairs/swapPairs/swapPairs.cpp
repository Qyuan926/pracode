#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
};
//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表

ListNode* swapPairs(ListNode* head) {
	//如果链表中不足两个Node，直接返回
	if (head == nullptr || head->next == nullptr)
		return   head;

	ListNode* Head = new ListNode;
	ListNode* Tail = Head;
	ListNode* slow = head;
	ListNode* Next = nullptr;

	while (slow != nullptr)
	{
		ListNode* fast = slow->next;
		if (fast != nullptr)
			Next = fast->next;
		//交换slow 和fast节点
		if (fast != nullptr)
		{
			Tail->next = fast;
			Tail = Tail->next;//fast
			fast->next = slow;
			Tail = Tail->next;//slow
		}
		else
		{
			Tail->next = slow;
			Tail = Tail->next;
			break;
		}

		//迭代
		slow = Next;
	}
	Tail->next = nullptr;
	ListNode* ret = Head->next;
	delete Head;
	
	return ret;
}
#if 0
//递归方法
ListNode* swapPairs(ListNode* head) {
	if (head == NULL || head->next == NULL)  return head; //终止条件
	ListNode* node = head->next;
	head->next = swapPairs(head->next->next);
	node->next = head;
	return node;

}
#endif

int main()
{
	ListNode* n1 = new ListNode;
	n1->val = 1;
	ListNode* n2 = new ListNode;
	n2->val = 2;
	ListNode* n3 = new ListNode;
	n3->val = 3;
	ListNode* n4 = new ListNode;
	n4->val = 4;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = nullptr;
	swapPairs(n1);

	return 0;
}

