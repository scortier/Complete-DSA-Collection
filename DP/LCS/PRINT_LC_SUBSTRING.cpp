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
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
}
/**********====================########################=================***********/

int t[8][9];

string LCS_TD(string x, string y, int m, int n)
{
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			if (j == 0 || i == 0)
				t[i][j] = 0;
		}
	}

	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (x[i - 1] == y[j - 1])
				// return LCS_TD(x,y,i-1,j-1);
				t[i][j] = 1 + t[i - 1][j - 1];
			else
				t[i][j] = 0;
		}
	}

	// Start from the right-most-bottom-most corner and
	// one by one store characters in lcs[]
	int i = m, j = n;	//i rep rows , j rep
	string s = " "; //empty string to insert same alphabet.
	while (i > 0 && j > 0)
	{
		// If current character in X[] and Y are same, then
		// current character is part of LCS
		if (x[i - 1] == y[j - 1])
		{
			s.pb (x[i - 1]); // Put current character in string s
			i--; j--;    // reduce values of i, j
		}

		// If not same, then find the larger of two and
		// go in the direction of larger value
		else if (t[i - 1][j] > t[i][j - 1])
			i--; //left shift
		else
			j--; //right shift
	}
	reverse(s.begin(), s.end()); 5y
	return s;

	// // Print the lcs
	// cout << "LCS of " << X << " and " << Y << " is " << lcs;

}



int32_t main()
{
	fast();
	memset(t, -1, sizeof(t));	//initialize whole matrix with -1.
	string x = "abcdgh";
	string y = "abedfhr";
	// cin >> x >> y;
	int n = y.size();
	int m = x.size();
	cout << LCS_TD(x, y, m, n);
	return 0;
}


// input:
// abcdgh
// abedfhr