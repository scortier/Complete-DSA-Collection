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
vector<int> adj[10001];
int vis[10001];

int maxD, maxNode;
void dfs(int curr, int d)
{
	vis[curr] = 1;
	if (d > maxD) maxD = d, maxNode = curr; //to store max dist and that corres node

	for (auto child : adj[curr])
	{
		if (!vis[child])
			dfs(child,  d + 1);//as child will be on dist d+1.
	}
}

int32_t main()
{
	fast();
	int n; cin >> n;
	reep(i, 1, n - 1)
	{
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	maxD = -1;
	dfs(1, 0); //intially root is 1 and dist=0
	//before calling dfs again vis[i]=0;
	reep(i, 1, n) vis[i] = 0;
	dfs(maxNode, 0);
	cout << maxD << endl;
	return 0;
}