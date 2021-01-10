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
#define PI 			    acos(-1.0)
#define assign(x,val)   memset(x,val,sizeof(x))
#define prec(val, dig)  fixed << setprecision(dig) << val
#define vec 		    vector < ll >
#define vecpi	 	    vector < pair < ll, ll > >
#define pi 			    pair < ll , ll >
#define lower(str) 		transform(str.begin(), str.end(), str.begin(), ::tolower);
#define upper(str) 		transform(str.begin(), str.end(), str.begin(), ::toupper);
#define mk(arr,n,type)  type *arr=new type[n];
const int maxm = 2e6 + 10;

void fast() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
/**********====================########################=================***********/


bool knapsackTD(int arr[], int n)
{
	int range = 0;
	for (int i = 0; i < n; i++)
	{
		range += arr[i];
	}

	//array created to store subproblems
	bool t[n + 1][range + 1];
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < range + 1; j++)
		{
			if (i == 0) t[i][j] = false;
			else if (j == 0) t[i][j] = true;
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < range + 1; j++)
		{
			if (arr[i - 1] <= j)
				t[i][j] = t[i][j - arr[i - 1]] || t[i - 1][j];
			else if (arr[i - 1] > j)
				t[i][j] = t[i - 1][j];
		}
	}

	vector<int>v(n); //to store the subset 1
	int mn = MOD; int x;	//intial diffbw two sum
	for (int i = 0; i < range / 2; i++)   v[i] = arr[i];
	for (int i = 0; i < v.size(); i++)
	{
		int y = range - 2 * v[i];
		mn = min(mn, y);
	}
	return mn;

	// // Initialize difference of two sums.
	// int diff = MOD;

	// // Find the largest j such that t[n][j]
	// // is true where j loops from sum/2 t0 0
	// for (int j = range / 2; j >= 0; j--)
	// {
	// 	// Find the
	// 	if (t[n][j] == true)
	// 	{
	// 		diff = range - 2 * j;
	// 		break;
	// 	}
	// }
	// return diff;

}


int32_t main()
{
	fast();
	int arr[] = {1, 6, 5, 11};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "The minimum difference between 2 sets is "
	     << knapsackTD(arr, n);
	return 0;

}