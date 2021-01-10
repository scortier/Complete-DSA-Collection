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
vec(adj[10001]); //adjacency list
vec(res);	//resultant array
ll in[10001];	//indegree

bool kahn(int n)
{
	priority_queue<int, vector<int> , greater<int> >q; //value want to store,vector<value> ,greater<int>
	//upper one will create min heap
	//priority_queue<int>Q;   the top element in Q will be max element as acc to max heap
	reep(i, 1, n)
	{
		if (in[i] == 0)
			q.push(i);
	}
	while (!q.empty())
	{
		// int curr = q.front();
		int curr = q.top();
		res.pb(curr);
		q.pop();
		for (auto node : adj[curr])
		{
			in[node]--;
			if (in[node] == 0)
				q.push(node);
		}
	}

	//to check whether it is a valid topological sorting or not.
	return res.size() == n;
}



int32_t main()
{
	fast();
	int x, y, n, m;
	cin >> n >> m;
	reep(i, 1, m)
	{
		cin >> x >> y;
		adj[x].pb(y);
		in[y]++;
	}
	if (!kahn(n))	//if the lexigographical order fails
		cout << "Sandro fails.";
	else
	{
		for (int node : res)
			cout << node << " ";
	}
	return 0;
}