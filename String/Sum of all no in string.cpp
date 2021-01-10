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

int findSum(string str)
{
	// A temporary string
	string temp = "";

	// holds sum of all numbers present in the string
	int sum = 0;

	// read each character in input string
	for (char ch : str)
	{
		// if current character is a digit
		if (isdigit(ch))
			temp += ch;

		// if current character is an alphabet
		else
		{
			// increment sum by number found earlier
			// (if any)
			sum += atoi(temp.c_str());

			// reset temporary string to empty
			temp = "";
		}
	}

	// atoi(temp.c_str()) takes care of trailing
	// numbers
	return sum + atoi(temp.c_str());
}

void solve()
{
	string s; cin >> s;
	cout << findSum(s);
}

int32_t main()
{
	lage_rho();
	solve();
	return 0;
}