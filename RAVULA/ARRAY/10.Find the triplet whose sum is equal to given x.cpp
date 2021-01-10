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

int findtriplet(int a[], int n, int sum)
{
	int l, r, tsum;
	for (int i = 0; i < n - 2; i++)
	{
		l = i + 1; r = n - 1;
		while (l < r)
		{
			tsum = a[i] + a[l] + a[r];
			if (tsum == sum)\
			{
				cout << a[i] << a[l] << a[r] << endl;
				return 1;
			}

			if (tsum < sum) l++;
			else r--;
		}
	}
	return 0;
}


int32_t main()
{
	fast();

	return 0;
}