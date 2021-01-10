// QUARANTINE DAYS..;)
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

void rev(string& s)
{
	int i = 0;
	for (int j = 0; j < s.size(); j++)
	{
		if (s[j] == ' ')
			reverse(s.begin() + i, s.end() + j);
		i = j + 1;
	}
	// Reverse the last word
	reverse(s.begin() + i, s.end());

	// Reverse the entire string
	reverse(s.begin(), s.end());

}
string reverseString(string str)
{

	// Reverse str using inbuilt function
	reverse(str.begin(), str.end());

	// Add space at the end so that the
	// last word is also reversed
	str.insert(str.end(), ' ');

	int n = str.length();

	int j = 0;

	// Find spaces and reverse all words
	// before that
	for (int i = 0; i < n; i++) {

		// If a space is encountered
		if (str[i] == ' ') {
			reverse(str.begin() + j,
			        str.begin() + i);

			// Update the starting index
			// for next word to reverse
			j = i + 1;
		}
	}

	// Remove spaces from the end of the
	// word that we appended
	str.pop_back();

	// Return the reversed string
	return str;
}

void solve()
{
	string s = "  .aditya singh sisodiya";
	// rev(s);
	string st = reverseString(s);
	cout << st;
}

int32_t main()
{
	lage_rho();
	solve();
	return 0;
}