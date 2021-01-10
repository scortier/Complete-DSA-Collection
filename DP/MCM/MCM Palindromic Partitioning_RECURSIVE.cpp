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
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
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
	if (i >= j)
		return 0;
	if (isPalindrome(s, i, j) == true)
		return 0;
	int mn = MOD;
	for (int k = i; k < j - 1; k++)
	{
		int temp = solve(s, i, k) + solve(s, k + 1, j) + 1;
		mn = min(mn, temp);
	}
	return mn;
}



int32_t main()
{
	fast();
	string s;
	cin >> s;
	int i = 0, j = s.size() - 1;
	cout << solve(s, i, j);
	return 0;
}