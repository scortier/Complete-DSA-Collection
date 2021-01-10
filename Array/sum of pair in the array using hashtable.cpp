// QUARANTINE DAYS..;)
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
#define vi   		    vector < int >
#define pi 			    pair < int , int >
#define pr(gg)          cout<<gg<<endl
#define mk(arr,n,type)  type *arr=new type[n];
const int maxm = 2e6 + 10;

void lage_rho() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
/**********====================########################=================***********/

void sum(int a[], int n, int x)
{
	int cnt[n] = {0};
	int flag = 0;
	fl(i, 0, n)
	{
		cnt[a[i]]++;
	}
	for (int i = 0; i < n; i++)
	{
		int ct = (x - a[i]);
		cnt[a[i]]--;
		if (cnt[ct]) flag = 1;
	}
	if (flag) pr("yes");
	else pr("no");



}
void solve()
{
	int n, x; cin >> n >> x;
	int a[n];
	fl(i, 0, n) cin >> a[i];
	sum(a, n, x);
}

int32_t main()
{
	lage_rho();
	// test
	solve();
	return 0;
}