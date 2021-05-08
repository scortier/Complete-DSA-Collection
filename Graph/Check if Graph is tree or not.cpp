/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
An undirected graph is tree if it has following properties.
1) There is no cycle.
2) The graph is connected.

BFS
A graph is a tree if the following two conditions are satisfied:

There are no cycles present in the graph
The graph is connected
Algorithm for checking cycle in Graph.

Create the graph using the given number of edges and vertices.
Run a BFS from starting from any vertex along with the track of the parent.
Push vertex into queue and mark its parent as -1.
Run a loop while the queue is not empty.
Dequeue vertex from queue and add all its unvisited adjacent to queue and mark it visited.
For vertex ‘v’, if there is an adjacent ‘u’ such that u is already visited and u is not parent of v, then there is a cycle in the graph.
Algorithm for checking whether the graph is connected or not

After BFS, check if all the vertex is not visited or not.
If all the vertices are visited then it is connected.



DFS
A graph is a tree if the following two conditions are satisfied:

There are no cycles present in the graph
The graph is connected
Algorithm for checking cycle in Graph.

Create the graph using the given number of edges and vertices.
Run a DFS from starting from any vertex along with the track of the parent (initially, parent of every vertex is -1)
Recur for all the vertices adjacent to the current vertex.
If an adjacent vertex is not visited, then recur for that adjacent vertex.
If an adjacent vertex is visited and it is not the parent of the current vertex, then there is a cycle.

Algorithm for checking whether the graph is connected or not
1. After DFS, check if all the vertex is not visited or not.
2. If it is visited then it is connected.
*/
#include<bits/stdc++.h>
using namespace std;

// template<typename T>


//for undirected graph

class Graph {
	int V;	//no of vertex
	list<int> *adjlist; 	//array of link list of size V
	// bool isCyclicUtil(int v, bool visit[], int parent);
public:
	Graph(int v) {		//constructor
		V = v;
		adjlist = new list <int>[V];
		bool isTree();
	}
	void addEdge(int u, int v , bool bidirn = true)
	{
		adjlist[u].push_back(v);
		if (bidirn) adjlist[v].push_back(u);
	}

	bool isCyclicUtil(int v, bool visit[], int parent)
	{
		visit[v] = true;

		// Recur for all the vertices adjacent to this vertex
		list<int>::iterator i;
		for (i = adjlist[v].begin(); i != adjlist[v].end(); ++i)
		{
			// If an adjacent is not visited, then recur for
			// that adjacent
			if (!visit[*i])
			{
				if (isCyclicUtil(*i, visit, v))
					return true;
			}

			// If an adjacent is visited and not parent of current
			// vertex, then there is a cycle.
			else if (*i != parent)
				return true;
		}
		return false;
	}

	bool isTree()
	{
		bool *visit = new bool[V];
		for (int i = 0; i < V; i++)
			visit[V] = false;

		// The call to isCyclicUtil serves multiple purposes.
		// It returns true if graph reachable from vertex 0
		// is cyclcic. It also marks all vertices reachable
		// from 0.
		if (isCyclicUtil(0, visit, -1))
			return false;

		// If we find a vertex which is not reachable from 0
		// (not marked by isCyclicUtil(), then we return false
		for (int u = 0; u < V; u++)
			if (!visit[u])
				return false;

		return true;
	}

};

int32_t main()
{
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	g1.isTree() ? cout << "Graph is Tree\n" :
	                   cout << "Graph is not Tree\n";

	Graph g2(5);
	g2.addEdge(1, 0);
	g2.addEdge(0, 2);
	g2.addEdge(2, 1);
	g2.addEdge(0, 3);
	g2.addEdge(3, 4);
	g2.isTree() ? cout << "Graph is Tree\n" :
	                   cout << "Graph is not Tree\n";

	return 0;
}