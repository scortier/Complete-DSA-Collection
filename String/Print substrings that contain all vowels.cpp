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
#define pi 			    pair < int , int >
#define pr(gg)          cout<<gg<<endl
#define mk(arr,n,type)  type *arr=new type[n];

void lage_rho() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
/**********=============########################============***********/

// Returns true if x is vowel.
bool isVowel(char x)
{
	// Function to check whether a character is
	// vowel or not
	return (x == 'a' || x == 'e' || x == 'i' ||
	        x == 'o' || x == 'u');
}

void noofsubs(string s)
{
	int n = s.size();
	int start = 0;
	set<char> hash;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (isVowel(s[i] == true))
		{
			hash.insert(s[i]);
			if (hash.size() == 5)
				cout << s.substr(start, i - start + 1) << " ";
		}
		else
		{
			start = i + 1;
			hash.clear();
		}
	}
}
void solve()
{	string s; cin >> s;
	noofsubs(s);

}

int32_t main()
{
	lage_rho();
	// test
	solve();
	return 0;
}