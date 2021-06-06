/*
tc : O(n+e)
sc: O(n)+O(n)
*/

void bfs(int src, int N, vector<int>adj[])
{

	vector<int>dist(N, INT_MAX);
	queue<int>q;

	dist[src] = 0;
	q.push(src);

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (auto ch : adj[node])
		{
			if (dist[node] + 1 < dist[ch])
			{
				dist[ch] = dist[node] + 1;
				q.push(ch);
			}
		}
	}

	for (int i = 0; i < N; i++)
		cout << dist[i] << " ";

}

