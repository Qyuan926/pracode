#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


typedef  BTNode* QDataType;
// ��ʽ�ṹ����ʾ���� 
typedef struct QListNode
{
	struct QListNode* _pNext;
	QDataType _data;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* _front;
	QNode* _back;
}Queue;

// ��ʼ������ 
void QueueInit(Queue* q);
// ��β����� 
void QueuePush(Queue* q, QDataType data);
// ��ͷ������
void QueuePop(Queue* q);
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q);
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q);
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q);
// �������Ƿ�Ϊ�գ����Ϊ�շ���1������ǿշ���0 
int QueueEmpty(Queue* q);
// ���ٶ��� 
void QueueDestroy(Queue* q);



// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_back = NULL;

}
// ��β����� 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	newnode->_data = data;
	newnode->_pNext = NULL;
	if (q->_back == NULL)
	{
		q->_front = q->_back = newnode;
	}
	else
	{
		q->_back->_pNext = newnode;
		q->_back = newnode;
	}
}
// ��ͷ������
void QueuePop(Queue* q)
{
	assert(q);
	QNode* next = q->_front->_pNext;
	free(q->_front);
	q->_front = next;
	if (q->_front == NULL)
	{
		q->_back = q->_front = NULL;
	}
}
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_back->_data;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	int n = 0;
	QNode* cur = q->_front;
	while (cur != NULL)
	{
		++n;
		cur = cur->_pNext;
	}
	return n;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ���1������ǿշ���0 
int QueueEmpty(Queue* q)
{
	return q->_front == NULL ? 1 : 0;
}
// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	QNode* cur = q->_front;
	while (cur != NULL)
	{
		QNode* next = cur->_pNext;
		free(cur);
		cur = next;
	}
	q->_back = q->_front = NULL;
}