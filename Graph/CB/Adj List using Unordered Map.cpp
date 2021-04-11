/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
bidir and uni dirn both having wt
*/
#include<bits/stdc++.h>
using namespace std;

class Graph {

	unordered_map<string, list<pair<string, int> > >mp;

public:
	void addEdge(string x, string y, bool bidir, int wt)
	{
		mp[x].push_back(make_pair(y, wt));
		if (bidir)
			mp[y].push_back(make_pair(x, wt));
	}

	void print() {
		for (auto p : mp)
		{
			string src = p.first;
			list<pair<string, int>>nbrs = p.second;

			for (auto nb : nbrs)
			{
				string dest = nb.first;
				int distance = nb.second;

				cout << dest << " " << distance << ",";
			}
			cout << endl;
		}
	}
};

int32_t main()
{
	Graph g;
	g.addEdge("A", "B", true, 20);
	g.addEdge("B", "D", true, 40);
	g.addEdge("A", "C", true, 10);
	g.addEdge("A", "D", false, 50);
	g.addEdge("C", "D", true, 30);
	g.print();

	return 0;
}