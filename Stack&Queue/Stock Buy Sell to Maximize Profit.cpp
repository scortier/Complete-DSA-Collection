#include <bits/stdc++.h>
using namespace std;
#define endl 		    "\n"
#define test 		    int tt;cin>>tt;while(tt--)
#define fl(i,a,b)       for( int i=a;i<b;i++)
#define ll 			    long long int
#define pb 			    push_back
#define mp 			    make_pair
#define MOD 		    1000000007
#define PI 			    acos(-1.0)
#define assign(x,val)   memset(x,val,sizeof(x))
#define pr(gg)          cout<<gg<<endl
#define mk(arr,n,type)  type *arr=new type[n];


void lage_rho() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
/**********============########################============***********/

int stockbuysell(int a[], int n)
{
	if (n == 1) return 0;
	int maxm = 0;
	int i;
	while (i < n - 1)
	{
		while (i < n - 1 and (a[i + 1] <= a[i])) i++;

		if (i == n - 1) break;

		int buy = i + 1;

		while ((i < n) and (a[i] >= a[i - 1])) i++;

		int sell = i - 1;
		int x = 0; task
		int x = (a[sell] - a[buy]);		if (x > maxm) maxm = x;
	}
	return maxm;
}

void solve()
{
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << stockbuysell(a, n);

}

int32_t main()
{
	lage_rho();
	solve();
	return 0;
}