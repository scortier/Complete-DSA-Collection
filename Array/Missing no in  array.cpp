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
//ALL BELOW SOLN ARE TC: O(N)
//SPACE C :O(1)


// works fine for small numbers
int mis1(int a[], int n)
{
	int total = (n + 1) * (n + 2) / 2;
	fl(i, 0, n)
	{
		total -= a[i];
	}
	return total;
}

//handle overflow too.
int getMissingNo(int a[], int n)
{
	int i, total = 1;

	for ( i = 2; i <= (n + 1); i++)
	{
		total += i;
		total -= a[i - 2];
	}
	return total;
}


int mis2(int a[], int n)
{
	int x1 = a[0], x2 = 1;
	for (int i = 1; i < n ; i++)
		x1 = x1 ^ a[i];
	for (int i = 2; i < = n + 1; i++)
		x2 = x2 ^ i;

	return (x1 ^ x2);
}


void solve()
{
	int n; cin >> n;
	int a[n - 1];
	for (int i = 0; i < n - 1; i++) cin >> a[i];
	cout << "works fine for small numbers" << mis1(a, n);


}

int32_t main()
{
	lage_rho();
	// test
	solve();
	return 0;
}