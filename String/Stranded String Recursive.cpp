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

bool solve(string a, string b)
{
	//base condn
	if (a.compare(b) == 0) return true;
	if (a.length() <= 1) return false;

	int n = a.length();
	bool flag = false;
	for (int i = 1; i <= n - 1; i++)
	{	bool p = true, q = true, r = true, s = true;
		p = solve(a.substr(0, i), b.substr(n - i, i));
		q = solve(a.substr(i, n - i), b.substr(0, n - i));
		r = solve(a.substr(0, i), b.substr(0, i));
		s = solve(a, substr(i, n - i), b.substr(i, n - i));
		if ((p && q) || (r && s))
		{
			flag = true;
			break;
		}
	}
}




int32_t main()
{
	fast();

	return 0;
}