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

void lage_rho() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
/**********=============########################============***********/


void solve()
{
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int threshold; cin >> threshold;
	int l = 1, r = 1000001;
	int ans = 0;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] % mid == 0) {
				sum += (a[i] / mid);
			} else {
				sum += (a[i] / mid) + 1;
			}
		}
		if (sum > threshold) {
			l = mid + 1;
		} else {
			ans = mid;
			r = mid - 1;
		}
	}
	cout << ans;
}


int32_t main()
{
	lage_rho();
	// test
	solve();
	return 0;
}