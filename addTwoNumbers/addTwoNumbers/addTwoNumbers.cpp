#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	
};
/*给定两个用链表表示的整数，每个节点包含一个数位。

这些数位是反向存放的，也就是个位排在链表首部。

编写函数对这两个整数求和，并用链表形式返回结果。
示例：

输入：(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
输出：2 -> 1 -> 9，即912
*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	if (l1 == nullptr)
	{
		return l2;
	}
	if (l2 == nullptr)
	{
		return l1;
	}
	ListNode* Head = new ListNode;
	ListNode* Tail = Head;
	ListNode* cur1 = l1;
	ListNode* cur2 = l2;
	int num = 0;
	int carry = 0;

	int val1 = 0;
	int val2 = 0;
	while (cur1 != nullptr || cur2 != nullptr)
	{
		val1 = cur1 == nullptr ? 0 : cur1->val;
		val2 = cur2 == nullptr ? 0 : cur2->val;

		num = val1 + val2 + carry;

		ListNode* Node = new ListNode;
		Node->val = (num % 10);
		carry = num / 10;
		Tail->next = Node;
		Tail = Tail->next;
		if (cur1 != nullptr)
			cur1 = cur1->next;
		if (cur2 != nullptr)
			cur2 = cur2->next;
	}
	if (carry != 0)
	{
		ListNode* Node = new ListNode;
		Node->val = carry;
		Tail->next = Node;
		Tail = Tail->next;

	}
	Tail->next = nullptr;
	ListNode* ret = Head->next;
	delete Head;
	return ret;
}
/*
输入：(6 -> 1 -> 7) + (2 -> 9 -> 5)，即617 + 295
输出：9 -> 1 -> 2，即912
*/
ListNode*  reverseList(ListNode* head)
{
	if (head == nullptr)
	{
		return head;
	}
	ListNode* prev = head;

	ListNode* cur = head->next;
	prev->next = nullptr;
	while (cur != nullptr)
	{
		ListNode* next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;

	}
	return prev;
}

	ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)
		{
			return l2;
		}
		if (l2 == nullptr)
		{
			return l1;
		}

		stack<ListNode> s1;
		stack<ListNode> s2;
		while (l1 != nullptr)
		{
			s1.push(*l1);
			l1 = l1->next;
		}
		while (l2 != nullptr)
		{
			s2.push(*l2);
			l2 = l2->next;
		}
		ListNode* Head = new ListNode;
		ListNode* Tail = Head;
		int num = 0, carry = 0;
		while (!s1.empty() || !s2.empty())
		{
			int val1 = s1.empty() == true ? 0 : s1.top().val;
			int val2 = s2.empty() == true ? 0 : s2.top().val;
			s1.pop();
			s2.pop();

			num = val1 + val2 + carry;
			ListNode* Node = new ListNode;
			Node->val = num % 10;
			carry = num / 10;
			Tail->next = Node;
			Tail = Tail->next;
		}
		if (carry != 0)
		{
			ListNode* Node = new ListNode;
			Node->val = carry;
			Tail->next = Node;
			Tail = Tail->next;
		}
		Tail->next = nullptr;
		ListNode* head = Head->next;
		ListNode* ret = reverseList(head);
		return ret;
	}




int main()
{
	ListNode* n1 = new ListNode;
	n1->val = 6;
	ListNode* n2 = new ListNode;
	n2->val = 1;
	ListNode* n3 = new ListNode;
	n3->val =7;
	n1->next = n2;
	n2->next = n3;
	n3->next = nullptr;

	ListNode* N1 = new ListNode;
	N1->val = 2;
	ListNode* N2 = new ListNode;
	N2->val = 9;
	ListNode* N3 = new ListNode;
	N3->val = 5;
	N1->next = N2;
	N2->next = N3;
	N3->next = nullptr;
	ListNode* ret=addTwoNumbers2(N1, n1);
	return 0;
}