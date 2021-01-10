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

bool vis[1001][1001];
int n, m; //rows and columns
int a[1001][1001];

bool isValid(int x, int y)
{
	if (x < 1 || y < 1 || x > n || y > m)
		return false;

	else if (vis[x][y] == true || a[x][y] == '#')	//agr visit kar rakha hai toh dobara nhi karne ka
		return false;

	return true;
}

// int dx[] = { -1, 0, 1, 0};//up,right,down,left
// int dy[] = {0, 1, 0, -1};
void dfs(int x, int y)
{
	vis[x][y] = true;

	if (isValid(x - 1, y))
		dfs(x - 1, y); //up

	if (isValid(x, y + 1))
		dfs(x, y + 1); //right

	if (isValid(x + 1, y))
		dfs(x + 1, y); //down

	if (isValid(x, y - 1))
		dfs(x, y - 1); //left
}



int32_t main()
{
	fast();
	cin >> n >> m;//row,column
	// dfs(1, 1); // from 1,1
	reep(i, 1, n)
	{
		reep(j, 1, m)
		{
			cin >> a[i][j];
		}
	}

	int cnnt ;
	// reep(i, 1, n)
	// {
	// 	reep(j, 1, m)
	// 	{
	// 		if ( vis[i][j] == false && a[i][j] == '.' )
	// 		{

	// 			cnnt++; dfs(i, j);

	// 		}
	// 	}
	// }
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			if (a[i][j] == '.' && vis[i][j] == false)
				dfs(i, j), cnnt++;

	}
	cout << cnnt << endl;
	return 0;
}
