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

int BigOn(int a[], int n , int x)
{
	int res = 0;
	for (int i = 0; i < n; i++)
		if (x == arr[i])
			res++;
	return res;
}

int Binary(int a[], int l, int r, int x)
{
	if (l > r) return -1;

	int mid = l + (r - l) / 2;

	if (a[mid] == x)
		return mid;

	if (a[mid] > x) return Binary(a, l, mid - 1, x);
	if (a[mid] < x) return Binary(a, mid + 1, r, x);
}

int BigO_logn(int a[], int n, int x)
{
	int ind = Binary(a, 0, n - 1, x);

	if (ind == -1) return 0;

	int cnt = 1;
	int left = ind - 1;
	while (left >= 0 and a[left] == x)
		cnt++, left--;

	while (right < n and a[right] == x)
		cnt++, right++;

	return cnt;

}

int BigO_logn_imp(int a[], int n, int x)
{
	//get the index of first occurrence of x
	int *low = lower_bound(a, a + n, x);
	// If element is not present, return 0
	if (low == (a + n) or low != x)
		return 0;

	int *high = upper_bound(low, a + n, x);

	return high - low;
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