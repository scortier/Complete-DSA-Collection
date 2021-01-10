// QUARANTINE DAYS..;)
#include <bits/stdc++.h>
using namespace std;
#define endl 		    "\n"
#define test 		    long long int tt;cin>>tt;while(tt--)
#define rep(i,a,b)      for(long long int i=a;i<b;i++)
#define rev(i,a,b)      for(long long int i=b-1;i>=a;i--)
#define reep(i,a,b)     for(long long int i=a;i<=b;i++)
#define ll 			    long long int
#define pb 			    push_back
#define mp 			    make_pair
#define fi 			    first
#define se 			    second
#define MOD 		    1000000007
#define PI 			    acos(-1.0)
#define assign(x,val)   memset(x,val,sizeof(x))
#define prec(val, dig)  fixed << setprecision(dig) << val
#define vec(vct) 	    vector < ll > vct
#define vecpi(vct) 	    vector < pair < ll, ll > > vct
#define pi 			    pair < ll , ll >
#define lower(str) 		transform(str.begin(), str.end(), str.begin(), ::tolower);
#define upper(str) 		transform(str.begin(), str.end(), str.begin(), ::toupper);
#define mk(arr,n,type)  type *arr=new type[n];
const int maxm = 2e6 + 10;

void fast() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
/**********====================########################=================***********/
char a[31][31];
bool vis[31][31];
int dis[31][31];
int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n;

bool isValid(int x, int y)
{
	if (x < 1 || x > n || y < 1 || y > n)
		return false;

	if (vis[x][y] == 1 || a[x][y] == 'T')
		return false;

	return true;
}

void bfs(int srcX, int srcY)
{
	queue< pair<int, int> >q;
	q.push({srcX, srcY});
	vis[srcX][srcY] = 1;
	dis[srcX][srcY] = 0;
	while (!q.empty())
	{
		int currX = q.front().first;
		int currY = q.front().second;
		q.pop();
		//4 means only 4 dirn up,down,right,left
		//8 means 8 dirn including diagonal dirn with above too.
		for (int i = 0; i < 4; i++)	//4/8 depend on the condition
		{
			if (isValid(currX + dx[i], currY + dy[i])) //to check existence and visited or not
			{	int newX = currX + dx[i];
				int newY = currY + dy[i];

				q.push({newX, newY});
				dis[newX][newY] = dis[currX][currY] + 1;
				vis[newX][newY] = 1;
			}
		}
	}

	// cout << "Distance array \n";
	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= m; j++)
	// 	{
	// 		cout << dis[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }


}



int32_t main()
{
	fast();
	int srcX, srcY, endX, endY;
	cin >> n;
	reep(i, 1, n)
	{
		reep(j, 1, n)
		{
			cin >> a[i][j];
			if (a[i][j] == 'S') srcX = i, srcY = j;
			else if (a[i][j] == 'E') endX = i, endY = j;
		}
	}
	bfs(srcX, srcY);
	cout << dis[endX][endY];
	return 0;
}