// TC: >  O(N*N)
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, e;
	cin >> n >> e;

	vector<per>adj[n];

	int a, b, wt;
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b, wt));
		adj[b].push_back(make_pair(a, wt));
	}

	int parent[n];
	int key[n];
	bool mstSet[n];

	for (int i = 0; i < n; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;
	parent[0] = -1;

	int ansWeight = 0;

	for (int count = 0; count < n - 1; count++)
	{
		int mini = INT_MAX, par_node;
		//find out minimal key val
		for (int v = 0; v < n; v++)
		{
			//must not be part of mst and shoul minm among all key present
			if (mstSet[v] == false and key[v] < mini)
			{
				mini = key[v]; //value
				par_node = v;	//index
			}
		}

		mstSet[par_node] = true;	//now make the that index as part of mst now

		//looking for all its adjacent neighbors
		for (auto child : adj[par_node])
		{
			int ch_node = child.first;
			int ch_weight = child.second;
			if (mstSet[ch_node] == false and ch_weight < key[ch_node])
			{
				parent[ch_node] = par_node;	//update the parent[]
				key[par_node] = weight;
			}
		}
	}

	for (int i = 1; i < n; i++)
		cout << parent[i] << " - " << i << " \n";
}