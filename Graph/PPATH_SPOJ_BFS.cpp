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
#define vec 	    vector < ll >
#define vecpi 	    vector < pair < ll, ll > >
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
vec adj[10001];
vec primes;
int dist[10001], vis[10001];

bool isPrime(int n)
{
	for (int i = 0; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;

}

bool isValid(int a , int b)
{
	int cnt = 0;
	while (a > 0)
	{
		if (a % 10 != b % 10) cnt++;
		a /= 10;
		b /= 10;
	}
	if (cnt == 1) return true;
	else return false;
}
void buildGraph()
{
	for (int i = 1000; i <= 9999; i++) //forst 4 digit to lat 4 digit
	{
		if (isPrime(i))
			primes.pb(i);
	}
	for (int i = 0; i < primes.size(); i++)
	{
		for (int j = i + 1; j < primes.size(); j++)
		{
			int a = primes[i];
			int b = primes[j];
			if (isValid(a, b)) //means a n b differ by one then enter the loop
			{
				adj[a].pb(b);
				adj[b].pb(a);
			}
		}
	}
}

void bfs(int src)
{
	queue<int>q;
	q.push(src);
	vis[src] = 1;
	dist[src] = 0;

	while (!q.empty()) //tab tak chalao jab tak q khali na ho jae.
	{
		int curr = q.front();
		q.pop();

		for (auto child : adj[curr]) //curr node ki adj list kholo aur dekho konsa unvisited node hai.
		{
			if (!vis[child])
			{
				q.push(child);
				dist[child] = dist[curr] + 1;
				vis[child] = 1;
			}
		}
	}
}

int32_t main()
{
	fast();
	int a, b;
	buildGraph(); //geanerate a graph of 4 digit no
	test
	{
		cin >> a >> b;
		//intial dist sabki -1 indicate that no node is reachable from a
		// aur vis[i] bhi 0
		for (int i = 1000; i <= 9999; i++) dist[i] = -1, vis[i] = 0;
		bfs(a);

		if (dist[b] == -1)
			cout << "impossible" << endl;
		else
			cout << dist[b] << endl;
	}

	return 0;
}