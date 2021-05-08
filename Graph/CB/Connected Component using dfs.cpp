/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph {

	map<T, list<T> >mp;

public:
	void addEdge(int x, int y)
	{
		mp[x].push_back(y);
		mp[y].push_back(x);
	}

	void dfs_helper(T src, map<T, bool>&visited) {
		//recursive function that will traverse the graph

		cout << src << " ";
		visited[src] = true;
		//go to all nbr of that node that is not involved one by one

		for (auto nbr : mp[src])
		{
			if (!visited[nbr])
				dfs_helper(nbr, visited);
		}
	}

	void dfs()
	{
		map<T, bool>visited;

		for (auto p : mp)
		{
			T node = p.first;
			visited[node] = false;
		}

		//iterate over each vertices and initiate a dfs call
		int cnt = 0;

		for (auto p : mp)
		{
			T node = p.first;
			if (!visited[node])
			{
				cout << "Component " << cnt << "-->";
				dfs_helper(node, visited);
				cnt++;
				cout << endl;
			}
		}
	}

};

int32_t main()
{
	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(0, 3);
	g.addEdge(0, 4);
	g.addEdge(5, 6);
	g.addEdge(6, 7);
	g.addEdge(8, 8);

	g.dfs();

	return 0;
}