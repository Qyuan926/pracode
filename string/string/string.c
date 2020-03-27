#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>


char *strstr(const char *str, const char *strSet)
{
	assert(str);
	if (strSet == NULL)
		return NULL;
	char *str1 = (char* )str;
	char *str2 = (char*)strSet;
	while (*str1 != '\0')
	{
		char* Index = str1;
		str2 = (char*)strSet;
		while (*Index == *str2&&*Index != '\0'&&*str2 != '\0')
		{
			Index++;
			str2++;
		}
		if (*str2 == '\0')
		{
			return str1;
		}
		str1++;
	}
	return NULL;
}
//void *memcpy(void *dest, const void *src, size_t count)
//{
//	assert(dest&&src);
//	void* pret= dest;
//	while (count--)
//	{
//		*(char *)dest = *(char *)src;
//		
//		((char*)dest)++;
//		((char*)src)++;
//	}
//	return pret;
//}
void *memmove(void *dest, const void *src, size_t count)
{
	assert(dest&&src);
	void* ret = dest;
	if (dest>src)
	{
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	else
	{
		while (count--)
		{
			*(char*)dest = *(char*)src;
			((char*)dest)++;
			((char*)src)++;
		}
	}
	return ret;
}

int main()
{
	
	
	char* arr4 = "qqq";
	arr4 + 1;
	*arr4 = 'a';
	
	return 0;
}