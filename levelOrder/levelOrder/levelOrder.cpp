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

//从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印
//采用队列先进先出的特性，依次进队（先让根节点进队，取出队头元素，将其左右子树依次放入队列），直至队列为空时，结束。
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
	//从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
	//思想：在层序遍历的基础上面加一个节点标志着一层遍历的结束
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

//	请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推
//在层序遍历的基础上加一个    （ 标志着一层遍历结束的节点）     和  （一个偶数层交换顺序的临时数组）
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
				{//偶数层，倒着
					for (std::vector<int>::reverse_iterator i = tmp.rbegin(); i != tmp.rend(); ++i)
					{
						convert.push_back(*i);
					}
					ret.push_back(convert);
					end = que_.back();
					tmp.clear();
					convert.clear();

				}
				else//奇数层，正着
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
