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
#define M 50
// Utility method to construct the dp array
void constructDP(int dp[M][M], string str)
{
	int l = str.length();

	// declare 2D array isPalin, isPalin[i][j] will
	// be 1 if str(i..j) is palindrome
	int isPalin[l + 1][l + 1];

	// initialize dp and isPalin array by zeros
	for (int i = 0; i <= l; i++) {
		for (int j = 0; j <= l; j++) {
			isPalin[i][j] = dp[i][j] = 0;
		}
	}

	// loop for starting index of range
	for (int i = l - 1; i >= 0; i--) {

		// initialize value for one character strings as 1
		isPalin[i][i] = 1;
		dp[i][i] = 1;

		// loop for ending index of range
		for (int j = i + 1; j < l; j++) {

			/* isPalin[i][j] will be 1 if ith and
			   jth characters are equal and mid
			   substring str(i+1..j-1) is also a
			   palindrome             */
			isPalin[i][j] = (str[i] == str[j] && (i + 1 > j - 1 || isPalin[i + 1][j - 1]));

			/* dp[i][j] will be addition of number
			   of palindromes from i to j-1 and i+1
			   to j subtracting palindromes from i+1
			   to j-1 (as counted twice) plus 1 if
			   str(i..j) is also a palindrome */
			dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + isPalin[i][j];
		}
	}
}

// method returns count of palindromic substring in range (l, r)
int countOfPalindromeInRange(int dp[M][M], int l, int r)
{
	return dp[l][r];
}


void solve()
{

	string str = "xyaabax";

	int dp[M][M];
	constructDP(dp, str);

	int l = 3;
	int r = 5;

	cout << countOfPalindromeInRange(dp, l, r);
}

int32_t main()
{
	lage_rho();
	solve();
	return 0;
}