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
#define MAX_CHARS 26
// This function calculates number of unique characters
// using a associative array count[]. Returns true if
// no. of characters are less than required else returns
// false.
bool isValid(int count[], int k)
{
	int val = 0;
	for (int i = 0; i < MAX_CHARS; i++)
		if (count[i] > 0)
			val++;

	// Return true if k is greater than or equal to val
	return (k >= val);
}

// Finds the maximum substring with exactly k unique chars
void kUniques(string s, int k)
{
	int u = 0; // number of unique characters
	int n = s.length();

	// Associative array to store the count of characters
	int count[MAX_CHARS];
	memset(count, 0, sizeof(count));

	// Traverse the string, Fills the associative array
	// count[] and count number of unique characters
	for (int i = 0; i < n; i++)
	{
		if (count[s[i] - 'a'] == 0)
			u++;
		count[s[i] - 'a']++;
	}

	// If there are not enough unique characters, show
	// an error message.
	if (u < k)
	{
		cout << "Not enough unique characters";
		return;
	}

	// Otherwise take a window with first element in it.
	// start and end variables.
	int curr_start = 0, curr_end = 0;

	// Also initialize values for result longest window
	int max_window_size = 1, max_window_start = 0;

	// Initialize associative array count[] with zero
	memset(count, 0, sizeof(count));

	count[s[0] - 'a']++; // put the first character

	// Start from the second character and add
	// characters in window according to above
	// explanation
	for (int i = 1; i < n; i++)
	{
		// Add the character 's[i]' to current window
		count[s[i] - 'a']++;
		curr_end++;

		// If there are more than k unique characters in
		// current window, remove from left side
		while (!isValid(count, k))
		{
			count[s[curr_start] - 'a']--;
			curr_start++;
		}

		// Update the max window size if required
		if (curr_end - curr_start + 1 > max_window_size)
		{
			max_window_size = curr_end - curr_start + 1;
			max_window_start = curr_start;
		}
	}

	cout << "Max sustring is : "
	     << s.substr(max_window_start, max_window_size)
	     << " with length " << max_window_size << endl;
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