/*
APPROACH:

*/

#include <bits/stdc++.h>
using namespace std;

//APPROACH -1
//USING FLOYYD WARSHALL
void transitiveClosure(int graph[][V])
{
	int reach[V][V];

	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			reach[i][j] = graph[i][j];
		}
	}

	for (int k = 0; k < V; k++)
	{
		//i as src
		for (int i = 0; i < V; i++)
		{
			//j as dest
			for (int j = 0; j < V; j++)
			{
				//k is invading bw i and j path toh shi hai
				reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
			}
		}
	}

	// Print the shortest distance matrix
	printSolution(reach);
}

/* A utility function to print solution */
void printSolution(int reach[][V])
{
	printf ("Following matrix is transitive");
	printf("closure of the given graph\n");
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			/* because "i==j means same vertex"
			 and we can reach same vertex
			 from same vertex. So, we print 1....
			 and we have not considered this in
			 Floyd Warshall Algo. so we need to
			 make this true by ourself
			 while printing transitive closure.*/
			if (i == j)
				printf("1 ");
			else
				printf ("%d ", reach[i][j]);
		}
		printf("\n");
	}
}
// Driver Code
int main()
{
	/* Let us create the following weighted graph
	        10
	   (0)------->(3)
	    |         /|\
	  5 |          |
	    |          | 1
	   \|/         |
	   (1)------->(2)
	        3           */
	int graph[V][V] = { {1, 1, 0, 1},
		{0, 1, 1, 0},
		{0, 0, 1, 1},
		{0, 0, 0, 1}
	};

	// Print the solution
	transitiveClosure(graph);
	return 0;
}








//APPROACH-2
//USING DFS

class Solution:
{
public:

	// function to add an edge to graph
	void addEdge(int v, int w) { adj[v].push_back(w); }

	vector<vector<bool>>tc(V, vector<bool>(V, false));
	void DFS_Util(int u, int v)
	{

		if (u == v)
		{
			if (adj[v].find(u))
				tc[u][v] = true;
		}
		else
			tc[u][v] = true;





	}

	void transitiveClosure()
	{
		// Call the recursive helper function to print DFS
		// traversal starting from all vertices one by one
		for (int i = 0; i < V; i++)
			DFSUtil(i, i); // Every vertex is reachable from self.

		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
				cout << tc[i][j] << " ";
			cout << endl;
		}
	}





}