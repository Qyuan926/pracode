#define _CRT_SECURE_NO_WARNINGS 1
#include"minStack.h"






int main()
{
	MinStack*  s = minStackCreate();
	minStackPush(s, -2);
	minStackPush(s, 3);
	minStackPush(s, 2);
	printf("%d\n",minStackTop(s));
	printf("%d\n", minStackMin(s));
	minStackPop(s);

	minStackFree(s);
	return 0;
}