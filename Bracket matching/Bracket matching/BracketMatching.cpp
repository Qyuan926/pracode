#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef char STDataType;
typedef struct Stack {
	STDataType* _a;
	int _top;       // ջ��    
	int _capacity;  // ����
}
Stack;
// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}
// ��ջ 
void StackPush(Stack* ps, STDataType data)
{  //�ж��Ƿ����㹻�Ŀռ�
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		STDataType* p = (STDataType*)realloc(ps->_a, newcapacity*(sizeof(Stack)));
		if (p == NULL)
		{
			printf("Insufficient memory available\n");

		}
		else
		{
			ps->_a = p;
		}
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = data;
	ps->_top++;
}
// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps&&ps->_top>0);
	--ps->_top;

}
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	assert(ps&&ps->_top > 0);
	return ps->_a[ps->_top - 1];
}
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	return ps->_top;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	return ps->_top == 0 ? 1 : 0;
}
// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}




bool isValid(char * s){
	if (s == NULL)
	{
		return false;
	}
	Stack sta;
	StackInit(&sta);
	char* arr[3] = { "()", "{}", "[]" };
	while (*s != '\0')
	{
		if (*s == arr[0][0] || *s == arr[1][0] || *s == arr[2][0])
		{
			StackPush(&sta, *s);
		}
		else
		{
			if (StackEmpty(&sta))
			{
				return false;
			}
			char c = StackTop(&sta);
			if (*s == arr[0][1])
			{
				if (c != arr[0][0])
				{
					return false;
				}
			}
			if (*s == arr[1][1])
			{
				if (c != arr[1][0])
				{
					return false;
				}
			}
			if (*s == arr[2][1])
			{
				if (c != arr[2][0])
				{
					return false;
				}
			}

			StackPop(&sta);

		}
		++s;
	}
	int  flag = StackEmpty(&sta);
	StackDestroy(&sta);
	return flag;
}




int main()
{
	char* s = "({[]][";
	bool ret=isValid(s);
	return 0;
}