#include <bits/stdc++.h>
using namespace std;
#define endl 		    "\n"
#define test 		    int tt;cin>>tt;while(tt--)
#define fl(i,a,b)       for( int i=a;i<b;i++)
#define ll 			    long long int
#define pb 			    push_back
#define mp 			    make_pair
#define MOD 		    1000000007
#define PI 			    acos(-1.0)
#define assign(x,val)   memset(x,val,sizeof(x))
#define pr(gg)          cout<<gg<<endl
#define mk(arr,n,type)  type *arr=new type[n];


void lage_rho() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
/**********============########################============***********/
#define NO_OF_CHARS 256
int firstNonRepeating(string str)
{
	pair<int, int> arr[NO_OF_CHARS];

	for (int i = 0; str[i]; i++) {
		(arr[str[i]].first)++;
		arr[str[i]].second = i;
	}

	int res = INT_MAX;
	for (int i = 0; i < NO_OF_CHARS; i++)

		// If this character occurs only
		// once and appears before the
		// current result, then update the
		// result
		if (arr[i].first == 1)
			res = min(res, arr[i].second);

	return res;
}

void solve()
{
	string s;
	cin >> s;
	int r = firstNonRepeating(s);
	if (r == INT_MAX) pr("All are repeating");
	else pr(s[r]);
}

int32_t main()
{
	lage_rho();
	solve();
	return 0;
}