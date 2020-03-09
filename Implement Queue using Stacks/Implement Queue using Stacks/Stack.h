#pragma  once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>



typedef int STDataType;
// ֧�ֶ�̬������ջ 
typedef int STDataType;
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




typedef struct {
	Stack pstpush;
	Stack pstpop;

} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* Que = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&(Que->pstpush));
	StackInit(&Que->pstpop);
	return Que;

}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	/*while (1)
	{
		if (StackEmpty(&obj->pstpush) == 1)
		{*/
			StackPush(&obj->pstpush, x);
		/*	break;
		}
		else
		{
			StackPush(&obj->pstpop, StackTop(&obj->pstpush));
			StackPop(&obj->pstpush);
		}
	}*/
}
/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	int  top = 0;
	while (1)
	{
		if (StackEmpty(&obj->pstpop) == 0)
		{
			top = StackTop(&obj->pstpop);
			StackPop(&obj->pstpop);
			break;
		}
		else
		{
			while (StackEmpty(&obj->pstpush) == 0)
			{
				StackPush(&obj->pstpop, StackTop(&obj->pstpush));
				StackPop(&obj->pstpush);
			}

		}
	}
	return top;
}
/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	while (1)
	{
		if (StackEmpty(&obj->pstpop) == 0)
		{
			int top = StackTop(&obj->pstpop);
			return top;
		}
		else
		{
			while (StackEmpty(&obj->pstpush) == 0)
			{
				StackPush(&obj->pstpop, StackTop(&obj->pstpush));
				StackPop(&obj->pstpush);
			}


		}
	}
}

/** Returns whether the queue is empty. */
int myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->pstpush) == 1 && StackEmpty(&obj->pstpop) == 1;

}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->pstpush);
	StackDestroy(&obj->pstpop);
	free(obj);
	obj = NULL;

}