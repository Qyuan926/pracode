#define _CRT_SECURE_NO_WARNINGS 1
/*����һ�������һ���ض�ֵ x����������зָ���ʹ������С�� x �Ľڵ㶼�ڴ��ڻ���� x �Ľڵ�֮ǰ��

��Ӧ����������������ÿ���ڵ�ĳ�ʼ���λ�á�

ʾ��:

����: head = 1->4->3->2->5->2, x = 3
���: 1->2->2->4->3->5

*/

struct ListNode {
	int val;
	ListNode *next;
	
	
};
ListNode* partition(ListNode* head, int x) {
	ListNode* ret = nullptr;
	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}

	ListNode* list1 = new ListNode;
	ListNode* list2 = new ListNode;
	list1->next = nullptr;
	list2->next = nullptr;
	ListNode* tail1 = list1;
	ListNode* tail2 = list2;
	while (head != nullptr)
	{
		if (head->val<x)
		{
			tail1->next = head;
			tail1 = tail1->next;
		}
		else
		{
			tail2->next = head;
			tail2 = tail2->next;
		}
		head = head->next;
	}
	tail1->next = nullptr;
	tail2->next = nullptr;
	if (list1->next == nullptr || list2->next == nullptr)
	{
		if (list1->next == nullptr)
		{
			delete list1;
			ret = list2->next;
			delete list2;

		}
		else
		{
			delete list2;
			ret = list1->next;
			delete list1;

		}
	}
	else
	{
		tail1->next = list2->next;
		delete list2;
		ret = list1->next;
		delete list1;
	}
	return ret;
}