#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"



int main()
{
	BTDataType a[] = "ABC##DE#G##F###";
	
	int Index = 0;
	BTNode* ret = BinaryTreeCreate(a, &Index);
	BinaryTreePrevOrder(ret);
	printf("\n");
	printf("树的节点个数为%d\n", BinaryTreeSize(ret));
	printf("树的叶子节点个数为%d\n", BinaryTreeLeafSize(ret));
	printf("树的第k层节点个数为%d\n", BinaryTreeLevelKSize(ret,3));
	
	return 0;
}



