#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

void  TestStack()
{
	MyQueue* obj = myQueueCreate();
	myQueuePush(obj, 1);
	myQueuePush(obj, 2);
	myQueuePush(obj, 3);
	
	int ret = myQueuePeek(obj);
	printf("%d\n", ret);
}

int main()
{
	TestStack();

	return 0;
}