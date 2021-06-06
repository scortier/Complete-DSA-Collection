#include<bits/stdc++.h>
using namespace std;

class Solution {

private:
  bool checkCycle(int node, vector<int>& adj[], int vis[], int dfsVis[]) {
    //visit karoge node p toh dono array m mark matha tek ke jana
    vis[node] = 1;
    dfsVis[node] = 1;

    //node k adj ko dekhenge ab
    for (auto ch : adj[node])
    {
      if (vis[ch] == 0)//(!vis[ch])
      {
        // this cycle will go deeper n deeper and some node insied if return true tab toh baat ban gyi na
        if (checkCycle(ch, adj, vis, dfsVis))
          return true;
      }
      else if (dfsVis[ch])
      {
        return true;
      }
    }

    //jese recursion tree m last se lautke aate haina tab dfs unvisited mark do
    //sirf but vis array m mark rahega as visite toh kiya na bas vapas jaa rha
    //so dfsvis m unmark karo
    dfsVis[node] = 0;
    return false;
  }

public:
  bool isCyclic(int V, vector<int> adj[])
  {
    // int vis[V], dfsVis[V];
    // memset(vis, 0, sizeof vis);
    // memset(dfsVis, 0, sizeof dfsVis);

    vector<int>vis(V + 1, 0);
    vector<int>dfsVis(V + 1, 0);

    //basic mulitple comp dfs template
    for (int i = 1; i <= V; i++)
    {
      if (!vis[i])
      {
        // cout << i << endl;
        // if(dfs()){}
        if (checkCycle(i, adj, vis, dfsVis))
        {
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
      adj[u].push_back(v);//as directed graph
    }

    Solution obj;
    cout << obj.isCyclic(V, adj) << "\n";
  }

  return 0;
}





///////////
// Possibility of finishing all courses given pre-requisites
bool cyclic(int node, vector<int>adj[], vector<int>&vis)
{
  if (vis[node] == 1)
    return true;

  if (vis[node] == 0)
  {
    vis[node] = 1;
    for (auto ch : adj[node])
    {
      if (cyclic(ch, adj, vis))
        return true;
    }
  }
  vis[node] = 2;
  return false;
}

int Solution::solve(int n, vector<int>&B, vector<int>&C) {
  vector<int>adj[n + 1];
  for (int i = 0; i < B.size(); i++)
    adj[B[i]].push_back(C[i]);

  vector<int>vis(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    if (cyclic(i, adj, vis))
      return false;
  }
  return true;



}