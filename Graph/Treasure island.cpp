#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<char>>v;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        vector<char>temp;
        for (int j = 0; j < m; j++)
        {
            char x;
            cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    queue<pair<pair<int, int>, int>>q;
    q.push({{0, 0}, 0});
    bool vis[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            vis[i][j] = false;
    }
    vector<int>dx = { -1, 0, 1, 0};
    vector<int>dy = {0, 1, 0, -1};
    int ans = -1;
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cost = q.front().second;
        q.pop();
        if (vis[x][y])
            continue;
        if (v[x][y] == 'X')
        {
            ans = cost;
            break;
        }
        vis[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < m)
            {
                if (v[x][y] != 'D')
                    q.push({{x + dx[i], y + dy[i]}, cost + 1});
            }
        }
    }
    if (ans == -1)
        cout << "Not Possible to reach destination";
    else
        cout << ans;
}


////////////////////////////////////////

//BFS
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
// BFS
int minStepsBFS(vector<vector<char>>& island) {
    int dirs[4][2] = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m = island.size(), n = island[0].size();

    queue<pair<int, int>> q;
    q.push(std::pair<int, int>(0, 0)); island[0][0] = 'D';

    int steps = 1;
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            auto pos = q.front();
            q.pop();
            for (auto dir : dirs) {
                int nx = pos.first + dir[0];
                int ny = pos.second + dir[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || island[nx][ny] == 'D') continue;
                if (island[nx][ny] == 'X') return steps;
                q.push(pair<int, int>(nx, ny));
                island[nx][ny] = 'D';
            }
        }

        ++steps;
    }

    return -1;
}

// DFS
int res = INT_MAX;

void dfs(vector<vector<char>>& island, const vector<vector<int>>& dirs, int x, int y, int steps) {
    if (x < 0 || x >= island.size() || y < 0 || y >= island[0].size() || island[x][y] == 'D' || steps > res) return;
    if (island[x][y] == 'X') {
        res = std::min(res, steps);
        return;
    }

    island[x][y] = 'D';
    for (auto dir : dirs) {
        int nx = x + dir[0];
        int ny = y + dir[1];
        dfs(island, dirs, nx, ny, steps + 1);
    }
}

int minStepsDFS(vector<vector<char>>& island) {
    vector<vector<int>> dirs = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};
    dfs(island, dirs, 0, 0, 0);
    return res == INT_MAX ? -1 : res;
}

int main() {
    vector<vector<char>> island = {{'O', 'O', 'O', 'O', 'O'},
        {'D', 'D', 'D', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'D'},
        {'O', 'D', 'X', 'D', 'O'}
    };

    vector<vector<char>> islandcopy(island);
    cout << minStepsBFS(island) << endl;
    cout << minStepsDFS(islandcopy) << endl;
}