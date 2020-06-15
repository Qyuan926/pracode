#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == nullptr)
			return head;
		ListNode* newhead = new ListNode(0);
		newhead->next = head;
		ListNode* prev = newhead;
		ListNode* cur = head;
		while (cur != nullptr)
		{
			for (int i = 1; i<k; ++i)
			{
				cur = cur->next;
				if (cur == nullptr)
				{
					ListNode* ret = newhead->next;
					delete newhead;
					return ret;

				}
					
			}
			ListNode* next = cur->next;
			pair<ListNode*, ListNode*> ret = _reverseKNode(prev->next, cur);
			ListNode* begin = ret.first;
			ListNode* end = ret.second;
			prev->next = begin;
			end->next = next;
			prev = end;
			cur = next;
		}
		ListNode* ret = newhead->next;
		delete newhead;
		return ret;

	}
private:
	pair<ListNode*, ListNode*> _reverseKNode(ListNode* head, ListNode* tail) {
		ListNode* prev = tail->next;
		ListNode* p = head;
		while (prev != tail) {
			ListNode* nex = p->next;
			p->next = prev;
			prev = p;
			p = nex;
		}
		return pair<ListNode*, ListNode*>(tail, head);
	}
};

int main()
{
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = nullptr;
	Solution s;
	s.reverseKGroup(n1, 2);
	return 0;
}