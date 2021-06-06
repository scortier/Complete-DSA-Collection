/*
APPROACH :
Focus on every single points inside the rectangle. You can’t go to some points which lie inside any of the circle. So basically you know all the points where you can stand at. Can you use this info to figure out a path between origin and destination.

Above hint signify the term of valid condn
1. Inside the rectangle
2. Pt must be outside the circles area

-Check if (i,j) is a valid point for all 0<=i<=x, 0<=j<=y. By valid point we mean that none of the circle should contain it.

Now you know all the valid point in rectangle. You need to figure out if you can go from (0,0) to
(x,y) through valid points. This can be done with any graph traversal algorithms like BFS/DFS.


AB KUCH BHI LAGA SAKTE HO BFS/DFS



*/


#define ar array
#define mxN 201


int dX[8] = {0, 1, 0, -1, 1, -1, +1, -1};
int dY[8] = {1, 0, -1, 0, 1, -1, -1, +1};

bool valid(int x, int y, int X , int Y ) {
    if ( x >= 0 && y >= 0 && x <= X && y <= Y ) {
        return true;
    }
    return false;
}

bool inCircle(int x, int y, int cx, int cy, int R ) {
    if (  (cx - x) * (cx - x) + (cy - y) * (cy - y) - R * R <= 0  ) {
        return true;
    }
    return false;
}

void dfs(int vis[][mxN], int mp[][mxN], int X, int Y, int x = 0, int y = 0) {
    if ( vis[x][y] || !valid(x, y, X, Y) || mp[x][y] ) {
        return ;
    }
    vis[x][y] = 1;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dX[i] ;
        int ny = y + dY[i] ;
        dfs(vis, mp, X, Y, nx, ny);
    }
}

string Solution::solve(int X, int Y, int N, int R, vector<int>& A, vector<int>& B ) {

    int vis[mxN][mxN];
    int mp[mxN][mxN];

    memset(vis, 0, sizeof(vis));
    memset(mp, 0, sizeof(mp));

    for (int i = 0; i < N; ++i) {
        int cx = A[i];
        int cy = B[i];

        for (int j = cx - R; j <= cx + R; ++j) {
            for (int k = cy - R; k <= cy + R; ++k) {
                if ( valid(j, k, X, Y) && inCircle(j, k, cx, cy, R) ) {
                    mp[j][k] = 1;
                }
            }
        }
    }


    dfs(vis, mp, X, Y);

    if (vis[X][Y]) {
        return "YES";
    } else {
        return "NO";
    }
}