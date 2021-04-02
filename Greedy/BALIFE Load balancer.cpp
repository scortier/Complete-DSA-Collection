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


void solve()
{
	int n;
	int a[9000], diff, load = 0, max_load = 0;
	while (1) {
		cin >> n;
		if (n == - 1) break;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			load += a[i];
		}


		if (load % n != 0)
		{	pr(-1);
			continue;
		}

		load = load / n;
		diff = 0;
		fl(i, 0, n)
		{
			diff += (a[i] - load);
			int ans = max(diff, -diff);
			max_load = max(max_load, ans);
		}
		pr(max_load);
	}
}

int32_t main()
{
	moh_maya();
	// test
	solve();
	return 0;
}