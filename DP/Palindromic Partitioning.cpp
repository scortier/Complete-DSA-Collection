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
int t[1001][1001];
bool ispalindrome(string s, int i, int j)
{
	if (i == j) return true;
	if (i > j) return true;
	while (i > j)
	{
		if (s[i] != s[j]) return false;
		i++;
		j--;
	}
	return true;
}

int partition(string s, int i, int j)
{
	//base ccondn
	if (i == j and i > j) return 0;
	if (ispalindrome(s, i, j) == true)
		return 0;
	int left, right;
	if (t[i][j] != -1) return t[i][j];
	int mn = INT_MAX;
	for (int k = i; k <= j - 1; k++)
	{


		if (t[i][j] != -1) left = t[i][k];
		else
		{
			left = partition(s, i, k);
			t[i][k] = left;
		}
		if (t[k + 1][j] != -1)
			right = t[k + 1][j];
		else
		{
			right = partition(s, k + 1, j);
			t[k + 1][j] = right;
		}
		int temp = 1 + left + right;

		// int temp = solve(s, i, k) + solve(s, k + 1, j) + 1;
		if (temp < mn)
			mn = temp;
	}
	t[i][j] = mn;
	return t[i][j];
}

void solve()
{
	string s; cin >> s;
	memset(t, -1, sizeof(t));
	int n = s.size();
	int i = 0, j = n - 1;
	cout << partition(s, i, j);

}

int32_t main()
{
	lage_rho();
	solve();
	return 0;
}