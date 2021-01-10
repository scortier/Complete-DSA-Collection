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
#define f 			    first
#define s 			    second
#define MOD 		    1000000007
#define PI 			    acos(-1.0)
#define assign(x,val)   memset(x,val,sizeof(x))
#define prec(val, dig)  fixed << setprecision(dig) << val
#define vec 		    vector < ll >
#define vecpi	 	    vector < pair < ll, ll > >
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
//priority queue
vector<pair<int , int> >adj[1001];

int32_t main()
{
	fast();
	int n, m, a, b, w;
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b >> w;
		//it is undirected graph.
		adj[a].pb({b, w});
		adj[b].pb({a, w});
	}
	// priority queue for min heap top of queue contain least value.
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int , int> > >pq;


	vector<int> dist(n + 1, MOD);
	pq. push({0, 1}); //label of src node
	dist[1] = 0; // dist of src node is 0.

	while (!pq.empty())
	{
		int curr = pq.top().second; //contain node
		int curr_d = pq.top().first; // contain dist
		pq.pop(); //remove label from pr queue

		for (pair<int , int >edge : adj[curr]) // traversing the adj list of curr node.
		{
			if (curr_d + edge.second < dist[edge.first])
			{
				dist[edge.first] = curr_d + edge.second;
				pq.push({dist[edge.first], edge.first});
			}
		}

	}

	for (int i = 1; i <= n; i++)
		cout << dist[i] << " ";
	return 0;
}


// 6 9
// 1 2 4
// 1 6 2
// 2 3 5
// 2 6 1
// 6 3 8
// 6 5 10
// 3 4 6
// 3 5 3
// 5 4 5