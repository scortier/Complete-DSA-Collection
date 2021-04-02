/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int>a, pair<int, int>b)
{
	return a.second < b.second;
}

int32_t main()
{
	int n, t, s, e;
	cin >> t;

	vector<pair<int, int>>v;

	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> s >> e;
			v.push_back(make_pair(s, e));
		}
		///activity selection algo
		sort(v.begin(), v.end(), compare);

		//starting picking activities
		int res = 1;
		int fin = v[0].second;

		for (int i = 1; i < n; i++)
		{
			if (v[i].first >= fin)
			{
				fin = v[i].second;
				res++;
			}
		}
		cout << res << endl;
		v.clear();
	}
	return 0;
}