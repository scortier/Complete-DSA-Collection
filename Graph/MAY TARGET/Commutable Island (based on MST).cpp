int Solution::solve(int A, vector<vector<int> > &B) {
    using PII = pair<int, int>;
    vector<vector<PII>> adj(A + 1);
    for (auto edge : B) {
        int weight = edge[2], u = edge[0], v = edge[1];
        adj[v].push_back({u, weight});
        adj[u].push_back({v, weight});
    }
    priority_queue<PII, vector<PII>, greater<PII>> q;
    vector<bool> visited(A + 1, false);
    q.push({0, 1}); // cost from 1 to itself is 0;
    int cost = 0;
    while (!q.empty()) {
        PII ele = q.top();
        q.pop();
        int u = ele.second;
        int weight = ele.first;
        //check if this node is not already included in MST
        if (!visited[u]) {
            cost += weight;
            visited[u] = true;
            for (auto v : adj[u]) {
                if (!visited[v.first]) {
                    q.push({v.second , v.first });
                }
            }
        }
    }
    return cost;
}




//MST PROBLEM
//can be done by kruskal or prims
int Solution::solve(int N, vector<vector<int> > &cell) {
    int a, b, wt; //cell[0],cell[1],cell[2]
    vector<pair<int, int>>adj[N + 1]; //node,weight
    for (int i = 0; i < cell.size(); i++)
    {
        a = cell[i][0], b = cell[i][1], wt = cell[i][2];
        adj[a].push_back(make_pair(b, wt));
        adj[b].push_back(make_pair(a, wt));
    }
    int parent[N + 1];

    int key[N + 1];

    bool mstSet[N + 1];

    for (int i = 0; i <= N; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    priority_queue< pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 1});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        mstSet[u] = true;

        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
                pq.push({key[v], v});
            }
        }

    }
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (key[i] != INT_MAX) sum += key[i];
    }
    return sum;
}
