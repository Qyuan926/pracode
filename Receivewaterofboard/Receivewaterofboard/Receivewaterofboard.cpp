#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
//Ä¾°å½ÓË®
int main()
{

	int T;
	cin >> T;
	for (int i = 0; i<T; ++i)
	{
		int n;
		cin >> n;
		vector<int>arr(n);
		int maxIndex = 0;
		int max = 0;
		for (int j = 0; j<n; ++j)
		{
			int h;
			cin >> h;
			arr[j] = h;
			if (h>max)
			{
				max = h;
				maxIndex = j;
			}
		}
		int ret = 0;
		int startIndex = 0;
		int start = arr[0];
		for (int i = 1; i <= maxIndex; ++i)
		{
			if (arr[i] >= start)
			{

				ret += ((i - startIndex)*start);
				startIndex = i;
				start = arr[i];
			}
		}
		start = arr[arr.size() - 1];
		startIndex = arr.size() - 1;
		for (int i = startIndex - 1; i >= maxIndex; --i)
		{
			if (arr[i] >= start)
			{
				ret += ((startIndex - i)*start);
				startIndex = i;
				start = arr[i];

			}
		}
		cout << ret << endl;
	}

	return 0;
}