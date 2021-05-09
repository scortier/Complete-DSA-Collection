#include<bits/stdc++.h>
using namespace std;

class Solution {

private:
  bool checkCycle(int node, vector<int> adj[], int vis[], int dfsVis[]) {
    vis[node] = 1;
    dfsVis[node] = 1;

    //node k adj ko dekhenge ab
    for (auto ch : adj[node])
    {
      if (vis[ch] == 0)
      {
        if (checkCycle(ch, adj, vis, dfsVis))
          return true;
      }
      else if (dfsVis[ch])
        return true;
    }

//jese recursion tree m last se lautke aate haina tab dfs unvisited mark do sirf but vis array m mark rahega as visite toh kiya na bas vapas jaa rha so dfsvis m unmark karo
    dfsVis[node] = 0;
    return false;
  }

public:
  bool isCyclic(int N, vector<int> adj[]) {
    int vis[N], dfsVis[N];
    memset(vis, 0, sizeof vis);
    memset(dfsVis, 0, sizeof dfsVis);

//basic template
    for (int i = 0; i < N; i++) {
      if (!vis[i]) {
        // cout << i << endl;
        if (checkCycle(i, adj, vis, dfsVis)) {
          return true;
        }
      }
    }
    return false;
  }
};




int main()
{

  int t;
  cin >> t;
  while (t--)
  {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++)
    {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
    }

    Solution obj;
    cout << obj.isCyclic(V, adj) << "\n";
  }

  return 0;
}