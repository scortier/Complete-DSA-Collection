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

// int t[e+1][f+1];
int t[1001][1001];

int solve(int e, int f)
{
	if (e == 0 || f == 0) return f;
	if (e == 1) return f;
	if (t[e][f] != -1) return t[e][f];

	int mn = MOD;
	for (int k = 1; k <= f; k++)
	{
		//agr -1 nhi matlab pehle use ho chuka hai toh sidhe return kardo.
		if (t[e - 1][k - 1] != -1)
			int low = t[e - 1][k - 1];
		else
			//pehle solve karke low m store karo then array k specific block m
			low = solve(e - 1, k - 1),
			t[e - 1][k - 1] = low;

		if (t[e][f - k] != -1)
			int right = t[e][f - k];
		else
			right = solve(e, f - k),
			t[e][f - k] = right;

		int temp = 1 + left + right;
		mn = min(mn, temp);
	}
	t[e][f] = mn;
	return t[e][f];
}


int32_t main()
{
	fast();
	int e, f;
	cin >> e >> f;
	cout << solve(e, f);
	return 0;
}