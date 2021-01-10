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

//TC:O(logn) base:2
//recurrence reln:T(N)=T(N/2)+1;

//iterartive version
int BinarySearch(int a[], int low, int high, int target)
{
	int low , high;
	int mid;

	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (a[mid] == target)
			return mid;
		else if (a[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}


int32_t main()
{
	fast();
	int l, h, t, n;
	int >> n >> l >> h >> t;
	int a[n];
	rep(i, 0, n) cin >> a[i];
	cout << BinarySearch(a, l, h, t);
	return 0;
}