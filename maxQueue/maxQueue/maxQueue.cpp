#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


typedef struct {
	int* queue;
	int* maxqueue;
	int capacity;
	int Index;
	int maxIndex;
} MaxQueue;


MaxQueue* maxQueueCreate() {
	MaxQueue* ret = (MaxQueue*)malloc(sizeof(MaxQueue));
	ret->capacity = 4;
	ret->Index = ret->maxIndex = -1;
	ret->queue = (int*)malloc(sizeof(int)*(ret->capacity));
	ret->maxqueue = (int*)malloc(sizeof(int)*(ret->capacity));
	return ret;
}
void pop(int* arr, int length)
{
	for (int i = 0; i<length; ++i)
	{
		arr[i] = arr[i + 1];
	}


}

int maxQueueMax_value(MaxQueue* obj) {
	if (obj->Index == -1)
	{
		return -1;
	}
	return  obj->maxqueue[0];
}

void maxQueuePush_back(MaxQueue* obj, int value) {
	if ((obj->Index) == -1)
	{
		//队列为空，插入数据
		obj->queue[++(obj->Index)] = value;
		obj->maxqueue[++(obj->maxIndex)] = value;
	}
	else
	{
		//队列当中有数据，队尾插入数据
		//判断队列是否还有空间
		if (obj->capacity - 1 == obj->Index)
		{
			obj->capacity *= 2;
			obj->queue = (int*)realloc(obj->queue, sizeof(int)*(obj->capacity));
			obj->maxqueue = (int*)realloc(obj->maxqueue, sizeof(int)*(obj->capacity));
		}
		obj->queue[++(obj->Index)] = value;
		while (value>(obj->maxqueue[obj->maxIndex]))
		{
			--(obj->maxIndex);
			if (obj->maxIndex == -1)
				break;
		}
		obj->maxqueue[++(obj->maxIndex)] = value;
	}

}

int maxQueuePop_front(MaxQueue* obj) {
	//判断队列是否为空
	if (obj->Index == -1)
	{
		return -1;
	}
	int ret = obj->queue[0];
	if (obj->maxqueue[0] == obj->queue[0])
	{

		pop(obj->maxqueue, (obj->maxIndex));

		pop(obj->queue, (obj->Index));
		--(obj->maxIndex);
	}
	else{
		pop(obj->queue, (obj->Index));
	}
	--(obj->Index);
	return ret;
}

void maxQueueFree(MaxQueue* obj) {
	free(obj->queue);
	free(obj->maxqueue);
	free(obj);
	obj = NULL;
}


int main()
{
	MaxQueue* que = maxQueueCreate();

	maxQueuePush_back(que, 1);
	int push1 = maxQueueMax_value(que);
	printf("push1:%d\n", push1);
	maxQueuePush_back(que, 2);
	int push2 = maxQueueMax_value(que);
	printf("push2:%d\n", push2);
	/*maxQueuePush_back(que, 7);
	int push3 = maxQueueMax_value(que);
	printf("push3:%d\n", push3);
	maxQueuePush_back(que, 5);
	int push4 = maxQueueMax_value(que);
	printf("push4:%d\n", push4);
	maxQueuePush_back(que, 8);
	int push5 = maxQueueMax_value(que);
	printf("push5:%d\n", push5);
	maxQueuePush_back(que, 1);*/

	/*maxQueuePop_front(que);
	maxQueuePop_front(que);
	maxQueuePop_front(que);
	maxQueuePop_front(que);
	int push6= maxQueueMax_value(que);
	printf("push6:%d\n", push6);*/
	maxQueuePop_front(que);
	int push7 = maxQueueMax_value(que);
	

	maxQueueFree(que);
	return 0;
}