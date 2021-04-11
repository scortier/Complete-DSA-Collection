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

vector<int> a[maxm];
bool visited[maxm];

void dfs(int current)
{
	if (!visited[current])
	{
		visited[current] = true;
		for (int i = 0; i < a[current].size(); i++)
		{
			if (!visited[a[current][i]])
				dfs(a[current][i]);
		}
		//for(auto child:a[current])
		//	dfs(child);

	}
};
//if we are using dfs more than once than need a reset func to set all the visited node to 0.

int32_t main()
{
	fast();
	int n = 5; //no of edges.
	while (n--)
	{
		// p->q only as a directed graph
		int p, q; //nodes connecting those edges.
		cin >> p >> q;
		a[p].pb(q);
	}
	//can you go from node l to node m
	int l, m; cin >> l >> m;
	dfs(l);
	if (visited[m] == 0) cout << "yes" << endl;
	else cout << "no" << endl;
	dfs(0);
	for (int i = 0; i <= 7; i++)
		cout << i << " : " << visited[i] << endl;


	return 0;
}