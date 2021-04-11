/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
dist cal by level order is shortest dist in unweighted graph
*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph {

	map<T, list<T> > mp;

public:
	void addEdge(int x, int y)
	{
		mp[x].push_back(y);
		mp[y].push_back(x);
	}

	void bfs(T src)
	{
		map<T, int>dist;
		queue<T>q;
		q.push(src);

		//all other nodes will have infinite dist
		for (auto node_pair : mp)	//0->(...) 1->(....) 2->(...)
		{
			T node = node_pair.first; //accessing 0,1 from above
			dist[node] = INT_MAX;
		}
		//but src distance is 0
		dist[src] = 0;
		while (!q.empty())
		{
			T node = q.front();
			q.pop();
			cout << node << " " ;
			for (auto nbr : mp[node])
			{
				if (dist[nbr] == INT_MAX) //if visited a node first time
				{
					q.push(nbr);
					//dist[child]=dist[parent]+1;
					dist[nbr] = dist[node] + 1; //distance of that node will be just prev node ai.e parent +1.
				}
			}
		}
		cout << endl;
		//print the dist to every node
		for (auto node_pair : mp)
		{
			T node = node_pair.first;
			int d = dist[node];
			cout << "Node " << node << " Dist from src " << d << endl;
		}
	}
};


int32_t main()
{
	Graph<int>g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(0, 3);
	g.bfs(0);
	return 0;
}