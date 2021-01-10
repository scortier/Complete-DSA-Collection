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

bool solve(int a[], int n, int sum)
{	int s = 0, t = 0;
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		s = a[i] + a[i + 1];
		t = sum - s;
		for (int j = i + 2; j < n; j++)
		{
			if (a[j] == t)
				return true;
			return false;
		}

	}
}

int32_t main()
{
	fast();
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int sum = 7;
	cout << solve(a, n, sum);
	return 0;
}
