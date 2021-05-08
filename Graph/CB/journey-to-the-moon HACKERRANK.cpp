/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;



class Graph {

    map<int, list<int> >mp;

public:
    void addEdge(int x, int y)
    {
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    void dfs_helper(int src, map<int, bool>&visited) {
        //recursive function that will traverse the graph
        // cout << src << " " << "size" << size << " ";
        visited[src] = true;
        //go to all nbr of that node that is not involved one by one
        int size = 1;
        for (auto nbr : mp[src])
        {
            if (!visited[nbr]) {
                dfs_helper(nbr, visited, size);
                size++;
            }
        }
        cout << size << "";
        // return size;
    }

    void dfs()
    {
        map<int, bool>visited;

        for (auto p : mp)
        {
            int node = p.first;
            visited[node] = false;
        }

        //iterate over each vertices and initiate a dfs call
        int cnt = 0;

        for (auto p : mp)
        {
            int node = p.first;
            if (!visited[node])
            {
                cout << "Component " << cnt << " --> ";
                dfs_helper(node, visited);
                cnt++;
                cout << endl;
            }
        }
    }

};


int32_t main()
{
    Graph g;

    int n, p;
    cin >> n >> p;
    while (p--)
    {
        int x, y; cin >> x >> y;
        g.addEdge(x, y);
    }
    g.dfs();

    return 0;
}