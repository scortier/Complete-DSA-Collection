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
//TC :O(N) SC:O(N)
void sort012(int arr[], int n)
{
	// Variables to maintain the count of 0's,
	// 1's and 2's in the array
	int count0 = 0, count1 = 0, count2 = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0)
			count0++;
		if (arr[i] == 1)
			count1++;
		if (arr[i] == 2)
			count2++;
	}

	// Putting the 0's in the array in starting.
	for (int i = 0; i < count0; i++)
		arr[i] = 0;

	// Putting the 1's in the array after the 0's.
	for (int i = count0; i < (count0 + count1); i++)
		arr[i] = 1;

	// Putting the 2's in the array after the 1's
	for (int i = (count0 + count1); i < n; i++)
		arr[i] = 2;

	return;
}

//Dutch National Flag Algorithm OR 3-way Partitioning:
// TC O(N)  SC O(1)
void sort012(int a[], int arr_size)
{
	int lo = 0;
	int hi = arr_size - 1;
	int mid = 0;

	// Iterate till all the elements
	// are sorted
	while (mid <= hi) {
		switch (a[mid]) {

		// If the element is 0
		case 0:
			swap(a[lo++], a[mid++]);
			break;

		// If the element is 1 .
		case 1:
			mid++;
			break;

		// If the element is 2
		case 2:
			swap(a[mid], a[hi--]);
			break;
		}
	}
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