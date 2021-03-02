/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>

class graph{
	map<T,list<pair<T,int>>>adjList;

	void addEdge(T u,T v,int dist,bool bidirectional=1)
	{
		adjList[u].push_back(make_pair(v,dist));
		if(bidirectional)
			adjList[v].push_back(make_pair(u,dist));
	}

	void print_adj(){
		for(auto x:adjList)
		{
			cout<<x.first<<" : ";
			for(auto a:x.second)
				cout<<" ( "<<a.first<<" , "<<a.second<<" ) ";
		cout<<endl;

		}
	}

	void bfs(T u)
	{
		map<T,bool>visited;
		queue<T>q;
		q.push(u);
		while(!q.empty())
		{
			T front_element=q.front();
			q.pop();
			if(!visited[front_element]){
				cout<<front_element<<" -> ";
				visited[front_element]=true;
			}
			for(auto x: adjList[front_element])
			{
				if(!visited[x.first])//if not visited then inset into the queue
					q.push(x.first);
			}
		}
	}

	void dfs_util(T source,map<T,bool>&visited)
	{
		visited[source]=true;
		cout<<source<< " -> ";

		for(auto x: adjList[source])
		{
			
		}
	}
}



int32_t main()
{

	return 0;
}