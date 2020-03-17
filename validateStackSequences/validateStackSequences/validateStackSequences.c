#define _CRT_SECURE_NO_WARNINGS 1
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

int validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
	// assert(pushed&&pushedSize>0&&popped&&poppedSize>0);
	Stack s;
	StackInit(&s);
	int i = 0, j = 0;
	while (i<pushedSize)
	{
		while (i<pushedSize&&pushed[i] != popped[j])
		{
			StackPush(&s, pushed[i]);
			++i;
		}
		if (i<pushedSize&&pushed[i] == popped[j])
		{
			StackPush(&s, pushed[i]);
			StackPop(&s);
			++j;
			++i;
		}
		while (!StackEmpty(&s) && StackTop(&s) == popped[j])
		{
			StackPop(&s);
			++j;
		}

		if (!StackEmpty(&s) && i >= pushedSize)
			return 0;
	}


	return 1;

}



int main()
{
	
		int pushed[5] = { 1, 2, 3, 4, 5 };
	int popped[5] = { 4, 5, 3, 2, 1 };
	printf("%d\n", validateStackSequences(pushed, 5, popped, 5));
	return 0;
}