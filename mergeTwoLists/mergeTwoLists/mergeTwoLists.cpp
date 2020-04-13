#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
struct List{
	int data_;
	List* next_;
};
typedef struct List  List;
List* CreateList(int* num, int length)
{
	List* Head = new  List;
	List* Tail = Head;
	for (int i = 0; i<length; ++i)
	{
		List* list = new List;
		list->data_ = num[i];
		list->next_ = NULL;
		Tail->next_ = list;
		Tail = list;
	}

	List* ret = Head->next_;
	delete Head;
	return ret;
}
List* mergeList(List* List1, List*  List2)
{
	if (List1 == NULL)
	{
		return List2;
	}
	if (List2 == NULL)
	{
		return List1;
	}
	List* Head = new List;
	List* Tail = Head;
	while (List1 != NULL&&List2 != NULL)
	{
		if (List1->data_<List2->data_)
		{
			Tail->next_ = List1;
			List1 = List1->next_;
		}
		else
		{
			Tail->next_ = List2;
			List2 = List2->next_;
		}
		Tail = Tail->next_;
	}
	while (List1 != NULL)
	{
		Tail->next_ = List1;
		List1 = List1->next_;
		Tail = Tail->next_;
	}
	while (List2 != NULL)
	{
		Tail->next_ = List2;
		List2 = List2->next_;
		Tail = Tail->next_;
	}
	Tail->next_ = NULL;
	List* ret = Head->next_;
	delete Head;
	return ret;
}
int main()
{
	int num;
	char ch;
	int length1 = 0;
	int length2 = 0;
	int* arr1 = new int[1000];
	int* arr2 = new int[1000];
	while ((scanf("%d%c", &num, &ch)>0))
	{
		arr1[length1++] = num;
		if (ch == '\n')
			break;
	}
	while ((scanf("%d%c", &num, &ch)>0))
	{
		arr2[length2++] = num;
		if (ch == '\n')
			break;
	}
	List* List1 = CreateList(arr1, length1);
	List* List2 = CreateList(arr2, length2);
	List* retHead = mergeList(List1, List2);
	List* cur = retHead;
	while (cur != NULL)
	{
		cout << cur->data_ << ' ';
		cur = cur->next_;
	}

	return 0;
}