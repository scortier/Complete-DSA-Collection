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


};

int32_t main()
{
	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(3, 0);


	return 0;
}