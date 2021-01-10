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

bool checkkaro(int a[], int b[] , int n, int m)
{
	if (n != m) return false;

	sort(a, a + n);
	sort(b, b + m);

	for (int i = 0; i < n; i++)
	{
		if (a[i] != b[i]) return false;
	}

	return true;

}

bool check(int a[], int b[], int n, int m)
{
	unordered_map<int , int>ump;

	if (n != m) return false;
	fl(i, 0, n) ump[a[i]]++;

	fl(i, 0, n)
	{
		if (ump.find(b[i]) == ump.end())
			return false;

// If an element of arr2[] appears more
		// times than it appears in arr1[]
		if (ump[b[i]] == 0) return false;

		ump[b[i]]--;
	}
	return true;
}
void solve()
{


}

int32_t main()
{
	lage_rho();
	solve();
	return 0;
}