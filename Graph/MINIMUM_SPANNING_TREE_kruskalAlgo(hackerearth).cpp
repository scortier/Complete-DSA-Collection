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

struct edge {
	int a; int b; int w;
};

edge ar[100001];
int par[10001]; //parents

bool comp(edge a, edge b)
{
	if (a.w < b.w)
		return true;
	return false;
}
int find(int a)
{
	if (par[a] == -1)
		return a;
	return par[a] = find(par[a]);
}

void merge(int a , int b) {
	par[a] = b;
}

int32_t main()
{
	fast();
	int n, m, a, b, w;
	cin >> n >> m;

	for (int i = 0; i <= n; i++) par[i] = -1;

	for (int i = 0; i < m; i++)
	{
		cin >> ar[i].a >> ar[i].b >> ar[i].w;
	}
	int sum = 0;
	sort(ar, ar + m, comp);

	for (int i = 0; i < m; i++)
	{
		a = find(ar[i].b);
		b = find(ar[i].a);

		if (a != b)
		{
			sum += ar[i].w;
			merge(a, b);
		}

	}

	cout << sum;
	return 0;
}