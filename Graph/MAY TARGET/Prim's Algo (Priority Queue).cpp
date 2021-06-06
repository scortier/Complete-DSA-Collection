//TC :O(N+E) +O(NLOGN)
#include<bits/stdc++.h>
using namespace std;
/*
Agr nodes - 1 se start ho rhe ho toh size of each array will change from N to N+1
pq.push({0,0}) will change to pq.push({0,1}) //value,node
 while cal sum for(1 to =N)

*/
int main()
{
	int N, e;
	cin >> N >> e;
	vector<pair<int, int> > adj[N];

	int a, b, wt;
	for (int i = 0; i < e ; i++) {
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b, wt));
		adj[b].push_back(make_pair(a, wt));
	}

	int parent[N];

	int key[N];

	bool mstSet[N];

	for (int i = 0; i < N; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	priority_queue< pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > pq;

	key[0] = 0;
	parent[0] = -1;
	pq.push({0, 0});// key[index] i.e value at index,index


	while (!pq.empty())
	{
		int par_node = pq.top().second;
		pq.pop();

		mstSet[par_node] = true;

		//looking for all its adjacent neighbors
		for (auto child : adj[par_node])
		{
			int ch_node = child.first;
			int ch_weight = child.second;
			if (mstSet[ch_node] == false and ch_weight < key[ch_node])
			{
				parent[ch_node] = par_node;	//update the parent[]
				key[par_node] = weight;
				pq.push({key[ch_node], ch_node})
			}
		}

	}

	for (int i = 1; i < N; i++)
		cout << parent[i] << " - " << i << " \n";
	return 0;

//to find the total minimum weight of mst
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (key[i] != INT_MAX) sum += key[i];
	}
	return sum;

}

// Run the loop till all the nodes have been visited
// because in the brute code we checked for mstSet[node] == false while computing the minimum
// but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
// hence its better to keep running till all the nodes have been taken.
// try the following case:
// 6 7
// 0 1 5
// 0 2 10
// 0 3 100
// 1 3 50
// 1 4 200
// 3 4 250
// 4 5 50