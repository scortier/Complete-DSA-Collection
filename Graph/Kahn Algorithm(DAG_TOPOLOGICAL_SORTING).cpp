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
vec(adj[101]); //adjacency list
vec(res);	//resultant array
ll in[100];	//indegree

void kahn(int n)
{
	queue<int>q;
	for (int i = 1; i <= n; i++)
	{
		if (in[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int curr = q.front();
		res.pb(curr);	//adding the  node in final topsort array
		q.pop();
		for (int node : adj[curr])
		{
			in[node]--;
			if (in[node] == 0)
				q.push(node);
		}
	}
	cout << "TOPSORT" << endl;
	for (int node : res)
		cout << node << " ";
}


int32_t main()
{
	fast();
	int n, m; //n=node,m=edges
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;	//x->y directed edge
		adj[x].pb(y);
		in[y]++;
	}
	kahn(n);
	return 0;
}

// INPUT:
// 9 10
// 1 2
// 3 4
// 1 8
// 2 9
// 2 5
// 4 5
// 4 8
// 5 9
// 5 7
// 6 7