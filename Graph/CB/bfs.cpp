/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

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
		map<T, int>visited;
		queue<T>q;
		q.push(src);
		visited[src] = true;
		while (!q.empty())
		{
			T node = q.front();
			q.pop();
			cout << node << " ";
			for (auto nbr : mp[node])
			{
				if (!visited[nbr])
				{
					q.push(nbr);

					visited[nbr] = true;
				}
			}
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
	g.bfs(0);
	return 0;
}