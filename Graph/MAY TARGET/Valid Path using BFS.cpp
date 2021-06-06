/*
APPROACH :
Focus on every single points inside the rectangle. You can’t go to some points which lie inside any of the circle. So basically you know all the points where you can stand at. Can you use this info to figure out a path between origin and destination.

Above hint signify the term of isValid condn
1. Inside the rectangle
2. Pt must be outside the circles area

-Check if (i,j) is a isValid point for all 0<=i<=x, 0<=j<=y. By isValid point we mean that none of the circle should contain it.

Now you know all the isValid point in rectangle. You need to figure out if you can go from (0,0) to
(x,y) through isValid points. This can be done with any graph traversal algorithms like BFS/DFS.


AB KUCH BHI LAGA SAKTE HO BFS/DFS



*/


/*
The idea is to start traversing the rectangle co-ordinates one by one
from each (i,j) i have 8 choices to move , for doing this i will use
queue and visited array , visited help in reducing same call
at each (i,j) i will first check whether the point lies inside any circle or
not by calculating it distance from centre of each circle ,if distance is greater than
r then point lies outside the circle , after my queue is empty if the (x,y)
co-ordinate is marked as visited means it is possible to reach there
*/

// these are the moves which i can take from any position i,j
int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[8] = { -1, 1, 0, 1, -1, 0, -1, 1};

// Used to check whether the i,j column lies inside the rectangle or not
bool isValid(int x, int y, int x_end, int y_end)
{
  if (x < 0 || x > x_end || y < 0 || y > y_end)
  {
    return false;
  }
  return true;
}

// Check whether the point x,y lies inside any circle or not
bool inCircle(int x, int y, int No_of_circles, int radius, vector<int>&X_Cord, vector<int>&Y_Cord)
{
  for (int i = 0; i < No_of_circles; i++)
  {
    //x*x+y*y<=r*r
    if (((x - X_Cord[i]) * (x - X_Cord[i]) + (y - Y_Cord[i]) * (y - Y_Cord[i])) <= (radius * radius))
      return true;
  }
  return false;
}

string Solution::solve(int x_end, int y_end, int No_of_circles, int radius, vector<int> &X_Cord, vector<int> &Y_Cord) {
  // visited array
  bool vis[x_end + 1][y_end + 1];
  memset(vis, false, sizeof(vis));

  // vector<vector<bool>> vis(x_end + 1, vector<bool>(y_end + 1, false));
  // int R = vis.size(), C = vis[0].size();

  queue<pair<int, int>> q;
  q.push({0, 0});
  vis[0][0] = true;

  // first checking wheter the point (0,0) lies in circle or not
  if (inCircle(0, 0, No_of_circles, radius, X_Cord, Y_Cord))
    return "NO";


  while (!q.empty()) {

    // pick first element of queue
    pair<int, int> temp = q.front();
    q.pop();

    // checking all 8 possible moves
    for (int i = 0; i < 8; i++) {
      int x = temp.first + dx[i];
      int y = temp.second + dy[i];
      if (!vis[x][y] && isValid(x, y, x_end, y_end) && !inCircle(x, y, No_of_circles, radius, X_Cord, Y_Cord)) {

        q.push({x, y});
        vis[x][y] = true;
      }
    }
  }
  if (vis[x_end][y_end])
    return "YES";
  else
    return "NO";

}

