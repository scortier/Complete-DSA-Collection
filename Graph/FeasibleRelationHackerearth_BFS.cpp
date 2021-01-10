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

vec (adj[1000001]);	//creating adj list
int vis[1000001]; //to check visited node
int cc[1000001];	//to check connected comp
int curr_cc;

void dfs(int current)
{
	vis[current] = 1;
	cc[current] = curr_cc;

	for (auto child : adj[current])
	{
		if (!vis[child])
			dfs(child);
	}
}

int32_t main()
{
	fast();
	int n, k, a, b;
	string s;
	test
	{
		cin >> n >> k;
		vector<pair<int, int>>edgelist;
		for (int i = 1; i <= n; i++)	//clear adj list and vis array for each test case.
		{
			adj[i].clear();
			vis[i] = 0;
		}
		reep(i, 1, k)
		{
			cin >> a >> s >> b;
			if (s == "=") //create a graph if s:"="
			{
				adj[a].pb(b);
				adj[b].pb(a);
			}
			else
				edgelist.pb(mp(a, b));
		}
		curr_cc = 0;
		for (int i = 1; i <= n; i++)
			if (vis[i] == 0)
			{
				curr_cc++;
				dfs(i);
			}

		bool flag = true;
		for (int i = 0; i < edgelist.size(); i++)
		{
			a = edgelist[i].fi;
			b = edgelist[i].se;

			if (cc[a] == cc[b]) //connected comp of a=b
			{
				flag = false;
				break;
			}


		}
		if (flag == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}