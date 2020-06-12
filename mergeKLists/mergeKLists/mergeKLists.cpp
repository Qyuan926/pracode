#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x=0) : val(x), next(NULL) {}
	
};


class Solution {
	ListNode* _mergeTwolists(ListNode* list1, ListNode* list2)
	{
		if (list1 == nullptr)
			return list2;
		if (list2 == nullptr)
			return list1;
		ListNode* Head = new ListNode;
		ListNode* Tail = Head;
		while (list1 != nullptr || list2 != nullptr)
		{
			if (list1 != nullptr&&list2 != nullptr)
			{
				if (list1->val >= list2->val)
				{
					Tail->next = list2;
					list2 = list2->next;
				}
				else
				{
					Tail->next = list1;
					list1 = list1->next;
				}
			}
			else if (list1 != nullptr)
			{
				Tail->next = list1;
				list1 = list1->next;
			}
			else{
				Tail->next = list2;
				list2 = list2->next;
			}
			Tail = Tail->next;
		}
		Tail->next = nullptr;
		ListNode* ret = Head->next;
		delete Head;
		return  ret;
	}
	ListNode* _mergeKlists(vector<ListNode*>& lists, int left, int right)
	{
		if (left == right)
			return lists[left];
		if (left>right)
			return nullptr;
		int mid = left + ((right - left) >> 1);
		return  _mergeTwolists(_mergeKlists(lists, left, mid), _mergeKlists(lists, mid + 1, right));
	}
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty())
			return nullptr;
		if (lists.size() == 1)
			return lists[0];
		return  _mergeKlists(lists, 0, lists.size() - 1);
	}
};