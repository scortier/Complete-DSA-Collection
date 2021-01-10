// QUARANTINE DAYS..;)
#include <bits/stdc++.h>
using namespace std;
#define endl 		    "\n"
#define test 		    int tt;cin>>tt;while(tt--)
#define rep(i,a,b)      for( int i=a;i<b;i++)
#define rev(i,a,b)      for( int i=b-1;i>=a;i--)
#define reep(i,a,b)     for( int i=a;i<=b;i++)
#define ll 			    long long int
#define pb 			    push_back
#define mp 			    make_pair
#define f 			    first
#define s 			    second
#define MOD 		    1000000007
#define PI 			    acos(-1.0)
#define assign(x,val)   memset(x,val,sizeof(x))
#define prec(val, dig)  fixed << setprecision(dig) << val
#define vi   		    vector < int >
#define pi 			    pair < int , int >
#define pr(gg)          cout<<gg<<endl
#define mk(arr,n,type)  type *arr=new type[n];
const int maxm = 2e6 + 10;

void lag_gae() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
/**********====================########################=================***********/
const int N = 1e5 + 9;
int a[N][26];
vector<int>v[N];
bool visited[N];
string s;
void dfs(int x) {
	visited[x] = 1;
	a[x][s[x] - 'a']++;
	for (int child : v[x]) {
		if (visited[child])
			continue;
		dfs(child);
		for (int i = 0; i < 26; i++)
			a[x][i] += a[child][i];
	}
}

void solve()
{
	int x, q;
	cin >> x >> q;
	cin >> s;
	s = "*" + s;
	int l, r;
	for (int i = 1; i < x; i++) {
		cin >> l >> r;
		v[l].push_back(r);
		v[r].push_back(l);
	}
	char c;
	dfs(1);
	for (int i = 1; i <= q; i++) {
		cin >> l >> c;
		cout << a[l][c - 'a'] << endl;

	}
}

int32_t main()
{
	lag_gae();
	// test
	solve();
	return 0;
}