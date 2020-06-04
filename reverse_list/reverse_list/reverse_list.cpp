#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
using namespace std;

struct list_node{
	int val;
	struct list_node * next;
};

list_node * input_list(void)
{
	int n, val;
	list_node * phead = new list_node();
	list_node * cur_pnode = phead;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &val);
		if (i == 1) {
			cur_pnode->val = val;
			cur_pnode->next = NULL;
		}
		else {
			list_node * new_pnode = new list_node();
			new_pnode->val = val;
			new_pnode->next = NULL;
			cur_pnode->next = new_pnode;
			cur_pnode = new_pnode;
		}
	}
	return phead;
}

typedef list_node node;
list_node * reverse_list(list_node * head, int L, int R)
{
	//////在下面完成代码
	node* prev = nullptr;
	node* begin = nullptr;
	node*  cur = head;
	node* end = nullptr;
	node* next = nullptr;
	//找到要旋转部分的开始和结尾以及开的节点的前一个和结尾节点的后一个
	int len = 1;
	while (cur != nullptr)
	{
		prev = len + 1 == L ? cur : prev;
		begin = len == L ? cur : begin;
		end = len == R ? cur : end;
		next = len == R + 1 ? cur : next;
		cur = cur->next;
		len++;
	}

	node* Node = nullptr;
	if (begin != nullptr)
		Node = begin->next;
	while (Node != nullptr&&Node != end)
	{
		begin->next = next;
		next = begin;
		begin = Node;
		if (begin != nullptr)
			Node = begin->next;
	}
	begin->next = next;
	end->next = begin;
	if (prev == nullptr)
	{
		return end;
	}
	else
	{
		prev->next = end;
	}
	return head;


}

void print_list(list_node * head)
{
	while (head != NULL) {
		printf("%d ", head->val);
		head = head->next;
	}
	puts("");
}


int main()
{
	int L, R;
	list_node * head = input_list();
	scanf("%d%d", &L, &R);
	list_node * new_head = reverse_list(head, L, R);
	print_list(new_head);
	return 0;
}