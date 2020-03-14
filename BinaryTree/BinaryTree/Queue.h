#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


typedef  BTNode* QDataType;
// 链式结构：表示队列 
typedef struct QListNode
{
	struct QListNode* _pNext;
	QDataType _data;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* _front;
	QNode* _back;
}Queue;

// 初始化队列 
void QueueInit(Queue* q);
// 队尾入队列 
void QueuePush(Queue* q, QDataType data);
// 队头出队列
void QueuePop(Queue* q);
// 获取队列头部元素 
QDataType QueueFront(Queue* q);
// 获取队列队尾元素 
QDataType QueueBack(Queue* q);
// 获取队列中有效元素个数 
int QueueSize(Queue* q);
// 检测队列是否为空，如果为空返回1，如果非空返回0 
int QueueEmpty(Queue* q);
// 销毁队列 
void QueueDestroy(Queue* q);



// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_back = NULL;

}
// 队尾入队列 
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
// 队头出队列
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
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_back->_data;
}
// 获取队列中有效元素个数 
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
// 检测队列是否为空，如果为空返回1，如果非空返回0 
int QueueEmpty(Queue* q)
{
	return q->_front == NULL ? 1 : 0;
}
// 销毁队列 
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