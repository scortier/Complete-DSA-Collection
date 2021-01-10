// QUARANTINE DAYS..;)
#include <bits/stdc++.h>
using namespace std;
#define endl 		    "\n"
#define test 		    int tt;cin>>tt;while(tt--)
#define fl(i,a,b)       for( int i=a;i<b;i++)
#define bfl(b,a,i)      for( int i=b;i>=a;i--)
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
//Approach
// 1. sort the array
// 2. two pointer method


int triplet(int a[], int n)
{

	int cnt = 0;
	bfl(n - 1, 0, i)
	{
		int j = 0, k = i - 1;
		while (j < k) {
			if (a[i] == a[j] + a[k])
			{cnt++; j++; k--;}
			else if (a[i] > a[j] + a[k])
			{
				j++;
			}
			else k--;

		}

	}
	return cnt;
}

void solve()
{
	int n; cin >> n;
	int a[n];

	fl(i, 0, n) cin >> a[i];
	sort(a, a + n);
	int ans = triplet(a, n);
	if (ans) pr(ans);
	else pr("-1");


}

int32_t main()
{
	lage_rho();
	// test
	solve();
	return 0;
}