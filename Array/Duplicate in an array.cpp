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

//TC:O(N) SC:O(1)
//IT IS WRONG IF A NO CAME 3 TIMES IT WILL PRINT TWICW IT.
void dup(int a[], int n)
{
	fl(i, 0, n)
	if (a[abs(a[i])] >= 0)
		a[abs(a[i])] = -a[abs(a[i])];
	cout << a[abs(a[i])] << " ";
}

//TC:O(N) SC:O(1)
void deup(int a[], int n)
{
	fl(i, 0, n)
	{
		int idx = a[i] % n;
		a[idx] += n;
	}

	//check which value exist greater than 1.
	fl(i, 0, n)
	{
		if (a[i] / n > 1) cout << i << " " << endl;
	}
}



void solve()
{
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];

}

int32_t main()
{
	lage_rho();
	test
	solve();
	return 0;
}