#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// ֧�ֶ�̬������ջ 
typedef BTNode* STDataType;
typedef struct Stack {
	STDataType _a[100];
	int _top;       // ջ��    
	
}
Stack;
// ��ʼ��ջ 
void StackInit(Stack* ps);
// ��ջ 
void StackPush(Stack* ps, STDataType data);
// ��ջ 
void StackPop(Stack* ps);
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps);
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps);
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ���1�������Ϊ�շ���0 
int StackEmpty(Stack* ps);
// ����ջ 
void StackDestroy(Stack* ps);


// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	//ps->_a = NULL;
	 ps->_top = 0;
}
// ��ջ 
void StackPush(Stack* ps, STDataType data)
{  //�ж��Ƿ����㹻�Ŀռ�
	if (ps->_top >=100)
	{
		
		printf("Insufficient memory available\n");
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
	
	ps->_top = 0;
}
