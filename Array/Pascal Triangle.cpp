// QUARANTINE DAYS..;)
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
int binomialCoeff(int n, int k)
{
	int res = 1;
	if (k > n - k)
		k = n - k;
	for (int i = 0; i < k; ++i)
	{
		res *= (n - i);
		res /= (i + 1);
	}

	return res;
}
void printPascal(int n)
{
	// Iterate through every line and
	// print entries in it
	for (int line = 0; line < n; line++)
	{
		// Every line has number of
		// integers equal to line
		// number
		for (int i = 0; i <= line; i++)
			printf("%d ",
			       binomialCoeff(line, i));
		printf("\n");
	}
}


void solve()
{
	int n; cin >> n;
	printPascal(n);

}

int32_t main()
{
	lage_rho();
	solve();
	return 0;
}