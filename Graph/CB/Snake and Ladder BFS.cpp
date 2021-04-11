/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

//Unweighted and Directed Graph.
//Unweighted becoz  to reach from 1 to 2/3/4/5/6 we need a single throw of die.
//SO BFS can be appy here O(n) and with DFS(due to recursion)-->O(2^n).
*/
#include <bits/stdc++.h>
using namespace std;


class Graph {
	int V;	//no of vertex
	list<int> *adjlist; 	//array of link list of size V
public:
	Graph(int v) {		//constructor
		V = v;
		adjlist = new list <int>[V]; //link list..
	}
	void addedge(int u, int v , bool bidirn = true)
	{
		adjlist[u].pb(v);
		if (bidirn) adjlist[v].pb(u);
	}
	void printadjlist() {
		for (int i = 0; i < V; i++)
		{
			cout << i << "-->";
			for (int node : adjlist[i]) {
				cout << node << ",";
			}
			cout << endl;
		}
	}



	void bfs(int src , int dest)
	{
		queue<int> q;
		bool*visit = new bool[V + 1] {0}; //intitially no visited node
		int *dist = new int[V + 1] {0}; //intitially all distances are zero
		int *parents = new int[V + 1];

		for (int i = 0.; i < V; i++) { parents[i] = -1;}
		//src ka parents koi nhi hai

		q.push(src); //pushing the starting node in queue.(obviously from the back)
		visit[src] = true; //its visit value assign to true.
		while (!q.empty()) //Tab tak chalao jab tak queue empty nhi ho jaata.
		{
			int node = q.front(); //sabse aage wale element ko node naam diya
			cout << node << " ";
			q.pop();  //sabse front wale ko pop kiya.

			for (int neighbour : adjlist[node])
			{
				if (!visit[neighbour]) {	//node k adj nodes par agr vidit nhi hue ho toh.
					q.push(neighbour); //use neighbour ko queue m push karo
					visit[neighbour] = true;
					dist[neighbour] = dist[node] + 1; //neighbour k parent node se +1 dist hogi starting se.
					parents[neighbour] = node;
				}
			}
		}
		cout << endl;


		//distance of every node from the src.
		//	for (int i = 0; i < V; i++)
		//		cout << i << " " << "node having the distance == " << dist[i] << endl;

		cout << "THe Shortest path is" << dist[dest] << endl;
		cout << "Shortest path is this";
		int temp = dest;
		while (temp != -1)
		{
			cout << temp << "<--";
			temp = parents[temp]; //as har tym ek step piche jaa rhe hai.
		}

	}
};


int main()
{
	int board[50] = {0};
	///positive for ladder and negative for snakes.
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = -10;
	board[32] = -2;
	board[34] = -22;
	Graph g(50);

	//Insert edges
	for (int u = 0; u < 36; u++) //36 is the final destn.
	{
		//Throw a dice from 1 to 6
		for (int dice = 1; dice <= 6; dice++) {
			//v=intial posn + dice no + board with that no.
			int v = u + dice + board[u + dice];
			g.addedge(u, v, false);
		}
	}
	//shortest path
	g.bfs(0, 36);
	return 0;
}