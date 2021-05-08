/*
<<<<<<<<<<<---APPRhave to find all the length of cycle in graph
to do this have to traverse bfs in every node till we get backedge on that node

*/
#include<bits/stdc++.h>
using namespace std;

template<typename T>


//O(n^2)
// map<T, list<T> >mp;
vector<T>graph[100005];

void bfs(int src, int size, int &ans)
{
	vector<T>dist(size + 1, INT_MAX);//1 base indexing thats why n+1
	queue<T>q;
	q.push(src);
	dist[src] = 0;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		for (auto nbr : graph[curr])
		{
			if (dist[nbr] == INT_MAX)
			{
				//nbr not visited
				dist[nbr] = dist[curr] + 1;
				q.push(nbr);
			}
			else if (dist[nbr] >= dist[curr]) {
				//backedge is encountered
				int backeadge = dist[nbr] + dist[curr] + 1;
				ans = min(ans, backeadge );
			}
		}
	}
}


int32_t main()
{
	/*
	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(3, 0);
	*/
	int i, j, n, m, ans;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	ans = n + 1;//initially let the length of shortest cycle is n+1 ,which is not quite possible

	for (i = 1; i <= n; i++)
		bfs(i, n, ans);
	//if ans doesnt get changed
	if (ans == n + 1)
		cout << "No cycle";
	else
		cout << "Shprtest cycle is of length" << ans << endl;

	return 0;
}