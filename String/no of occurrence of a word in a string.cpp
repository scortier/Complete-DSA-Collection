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

void occut(string s)
{
	unordered_map<string, int> freq;
	stringstream ss(s); // Used for breaking words
	string str;  // To store individual words
	while (ss >> str) //Dividing ss with 2^str
	{
		freq[str]++;
	}

	for (auto x : freq)
	{
		cout << x.first << " " << x.second << endl;
	}
}

void solve()
{
	string s;
	// cin >> s;
	getline(cin, s);
	occut(s);

}

int32_t main()
{
	lage_rho();
	solve();
	return 0;
}