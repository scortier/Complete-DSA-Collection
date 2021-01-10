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


int parent[100001];

int find(int a)	//will return its parent
{
	while (parent[a] > 0)
		a = parent[a];

	return a;
}

void Union(int a , int b)
{
	parent[a] += parent[b];		//adding size of set b to set a
	parent[b] = a;				//making a , parent of new set
}


int32_t main()
{
	fast();
	int n , m , a , b;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		parent[i] = -1;		//initializing

	while (m--)
	{
		cin >> a >> b;
		a = find(a) , b = find(b);

		if (a != b) Union(a , b);
	}

	ll res = 1;

	for (int i = 1; i <= n; i++)
		if (parent[i] < 0)
			res = (res * abs(parent[i])) % 1000000007;	//acc to given mod(10^9+7) condn

	cout << res;
}