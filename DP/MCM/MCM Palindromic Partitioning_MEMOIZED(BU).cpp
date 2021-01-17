// QUARANTINE DAYS..;)
#include <bits/stdc++.h>
using namespace std;


#define MOD 		    1000000007
#define assign(x,val)   memset(x,val,sizeof(x))


void fast() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
/**********====================########################=================***********/

int static t[1001][1001];//can be used in func without declaring it.

bool isPalindrome(string s, int i, int j)
{
	if (i == j) return true;
	if (i > j) return true;
	while (i < j)
	{
		if (s[i] != s[j]) return false;
		i++;
		j--;
	}
	return true;
}



int solve(string s, int i, int j)
{	int left = 0, right = 0;
	if (i >= j)
		return 0;
	if (isPalindrome(s, i, j) == true)
		return 0;
	if (t[i][j] != -1)
		return t[i][j];

	int mn = MOD;
	for (int k = i; k <= j - 1; k++)
	{
		if (t[i][k] != -1)
			left = t[i][k];
		else
		{
			left = solve(s, i, k);
			t[i][k] = left;
		}
		if (t[k + 1][j] != -1)
			right = t[k + 1][j];
		else
		{
			right = solve(s, k + 1, j);
			t[k + 1][j] = right;
		}
		int temp = 1 + left + right;
		mn = min(mn, temp);
	}
	t[i][j] = mn;
	return t[i][j];
}



int32_t main()
{
	fast();
	string s = "ababbbabbababa";
	memset(t, -1, sizeof(t));// make complete table intialize with -1
	int n = s.size();
	int i = 0, j = n - 1;
	cout << solve(s, i, j);
	return 0;
}