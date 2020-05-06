#define _CRT_SECURE_NO_WARNINGS 1
/*给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5

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