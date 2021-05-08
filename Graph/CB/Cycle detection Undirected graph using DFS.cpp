/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;

// template<typename T>

class Graph {

	map<int, list<int> >mp;

public:
	void addEdge(int x, int y, bool directed = true)
	{
		mp[x].push_back(y);
		if (!directed)
			mp[y].push_back(x);
	}

	bool cycle_helper(int node, bool * visited, int parent)
	{
		visited[node] = true;

		for (auto nbr : mp[node])
		{
			//two cases
			if (!visited[nbr])
			{	//go and recursively visit the nbr
				bool cycle_mila = cycle_helper(nbr, visited, node);
				if (cycle_mila)
					return true;

			}
			//nbr is visited and nbr!=parent
			else if (nbr != parent) {
				return true;
			}
		}
		return false;
	}

	bool contains_cycle()
	{
		bool *visited = new bool[5];
		// vector<bool>visited[5];
		for (int i = 0; i < 5; i++)
		{
			visited[i] = false;
		}

		//if there are multiple components then make dfs helper call
		return cycle_helper(0, visited, -1); //parent of 0 is -1
	}

};

int32_t main()
{
	Graph g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 0);
	// g.addEdge(3, 0);

	if (g.contains_cycle())
		cout << "Yes undirected graph contains cycle.";
	else
		cout << "Not doesn't contain cycle.";
	return 0;
}