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
// If the next character is same as the last character in res,
// pop the last character from res.
// In this way, we remove a pair of adjacent duplicates characters.

// If the next character is different,
// we append it to the end of res.
string removeDuplicates(string S) {
	string res = "";
	for (char& c : S)
		if (res.size() && c == res.back())
			res.pop_back();
		else
			res.push_back(c);
	return res;
}

void solve()
{
	string s; cin >> s;
	cout << removeDuplicates(s);

}

int32_t main()
{
	lage_rho();
	solve();
	return 0;
}