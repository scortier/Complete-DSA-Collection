// QUARANTINE DAYS..;)
//SIMILAR TO IN OR OUT TIME ALFO ON GRAPH.
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
int vis[maxm];
vector<int> adj[maxm];
int cc_size;

void dfs(int current)
{
	vis[current] = 1;
	cc_size++;
	for (auto child : adj[current])
	{
		if (!vis[child]) dfs(child);
	}
}

int32_t main()
{
	fast();
	int n, m , a, b;

	test
	{
		cin >> n >> m;
		reep(i, 1, n)
		{
			vis[i] = 0; //clear vis for each test case
			adj[i].clear();//cl;ear adjacency list for all test case
		}

		reep(i, 1, m)
		{
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}

		ll res = 1; //no of ways of choosing leaders
		int cnt = 0;

		reep(i, 1, n)
		{
			if (vis[i] == 0)
			{
				cc_size = 0;
				dfs(i), cnt++;
				res = (res * cc_size) % MOD;
			}
		}
		cout << cnt << " " << res << endl;
	}
	return 0;
}