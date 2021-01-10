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
vector<int> adj[maxm];
int vis[maxm];
int color[maxm];
bool dfs(int current , int c)
{
	vis[current] = 1;
	color[current] = c;

	for (auto child : adj[current]) //in adjacence  list of node current
	{
		if (!vis[child]) //child par vi sit nhi kiya hai toh
		{
			//visit nhi kiya toh color karna baaki hai aur parent se opp color karna hai
			// so XOR operator
			bool res = dfs(child, c ^ 1);
			if (res == false)
				return false;
		}
		//agar visited hai toh color bhi kiya hoga so
		//check if parent aur child ka color same hai toh return false.
		else if (color[current] == color[child])
			return false;
	}
	return true;
}

int32_t main()
{
	fast();
	int n, m, a, b, t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cin >> n >> m;
		reep(i, 1, n)
		{
			adj[i].clear();
			vis[i] = 0;
		}
		reep(i, 1, m)
		{
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		bool flag = true;

		reep(i, 1, n)
		{
			if (vis[i] == 0)
			{	bool res = dfs(i, 0);
				if (res == false)
					flag == false;
			}
		}
		cout << "Scenario #" << tt << ":" << endl;

		if (flag == false)
			cout << "Suspicious bugs found!" << endl;
		else
			cout << "No suspicious bugs found!" << endl;

	}
	return 0;
}