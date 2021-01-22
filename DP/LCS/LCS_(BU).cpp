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
// BU -- RECUSION+TABLE
// TD -- ONLY TABLE
//table to store the value so that it can be reuse.
//table is made only with those var jo recursive m change  ho tahe hai.
int t[8][9];
int LCS_BU(string x, string y, int m, int n)
{
	if (n == 0 || m == 0)
		return 0;
	//if box is -1 then it is not used prev .
	if (t[m][n] != -1)
		return t[m][n];

	//if box doesn't contain -1.
	if (x[m - 1] == y[n - 1])
		// when last one letter is common and check for others too.
		return t[m][n] = (1 + LCS_BU(x, y, m - 1, n - 1));
	else
		// letter doesn't matched so decrease one by both sides one at a time.
		return t[m][n] = max(LCS_BU(x, y, m - 1, n), LCS_BU(x, y, m, n - 1));

}



int32_t main()
{
	fast();
	memset(t, -1, sizeof(t));	//initialize whole matrix with -1.
	string x, y;
	cin >> x >> y;
	int n = y.size();
	int m = x.size();
	cout << LCS_BU(x, y, m, n);
	return 0;
}

// input:
// abcdgh
// abedfhr