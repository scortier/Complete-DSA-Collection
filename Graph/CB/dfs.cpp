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

	void dfs(T src)
	{
		map<T, bool>visited;
		//Map all the nodes as not visited in the beginning
		for (auto p : mp)
		{
			T node = p.first;
			visited[node] = false;
		}
		//call the  helper function
		dfs_helper(src, visited);
	}
}

int32_t main()
{
	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(3, 0);

	g.dfs(0);
	return 0;
}