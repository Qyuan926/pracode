#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
char firstUniqChar(char* s){
	assert(s);
	int nums[256] = { 0 };
	char* string = s;
	while (*string != '\0')
	{
		nums[*string] += 1;
		string++;
	}
	string = s;
	while (*string != '\0')
	{
		if (nums[*string] == 1)
		{
			return *string;
		}
		string++;
	}
	return ' ';
}
int main()
{
	char* s = " ";
	char ret = firstUniqChar(s);
	printf("%c\n", firstUniqChar(s));
	return 0;
}