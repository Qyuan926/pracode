#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	
	
};

//���ϵ��´�ӡ����������ÿ���ڵ㣬ͬһ��Ľڵ㰴�մ����ҵ�˳���ӡ
//���ö����Ƚ��ȳ������ԣ����ν��ӣ����ø��ڵ���ӣ�ȡ����ͷԪ�أ����������������η�����У���ֱ������Ϊ��ʱ��������
	vector<int> levelOrder1(TreeNode* root) {
		vector<int> ret;
		if (root == nullptr)
		{
			return ret;
		}
		queue<TreeNode*> que_;
		que_.push(root);
		while (!que_.empty())
		{
			TreeNode* Node = que_.front();
			if (Node->left != nullptr)
			{
				que_.push(Node->left);
			}
			if (Node->right != nullptr)
			{
				que_.push(Node->right);
			}
			que_.pop();
			ret.push_back(Node->val);
		}
		return ret;
	}
	//���ϵ��°����ӡ��������ͬһ��Ľڵ㰴�����ҵ�˳���ӡ��ÿһ���ӡ��һ�С�
	//˼�룺�ڲ�������Ļ��������һ���ڵ��־��һ������Ľ���
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector< vector<int>> ret;
		if (root == nullptr)
		{
			return ret;
		}
		vector <int> tmp;
		queue<TreeNode*> que_;
		TreeNode* end = root;
		que_.push(root);
		while (!que_.empty())
		{
			TreeNode* Node = que_.front();
			que_.pop();
			tmp.push_back(Node->val);
			if (Node->left != nullptr)
			{
				que_.push(Node->left);
			}
			if (Node->right != nullptr)
			{
				que_.push(Node->right);
			}
			if (Node == end)
			{
				ret.push_back(tmp);
				end = que_.back();
				tmp.clear();
			}

		}
		return ret;
	}

//	��ʵ��һ����������֮����˳���ӡ������������һ�а��մ����ҵ�˳���ӡ���ڶ��㰴�մ��ҵ����˳���ӡ���������ٰ��մ����ҵ�˳���ӡ���������Դ�����
//�ڲ�������Ļ����ϼ�һ��    �� ��־��һ����������Ľڵ㣩     ��  ��һ��ż���㽻��˳�����ʱ���飩
	vector<vector<int>> levelOrder3(TreeNode* root) {
		vector<  vector<int> > ret;
		if (root == nullptr)
		{
			return ret;
		}
		vector<int> tmp;
		vector<int> convert;
		queue<TreeNode*> que_;
		que_.push(root);
		TreeNode* end = root;
		size_t floor = 1;
		while (!que_.empty())
		{
			TreeNode* Node = que_.front();
			que_.pop();
			tmp.push_back(Node->val);
			if (Node->left != nullptr)
			{
				que_.push(Node->left);
			}
			if (Node->right != nullptr)
			{
				que_.push(Node->right);
			}
			if (Node == end)
			{
				if (floor % 2 == 0)
				{//ż���㣬����
					for (std::vector<int>::reverse_iterator i = tmp.rbegin(); i != tmp.rend(); ++i)
					{
						convert.push_back(*i);
					}
					ret.push_back(convert);
					end = que_.back();
					tmp.clear();
					convert.clear();

				}
				else//�����㣬����
				{
					ret.push_back(tmp);
					end = que_.back();
					tmp.clear();
				}
				floor++;
			}

		}
		return ret;
	}
