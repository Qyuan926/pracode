#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
};
//����һ���������������������ڵĽڵ㣬�����ؽ����������

ListNode* swapPairs(ListNode* head) {
	//��������в�������Node��ֱ�ӷ���
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
		//����slow ��fast�ڵ�
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

		//����
		slow = Next;
	}
	Tail->next = nullptr;
	ListNode* ret = Head->next;
	delete Head;
	
	return ret;
}
#if 0
//�ݹ鷽��
ListNode* swapPairs(ListNode* head) {
	if (head == NULL || head->next == NULL)  return head; //��ֹ����
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

