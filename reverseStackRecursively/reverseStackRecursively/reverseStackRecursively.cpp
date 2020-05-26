#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
/*
һ��ջ����ѹ��1,2,3,4,5��ô��ջ����ջ�׷ֱ�Ϊ5,4,3,2,1�������ջת�ú󣬴�ջ����ջ��Ϊ1,2,3,4,5��Ҳ����ʵ����ջ��Ԫ�ص�����
�����һ���㷨ʵ������ջ�Ĳ���������ֻ���õݹ麯����ʵ�֣�����������������ݽṹ��

����һ��ջStack�Լ�ջ�Ĵ�Сtop���뷵��������ջ��*/
class ReverseStack {
public:
	//��תջ��Ԫ�أ�ע�ⷵ��ֵҪ����
	vector<int>& reverseStackRecursively(vector<int>& stack, int top) {
		//ջ��û��Ԫ��ֱ�ӷ��ؿ�ջ
		if (top == 0)
			return stack;
		int ret = getlast(stack);

		reverseStackRecursively(stack, top - 1);
		//����õ�ջ��Ԫ����ջ
		stack.push_back(ret);
		//����ջ
		return stack;
	}
	//�������ã���ȡջ�ײ���Ԫ��
	int getlast(vector<int>& stack)
	{
		//ȡ��ջ����Ԫ��,����ջ��ɾ����
		int ret = stack.back();
		stack.pop_back();
		//�����ʱջΪ�գ�˵��retΪջ��Ԫ��ֱ�ӷ���
		if (stack.empty())
		{
			return ret;
		}
		else
		{   //ջ��Ϊ�գ�ջ��Ԫ��Ϊ�������ݹ�ȥ��
			int last = getlast(stack);
			//����ʱ��ret���·���ջ��
			stack.push_back(ret);
			//����ջ��Ԫ��
			return last;
		}
	}
};

int main()
{
	vector<int> stack = { 1, 2, 3, 4 };
	ReverseStack  s;
	vector<int> ret=s.reverseStackRecursively(stack, 4);
	for (auto e : ret)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}