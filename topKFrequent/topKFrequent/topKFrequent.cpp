#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<ostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;


vector<string> topKFrequent(vector<string>& words, int k) {
	vector<string>ret;
	if (words.empty())
		return ret;

	map<string, int> smap;
	for (int i = 0; i<words.size(); ++i)
	{
		smap[words[i]]++;
	}
	multimap<int, string, greater<int>> mmap;
	for (auto& e : smap)
	{
		mmap.insert(make_pair(e.second, e.first));
	}


	for (auto& e : mmap)
	{
		ret.push_back(e.second);
		if (--k == 0)
		{
			break;
		}
	}


	return ret;
}


int main()
{
	vector<string> words = { "i", "love", "leetcode", "i", "love", "coding" };
	vector<string> ret = topKFrequent(words, 2);

	cout << endl;
	return 0;
}