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

int count(int a[], int n)
{
	int minm = INT_MAX;
	fl(i, 0, n)
	{
		minm = min(minm, a[i]);
	}
	return minm;
}

int cntUsingBS(int a[], int n)
{
	int l = 0; int h = n - 1; int mid = l + (h - l) / 2;
	if (l > h) return 0;

	if (l == h)  return l;

	if (low < mid and a[mid] < a[mid - 1])
		return mid;

	if (high > mid and a[mid] > a[mid + 1])
		return mid;

	// Decide whether we need to go to left half or
	// right half
	if (arr[h] > arr[mid])
		return countRotations(arr, l, mid - 1);

	return countRotations(arr, mid + 1, h);

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
	solve();
	return 0;
}