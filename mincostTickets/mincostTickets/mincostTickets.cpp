#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行。在接下来的一年里，你要旅行的日子将以一个名为 days 的数组给出。每一项是一个从 1 到 365 的整数。

火车票有三种不同的销售方式：

一张为期一天的通行证售价为 costs[0] 美元；
一张为期七天的通行证售价为 costs[1] 美元；
一张为期三十天的通行证售价为 costs[2] 美元。
通行证允许数天无限制的旅行。 例如，如果我们在第 2 天获得一张为期 7 天的通行证，那么我们可以连着旅行 7 天：第 2 天、第 3 天、第 4 天、第 5 天、第 6 天、第 7 天和第 8 天。

返回你想要完成在给定的列表 days 中列出的每一天的旅行所需要的最低消费。
输入：days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
输出：17
解释：
例如，这里有一种购买通行证的方法，可以让你完成你的旅行计划：
在第 1 天，你花了 costs[2] = $15 买了一张为期 30 天的通行证，它将在第 1, 2, ..., 30 天生效。
在第 31 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 31 天生效。
你总共花了 $17，并完成了你计划的每一天旅行。
*/


//动态规划
/*
如果某一天(day)不出行的话
costarr[day]=costarr[day+1];
如果要出行的话,选出花费最小的方案
costarr[day] = min(costs[0] + costarr[day+1], costs[1] + costarr[day+7],costs[2] + costarr[day+30])

有上述思路，我们需要倒着运算，结果保存在costarr[0]中
*/
class Solution {

public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		//记录每天花费情况的数组
		vector<int> costarr(366,-1);
		//记录一年当中出行的情况
		vector<int> dayarr(366, 0);
		for (auto day : days)
		{
			dayarr[day]++;
		}
		int ret = SloveFun(1, costs, costarr, dayarr);
		return ret;
	}
	int SloveFun(int day, vector<int>& costs, vector<int>& costarr, vector<int>& dayarr)
	{
		if (day>365)
		{
			return 0;
		}
		//加快速度的代码，如果这一天的花费情况已经被统计过了，直接返回，无需重复运算。
		if (costarr[day] != -1)
		{
			return costarr[day];
		}
		//这天不需要出行
		if (dayarr[day] == 0)
		{
			costarr[day] = SloveFun(day + 1, costs, costarr, dayarr);
		}
		else
		{//需要出行
			costarr[day] = min(
				min(costs[0] + SloveFun(day + 1, costs, costarr, dayarr), costs[1] + SloveFun(day + 7, costs, costarr, dayarr)),
				costs[2] + SloveFun(day + 30, costs, costarr, dayarr));
		}
		return costarr[day];
	}
};

class Solution2 {

public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		vector<int> dayarr;
		for (auto day : days)
		{
			dayarr.push_back(day);
		}
		vector<int> costarr(dayarr.size(), INT_MAX);
		int ret = SloveFun(0, costs, costarr, dayarr);
		return ret;
	}
	int SloveFun(int Index, vector<int>& costs, vector<int>& costarr, vector<int>& dayarr)
	{
		if (Index >= dayarr.size())
		{
			return 0;
		}
		if (costarr[Index] != INT_MAX)
		{
			return costarr[Index];
		}
		int costday[] = { 1, 7, 30 };
		int index = Index;
		for (int i = 0; i<3; ++i)
		{   //略过不需要出行的时候
			while (index<dayarr.size() && dayarr[index]<dayarr[Index] + costday[i])
			{
				++index;
			}
			//找到下一次需要出行的位置
			costarr[Index] = min(costarr[Index], SloveFun(index, costs, costarr, dayarr) + costs[i]);
		}
		return costarr[Index];
	}
};