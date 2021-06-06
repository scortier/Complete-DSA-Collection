int parent[1e4];
int rank[1e4];

void makeSet() {
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}
}

//7->6->4->3
int findPar(int node)
{
	if (node == parent[node])
		return node;
	return parent[node] = findPar(parent[node]);
}

void union(int u, int v)
{
	u = findPar(u);
	v = findPar(v);

	if (rank[u] < rank[v])
		parent[u] = v;

	else if (rank[v] < rank[u])
		parent[v] = u;

	else
	{
		parent[v] = u;
		rank[u]++;
	}
}

void main()
{
	makeSet();
	int m;
	cin >> m;
	while (m--)
	{
		int u, v;
		union(u, v);
	}

	if (findPar(2) != findPar(3))
		cout << "Different Components";
	else
	{
		cout << "Same";
	}
}