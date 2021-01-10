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
//Exactly one connnected component.
//tree doesnt contain a cycle.
vector<int>adj[maxm];
int visited[maxm];

void dfs(int current)
{
	visited[current] = 1;
	for (auto child : adj[current])
	{
		if (!visited[child])
			dfs(child);
	}
}

int32_t main()
{
	fast();
	int n, m, a, b; cin >> n >> m;
	reep(i, 1, m)
	{
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(b);
	}
	int connnected_comp = 0;
	reep(i, 1, n)
	{
		if (!visited[i]) //if ith node has not visited then
			dfs(i), connnected_comp++;
	}
	if (connnected_comp == 1 && m == n - 1)
		cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}