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

int sub(int a[], int sum) {
	int currsum = a[0], start = 0, i;

	for (int i = 1; i <= n; i++) {
		while (currsum > sum and start < i - 1) {
			currsum = currsum - a[start];
			start++;
		}

		if (currsum == sum) {
			cout << start << " " << i - 1;
			return 1;
		}
		if (i < n)
			currsum = currsum + a[i];
	}
	return 0;
}
void solve()
{
	int n, sum; cin >> n >> sum;
	int a[n];
	int x = 0;
	fl(i, 0, n) cin >> a[i];
	fl(i, 0, n)
	{
		x += a[i];
	}

}

int32_t main()
{
	lage_rho();
	test
	solve();
	return 0;
}