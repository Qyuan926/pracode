#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<unordered_map>
#include<set>
#include<queue>
using namespace std;
/*我们有一系列公交路线。每一条路线 routes[i] 上都有一辆公交车在上面循环行驶。例如，有一条路线 routes[0] = [1, 5, 7]，表示第一辆 (下标为0) 公交车会一直按照 1->5->7->1->5->7->1->... 的车站路线行驶。

假设我们从 S 车站开始（初始时不在公交车上），要去往 T 站。 期间仅可乘坐公交车，求出最少乘坐的公交车数量。返回 -1 表示不可能到达终点车站。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bus-routes
*/

int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
	if (S == T)
		return 0;
	int carnum = routes.size();
	unordered_map<int, set<int>> stand_car;
	//站台j所经过的车辆号存储为set中
	for (int i = 0; i<carnum; ++i)
	{
		//   for(int j=0;j<routes[i].size();++j)
		//   {
		//       stand_car[routes[i][j]].insert(i);
		//       //stand_car.insert(make_pair(routes[i][j],i))
		//   }
		for (auto& e : routes[i])
		{
			stand_car[e].insert(i);
		}
	}

	//判断每条路线是否被遍历过
	vector<bool> visited(carnum, false);
	//存储经过S站台的车辆
	queue<int> que;
	for (auto& e : stand_car[S])
	{
		que.push(e);
		visited[e] = true;
	}

	int step = 0;
	while (!que.empty())
	{
		++step;
		int size = que.size();
		for (int i = 0; i<size; ++i)
		{
			int car = que.front();
			que.pop();
			for (int j = 0; j<routes[car].size(); ++j)
			{
				//如果我们已经找到了站台，返回
				if (routes[car][j] == T)
					return  step;
				//查看这个站台是否还有路线是我们没有检查过的
				for (auto& e : stand_car[routes[car][j]])
				{
					if (visited[e] == false)
					{
						que.push(e);
						visited[e] = true;
					}
				}
			}
		}
	}
	return -1;

}




int main()
{
	vector<vector<int>> routes = { { 1, 2, 7 }, { 3, 6, 7 } };
	int S = 1;
	int T = 6;
	cout << numBusesToDestination(routes, S, T) << endl;
	return 0;
}