/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
find the src node which has no dependency on it.(indegree ki baat ho rhi)
nodes with 0 indegree start with them and queu m daldo unhe and process them one by one.

*/
#include<bits/stdc++.h>
using namespace std;

// template<typename T>

class Graph {

	// map<T, list<T> > mp;

	list<int>*l;
	int V;

public:
	//constructor
	Graph(int V)
	{
		this->V = V;
		l = new list<int>[V];
	}

	void addEdge(int x, int y)
	{
		l[x].push_back(y);
	}

	void topological_sort() {

		//indegree
		int *indegree = new int[V];

		//0 indegree
		for (int i = 0; i < V; i++) {
			indegree[i] = 0;
		}

		//update indegree by traversing edges
		//indegree[y]++

		//0->2 so 0=p.first and 2= p.second
		for (int i = 0; i < V; i++)
		{
			// int x = p.first;
			//x neighbours
			// for (auto y : p.second) {
//suppose 2 occur one time in 2 nodes list so its indegree will be 2.
			for (auto y : l[i]) {
				indegree[y]++;
			}

		}


		queue<int>q;
		//1.step find the nodes with 0 indegree
		for (int i = 0; i < V; i++)
		{
			if (indegree[i] == 0)
			{
				q.push(i);
			}
		}

		//simpul bfs
		//start removing ele from the queue
		while (!q.empty())
		{
			int node = q.front();
			cout << node << " ";
			q.pop();

			//iterate over nbr of that node and redue their indegree by 1
			for (auto nbr : l[node]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}
	}

};

int32_t main()
{
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	g.topological_sort();
	return 0;
}

//Output : 4 5 2 0 3 1