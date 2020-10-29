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


//Tournament Method
//Divide the array into two parts and compare the maximums and
//minimums of the two parts to get the maximum and the
//minimum of the whole array.


//structure is used to return
// two values from minMax()
struct pair
{
	int min;
	int max;
}

struct Pair getMinMax(int arr[], int low,
                      int high)
{
	struct Pair minmax, mml, mmr;
	int mid;

	// If there is only on element
	if (low == high)
	{
		minmax.max = arr[low];
		minmax.min = arr[low];
		return minmax;
	}

	// If there are two elements
	if (high == low + 1)
	{
		if (arr[low] > arr[high])
		{
			minmax.max = arr[low];
			minmax.min = arr[high];
		}
		else
		{
			minmax.max = arr[high];
			minmax.min = arr[low];
		}
		return minmax;
	}

	// If there are more than 2 elements
	mid = (low + high) / 2;
	mml = getMinMax(arr, low, mid);
	mmr = getMinMax(arr, mid + 1, high);

	// Compare minimums of two parts
	if (mml.min < mmr.min)
		minmax.min = mml.min;
	else
		minmax.min = mmr.min;

	// Compare maximums of two parts
	if (mml.max > mmr.max)
		minmax.max = mml.max;
	else
		minmax.max = mmr.max;

	return minmax;
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