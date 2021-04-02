#include <bits/stdc++.h>
using namespace std;
#define endl 		    "\n"
#define test 		    int tt;cin>>tt;while(tt--)
#define fl(i,a,b)       for( int i=a;i<b;i++)
#define bfl(i,a,b)      for( int i=b-1;i>=a;i--)
#define ll 			    long long int
#define pb 			    push_back
#define mp 			    make_pair
#define f 			    first
#define s 			    second
#define MOD 		    1000000007
#define PI 			    acos(-1.0)
#define assign(x,val)   memset(x,val,sizeof(x))
#define prec(val, dig)  fixed << setprecision(dig) << val
#define pi 			    pair < int , int >
#define pr(gg)          cout<<gg<<endl
#define mk(arr,n,type)  type *arr=new type[n];

void moh_maya() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
/**********=============########################============***********/

int bustock(int n, int k, int price[])
{
	vector<pair<int, int> >v;

	for (int i = 0; i < n; i++)
	{
		v.pb(mp(price[i], i + 1));
	}

	sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += min(v[i].second, k / v[i].first);
		k -= v[i].first * min(v[i].second, k / v[i].first);
	}
	return ans;
}
void solve()
{

	int price[] = { 10, 7, 19 };
	int n = sizeof(price) / sizeof(price[0]);
	int k = 45;

	cout << bustock(n, k, price) << endl;
}

int32_t main()
{
	moh_maya();
	// test
	solve();
	return 0;
}