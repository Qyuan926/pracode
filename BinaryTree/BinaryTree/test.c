#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"



int main()
{
	BTDataType a[] = "ABC##DE#G##F###";
	
	int Index = 0;
	BTNode* ret = BinaryTreeCreate(a, &Index);
	BinaryTreePrevOrder(ret);
	printf("\n");
	printf("���Ľڵ����Ϊ%d\n", BinaryTreeSize(ret));
	printf("����Ҷ�ӽڵ����Ϊ%d\n", BinaryTreeLeafSize(ret));
	printf("���ĵ�k��ڵ����Ϊ%d\n", BinaryTreeLevelKSize(ret,3));
	
	return 0;
}



