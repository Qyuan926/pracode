#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int Datatype;
typedef struct {
	Datatype* _arr;
	Datatype* _minarr;
	int _Capacity;
	int _top;
} MinStack;


MinStack* minStackCreate();

void minStackPush(MinStack* obj, int x);

void minStackPop(MinStack* obj);

int minStackTop(MinStack* obj);
int minStackMin(MinStack* obj); 
void minStackFree(MinStack* obj);