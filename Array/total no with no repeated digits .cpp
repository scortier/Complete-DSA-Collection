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

// Function to check if the given
// number has repeated digit or not
int repeated_digit(int n)
{
	unordered_set<int> s;

	// Traversing through each digit
	while (n != 0)
	{
		int d = n % 10;

		// if the digit is present
		// more than once in the
		// number
		if (s.find(d) != s.end())
		{
			// return 0 if the number
			// has repeated digit
			return 0;
		}
		s.insert(d);
		n = n / 10;
	}
	// return 1 if the number has
	// no repeated digit
	return 1;
}

// Function to find total number
// in the given range which has
// no repeated digit
int calculate(int L, int R)
{
	int answer = 0;

	// Traversing through the range
	for (int i = L; i < R + 1; ++i)
	{

		// Add 1 to the answer if i has
		// no repeated digit else 0
		answer = answer + repeated_digit(i);
	}

	return answer ;
}

void solve()
{


}

int32_t main()
{
	lage_rho();
	solve();
	return 0;
}