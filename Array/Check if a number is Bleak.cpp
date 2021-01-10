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
int countsetbits(int x)
{	int cnt = 0;
	while (x)
	{
		x &= (x - 1);
		cnt++;
	}
	return cnt;
}
bool isBleak(int n)
{
	fl(i, 0, n)
	if (i + countsetbits(i) == n) return false;
	return true;
}

//sec method

// A function to return ceiling of log x
// in base 2. For example, it returns 3
// for 8 and 4 for 9.
int ceilLog2(int x)
{
	int count = 0;
	x--;
	while (x > 0) {
		x = x >> 1;
		count++;
	}
	return count;
}
bool isbleak(int n)
{
	for (int i = n - ceilLog2(n); i < n; i++)
		if (i + countsetbits(i) == n) return false;
	return true;
}

void solve()
{
	int n; cin >> n;
	isBleak(n) ? pr("YEs") : pr("no");
	isbleak(n) ? pr("YEs") : pr("no");
}

int32_t main()
{
	lage_rho();
	solve();
	return 0;
}