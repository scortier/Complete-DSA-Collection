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
vector<int> adj[1000001];
int level[1000001];//level i will tell you how many elements are there at dist i from root node.
int vis[1000001];
int dist[1000001];

void bfs(int src)
{
	queue<int>q;;
	q.push(src);
	vis[src] = 1;
	dist[src] = 0;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (auto child : adj[curr])
		{
			if (!vis[child])
			{
				q.push(child);
				vis[child] = 1;
				dist[child] = dist[curr] + 1;
				level[dist[child]]++;
				//at dist[child] distance there is a node so level increases.
			}
		}

	}
}




int32_t main()
{
	fast();
	int n, a, b, e, m, src, d;
	cin >> n >> e;
	reep(i, 1, e)
	{
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);

	}
	cin >> m;
	while (m--) {
		cin >> src >> d;
		reep(i, 0, n) ///0-based index system is goven

		{
			// adj[i].clear();
			vis[i] = 0;
			level[i] = 0;
		}
		bfs(src);

		cout << level[d] << endl; //how many elements are there at d distance.

	}
	return 0;
}