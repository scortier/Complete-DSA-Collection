// QUARANTINE DAYS..;)
#include <bits/stdc++.h>
using namespace std;
#define MOD 		    1000000007
void fast() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
/**********====================########################=================***********/

bool isPalindrome(string s, int i, int j)
{
	if (i == j) return true;
	if (i > j) return false;
	while (i < j)
	{
		if (s[i] != s[j]) return false;
		i++;
		j--;
	}
	return true;
}

int solve(string s, int i, int j)
{
	//base condn
	if (i >= j or isPalindrome(s, i, j ) == true)// as on i==j only one arr ele we will get.
		return 0;
	int mn = MOD;
	for (int k = i; k < j ; k++)
	{
		//In nitin c1="n" c2="itin" (c1 and c2 are min no of palindrome partition in that section) and both are
		//separated by so +1 for that.
		//temp=c1+c2+1
		int temp = solve(s, i, k) + solve(s, k + 1, j) + 1;
		mn = min(mn, temp);
	}
	return mn;
}




int32_t main()
{
	//fast();
	string s = "ababbbabbababa";
	int n = s.size();
	int i = 0, j = n - 1;
	cout << solve(s, i, j);
	return 0;
}