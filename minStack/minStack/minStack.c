#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include"minStack.h"


MinStack* minStackCreate() {
	MinStack*  Stack = (MinStack*)malloc(sizeof(MinStack));
	Stack->_Capacity = 2;
	Stack->_top = 0;
	Stack->_arr = (Datatype*)malloc(sizeof(MinStack)*Stack->_Capacity);
	Stack->_minarr = (Datatype*)malloc(sizeof(MinStack)*Stack->_Capacity);
	return Stack;
}

void minStackPush(MinStack* obj, int x) {
	assert(obj);
	if (obj->_Capacity == obj->_top)
	{
		obj->_Capacity *= 2;
		obj->_arr = (Datatype*)realloc(obj->_arr, sizeof(MinStack)*obj->_Capacity);
		obj->_minarr = (Datatype*)realloc(obj->_minarr, sizeof(MinStack)*obj->_Capacity);
	}
	//找最小的元素
	int min = 0;
	if (obj->_top == 0)
		min = x;
	else
		min = obj->_minarr[obj->_top - 1];
	if (min>x)
		min = x;


	obj->_arr[obj->_top] = x;
	obj->_minarr[obj->_top] = min;
	++obj->_top;


}

void minStackPop(MinStack* obj) {
	assert(obj);
	obj->_top -= 1;

}

int minStackTop(MinStack* obj) {
	assert(obj&&obj->_top >= 0);

	return obj->_arr[obj->_top - 1];

}

int minStackMin(MinStack* obj) {
	assert(obj&&obj->_top >= 0);

	return obj->_minarr[obj->_top - 1];

}

void minStackFree(MinStack* obj) {
	assert(obj);
	obj->_top = obj->_Capacity = 0;
	free(obj->_arr);
	obj->_arr = NULL;
	free(obj->_minarr);
	obj->_minarr = NULL;

}