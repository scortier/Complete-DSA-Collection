//Author: Aditya Singh Sisodiya (Scortier)
#include<bits/stdc++.h>
using namespace std;

class Graph {
	int x; //no of vertices
	list<int>*adjlist;
public:
	Graph(int v) {
		x = v;
		adjlist = new list<int>[x];
	}
	void addedge(int u, int v, bool bidirn = true)
	{
		adjlist[u].push_back(v);
		if (bidirn)
			adjlist[v].push_back(u);
	}
	void printAdjList() {
		for (int i = 0; i < x; i++)
		{
			cout << i << "-->";
			for (int node : adjlist[i])
				cout << node << ",";
		}
		cout << endl;



		void bfs(int src)
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
			for (int i = 0; i < V; i++) {
				cout << i << " " << "node having the distance == " << dist[i] << endl;
			}
// cout << "THe Shortes path between the node" << dist[dest];
// cout << "Shortest path is this";
// int temp = dest;
// while (temp != -1)
// {
// 	cout << temp << "<--";
// 	temp = parent[temp];
// }

		}
	};


	int main()
	{

		Graph g(6); //as there are 6 vertices iin a graph
		g.addedge(0, 1);
		g.addedge(0, 4);
		g.addedge(1, 2);
		g.addedge(2, 4);
		g.addedge(2, 3);
		g.addedge(3, 4);
		g.addedge(3, 5);

		//g.printadjlist();
		g.bfs(0);
		return 0;
	}