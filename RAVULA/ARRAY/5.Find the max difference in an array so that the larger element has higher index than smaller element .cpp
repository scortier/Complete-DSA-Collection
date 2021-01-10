// QUARANTINE DAYS..;)
#include <bits/stdc++.h>
using namespace std;
#define endl 		    "\n"
#define test 		    long long int tt;cin>>tt;while(tt--)
#define rep(i,a,b)      for(long long int i=a;i<b;i++)
#define rev(i,a,b)      for(long long int i=b-1;i>=a;i--)
#define reep(i,a,b)     for(long long int i=a;i<=b;i++)
#define ll 			    long long int
#define pb 			    push_back
#define mp 			    make_pair
#define f 			    first
#define s 			    second
#define MOD 		    1000000007

void fast() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
}
/**********====================########################=================***********/



void maxDiff(int *a, int size)
{
	int mn = a[0];
	int mx = a[1] - a[0];
	int curr_diff = a[1] - a[0];
	int index;
	for (index = 1; index < size; index++)
	{
		if (a[index] < mn)
			mn = a[index];
		else
		{
			curr_diff = a[index] - mn;
			if (curr_diff > mx)
				mx = curr_diff;
		}
	}
	return mx;
}
int32_t main()
{
	fast();
	int a, b;
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	rep(i, 0, n)
	{	a = i, b = i + 1;
		int mn = MOD, mx = 0;
		mn = min(mn, arr[a]);
		mx = max(mx, arr[b]);
		if (arr[b] < arr[a]) b++;



	}
	return 0;
}