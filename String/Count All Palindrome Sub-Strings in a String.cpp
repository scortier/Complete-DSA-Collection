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
//BRUTE FORCE
//UNORDERED MAP

//space - O(n)
// Returns total number of palindrome substring of
// length greater than equal to 2
int countPalindromes(string s)
{
	unordered_map<string, int> m;
	for (int i = 0; i < s.length(); i++) {

		// check for odd length palindromes
		for (int j = 0; j <= i; j++) {

			if (!s[i + j])
				break;

			if (s[i - j] == s[i + j]) {

				// check for palindromes of length
				// greater than 1
				if ((i + j + 1) - (i - j) > 1)
					m[s.substr(i - j,
					           (i + j + 1) - (i - j))]++;

			} else
				break;
		}

		// check for even length palindromes
		for (int j = 0; j <= i; j++) {
			if (!s[i + j + 1])
				break;
			if (s[i - j] == s[i + j + 1]) {

				// check for palindromes of length
				// greater than 1
				if ((i + j + 2) - (i - j) > 1)
					m[s.substr(i - j,
					           (i + j + 2) - (i - j))]++;

			} else
				break;
		}
	}
	return m.size();
}

//space - o(n2)
// Returns total number of palindrome substring of
// length greater then equal to 2
int CountPS(char str[], int n)
{
	// create empty 2-D matrix that counts all palindrome
	// substring. dp[i][j] stores counts of palindromic
	// substrings in st[i..j]
	int dp[n][n];
	memset(dp, 0, sizeof(dp));

	// P[i][j] = true if substring str[i..j] is palindrome,
	// else false
	bool P[n][n];
	memset(P, false , sizeof(P));

	// palindrome of single length
	for (int i = 0; i < n; i++)
		P[i][i] = true;

	// palindrome of length 2
	for (int i = 0; i < n - 1; i++)
	{
		if (str[i] == str[i + 1])
		{
			P[i][i + 1] = true;
			dp[i][i + 1] = 1 ;
		}
	}

	// Palindromes of length more than 2. This loop is similar
	// to Matrix Chain Multiplication. We start with a gap of
	// length 2 and fill the DP table in a way that gap between
	// starting and ending indexes increases one by one by
	// outer loop.
	for (int gap = 2 ; gap < n; gap++)
	{
		// Pick starting point for current gap
		for (int i = 0; i < n - gap; i++)
		{
			// Set ending point
			int j = gap + i;

			// If current string is palindrome
			if (str[i] == str[j] && P[i + 1][j - 1] )
				P[i][j] = true;

			// Add current palindrome substring ( + 1)
			// and rest palindrome substring (dp[i][j-1] + dp[i+1][j])
			// remove common palindrome substrings (- dp[i+1][j-1])
			if (P[i][j] == true)
				dp[i][j] = dp[i][j - 1] + dp[i + 1][j] + 1 - dp[i + 1][j - 1];
			else
				dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
		}
	}

	// return total palindromic substrings
	return dp[0][n - 1];
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