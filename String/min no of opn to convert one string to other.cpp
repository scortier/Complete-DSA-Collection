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

int minopn(string s1, string s2)
{
	int n = s1.size(), m = s2.size();

	if (n != m) return -1;
	int cnt[256] = {0};
	fl(i, 0, n) cnt[s1[i]]++;
	fl(i, 0, m) cnt[s2[i]]--;
	fl(i, 0, 256) if (cnt[i]) return -1;

	int res = 0;
	for (int i = n - 1, j = n - 1; i >= 0;)
	{
		while (i >= 0 and s1[i] != s2[i])
		{
			i--;
			res++;
		}
		//if s1[i] and s2[i] matches
		if (i >= 0)
		{
			i--;
			j--;
		}

	}
	return res;
}
void solve()
{
	string s1, s2;
	cin >> s1 >> s2;
	cout << minopn(s1, s2);
}

int32_t main()
{
	lage_rho();
	// test
	solve();
	return 0;
}