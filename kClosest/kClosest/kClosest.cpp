#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
/*我们有一个由平面上的点组成的列表 points。需要从中找出 K 个距离原点 (0, 0) 最近的点。

（这里，平面上两点之间的距离是欧几里德距离。）

你可以按任何顺序返回答案。除了点坐标的顺序之外，答案确保是唯一的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/k-closest-points-to-origin
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

//按照距离的大小直接排序，输出前K个
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
	vector<vector<int>> ret;
	if (points.empty())
		return ret;
	sort(points.begin(), points.end(), [](vector<int> v1, vector<int> v2)->bool{
		return v1[0] * v1[0] + v1[1] * v1[1]<v2[0] * v2[0] + v2[1] * v2[1];
	});
	int count = 0;
	for (auto& e : points)
	{
		if (count<K)
		{
			ret.push_back(e);
			count++;
		}
		else
			break;
	}
	return ret;

};

//计算距离的平方，根据map容器有序的特性存储距离的平方和对应在数组中的坐标位置;进而取出钱K个最小的
//时间复杂度、空间复杂度都为O（n）
vector<vector<int>> kClosest1(vector<vector<int>>& points, int K) {
	vector<vector<int>>  ret;
	if (points.empty())
		return ret;

	multimap<long long, int> mmap;
	long long minnum = LLONG_MAX;
	for (int i = 0; i<points.size(); ++i)
	{
		long long num = points[i][0] * points[i][0] + points[i][1] * points[i][1];
		mmap.insert(make_pair(num, i));
	}

	int count = 0;
	for (auto& e : mmap)
	{
		if (count++<K)
		{
			ret.push_back(points[e.second]);
		}

	}
	return ret;

}



vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
	vector<vector<int>> ret;
	if (points.empty())
		return ret;
	priority_queue<pair<int, int>> que;
	for (int i = 0; i<K; ++i)
	{
		int num = points[i][0] * points[i][0] + points[i][1] * points[i][1];
		que.push(make_pair(num, i));
	}
	for (int i = K; i<points.size(); ++i)
	{
		int num = points[i][0] * points[i][0] + points[i][1] * points[i][1];
		if (num <= que.top().first)
		{
			que.pop();
			que.push(make_pair(num, i));
		}
		
	}
	while (!que.empty())
	{
		ret.push_back(points[que.top().second]);
		que.pop();
	}


	return ret;
}