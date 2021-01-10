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
#define vec 	 	    vector < ll >
#define vecpi 	   	    vector < pair < ll, ll > >
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
vec adj[maxm];
int vis[maxm];

int dfs(int curr)
{
	vis[curr] = 1;
	int curr_size = 1;
	for (auto child : adj[curr])
	{
		if (!vis[child])
		{
			curr_size += dfs(child);
		}
	}
	subSize[curr] = curr_size;
	return curr_size;
}

int32_t main()
{
	fast();
	int n, m, a, b;
	test
	{
		cin >> n >> m;
		reep(i, 1, n) adj[i].clear(), vis[i] = 0;
		reep(i, 1, m)
		{
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		bfs(1); //calling bfs from src node as 1.

		cout << dis[n] << endl;
	}
	return 0;
}