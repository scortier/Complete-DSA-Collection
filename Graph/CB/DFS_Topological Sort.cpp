/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
Topo Sort applies on Directed Acyclic Graph (DAG).
*/
#include<bits/stdc++.h>
using namespace std;

// template<typename T>

class Graph {

	map<int, list<int> >mp; //can't be unordered map as

public:
	void addEdge(int x, int y)
	{
		mp[x].push_back(y);
		// mp[y].push_back(x);
	}


	void dfs_helper(int curr, map<int, bool>&visited, list<int>&ordering)
	{
		visited[curr] = true;

		//go to all the nodes linked to curr that is not visited
		for (auto nbr : mp[curr])
		{
			//if node linked to curr not visited earlier then
			if (!visited[nbr]) {
				dfs_helper(nbr, visited, ordering);
			}
		}

		//push front in list to insert at the front.
		ordering.push_front(curr);
		// return;

	}

	void dfs()
	{
		map<int, bool>visited;
		list<int>ordering;

		//mark all the node as not visited in the beginning
		for (auto p : mp)
		{
			int node = p.first;
			visited[node] = false;
		}

		//call the helper function
		for (auto p : mp)
		{
			int node = p.first;
			if (!visited[node])
				dfs_helper(node, visited, ordering);
		}

		for (auto node : ordering)
			cout << node << " ";

	}
};

int32_t main()
{
	Graph g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(4, 3);
	g.addEdge(4, 5);
	g.addEdge(4, 6);
	g.addEdge(5, 6);

	g.dfs();

	return 0;
}

/*
OUTPUT:
4
5
6
0
1
2
3
*/