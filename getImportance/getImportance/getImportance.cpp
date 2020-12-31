﻿#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
给定一个保存员工信息的数据结构，它包含了员工唯一的id，重要度 和 直系下属的id。

比如，员工1是员工2的领导，员工2是员工3的领导。他们相应的重要度为15, 10, 5。那么员工1的数据结构是[1, 15, [2]]，员工2的数据结构是[2, 10, [3]]，员工3的数据结构是[3, 5, []]。注意虽然员工3也是员工1的一个下属，但是由于并不是直系下属，因此没有体现在员工1的数据结构中。

现在输入一个公司的所有员工信息，以及单个员工id，返回这个员工和他所有下属的重要度之和。

示例 1:

输入: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
输出: 11
解释:
员工1自身的重要度是5，他有两个直系下属2和3，而且2和3的重要度均为3。因此员工1的总重要度是 5 + 3 + 3 = 11。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/employee-importance

*/
class Employee {
public:
	int id;
	int importance;
	vector<int> subordinates;
};

void get(vector<Employee*>& employees, unordered_map<int, int>& id_index, int& ret, int id)
{
	int index = id_index[id];
	int size = employees[index]->subordinates.size();
	ret += employees[index]->importance;
	if (size == 0)
	{
		//ret+=employees[index]->importance;
		return;
	}
	//ret+=employees[index]->importance;
	for (int i = 0; i<size; ++i)
	{
		get(employees, id_index, ret, employees[index]->subordinates[i]);
	}

}

	int getImportance(vector<Employee*> employees, int id) {
		if (employees.empty())
			return 0;
		unordered_map<int, int> id_index;
		for (size_t i = 0; i<employees.size(); ++i)
		{
			id_index.insert(make_pair(employees[i]->id, i));
		}
		int ret = 0;
		get(employees, id_index, ret, id);
		return ret;
	}