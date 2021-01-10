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

int countTriplets(int arr[], int n, int sum)
{
	// Sort input array
	sort(arr, arr + n);

	// Initialize result
	int ans = 0;

	// Every iteration of loop counts triplet with
	// first element as arr[i].
	for (int i = 0; i < n - 2; i++)
	{
		// Initialize other two elements as corner elements
		// of subarray arr[j+1..k]
		int j = i + 1, k = n - 1;

		// Use Meet in the Middle concept
		while (j < k)
		{
			// If sum of current triplet is more or equal,
			// move right corner to look for smaller values
			if (arr[i] + arr[j] + arr[k] >= sum)
				k--;

			// Else move left corner
			else
			{
				// This is important. For current i and j, there
				// can be total k-j third elements.
				ans += (k - j);
				j++;
			}
		}
	}
	return ans;
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