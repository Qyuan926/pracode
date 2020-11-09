#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
/*������һ����ƽ���ϵĵ���ɵ��б� points����Ҫ�����ҳ� K ������ԭ�� (0, 0) ����ĵ㡣

�����ƽ��������֮��ľ�����ŷ����¾��롣��

����԰��κ�˳�򷵻ش𰸡����˵������˳��֮�⣬��ȷ����Ψһ�ġ�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/k-closest-points-to-origin
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������*/

//���վ���Ĵ�Сֱ���������ǰK��
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

//��������ƽ��������map������������Դ洢�����ƽ���Ͷ�Ӧ�������е�����λ��;����ȡ��ǮK����С��
//ʱ�临�Ӷȡ��ռ临�Ӷȶ�ΪO��n��
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