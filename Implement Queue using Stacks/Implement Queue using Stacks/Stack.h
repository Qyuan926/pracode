#pragma  once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>



typedef int STDataType;
// 支持动态增长的栈 
typedef int STDataType;
typedef struct Stack {
	STDataType* _a;
	int _top;       // 栈顶    
	int _capacity;  // 容量
}
Stack;
// 初始化栈 
void StackInit(Stack* ps)
{
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}
// 入栈 
void StackPush(Stack* ps, STDataType data)
{  //判断是否有足够的空间
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
// 出栈 
void StackPop(Stack* ps)
{
	assert(ps&&ps->_top>0);
	--ps->_top;

}
// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	assert(ps&&ps->_top > 0);
	return ps->_a[ps->_top - 1];
}
// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	return ps->_top;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	return ps->_top == 0 ? 1 : 0;
}
// 销毁栈 
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