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

int a[1001];
int st[4004]; //4n size if segment tree.

void build(int si, int ss, int se)
{
	if (ss == se) //at leaf node
	{
		st[si] = a[ss]; //at segment index we rgoing to store that element.
		return;
	}
	int mid = (ss + se) / 2;
	build(2 * si , ss , mid); //left subtree
	build(2 * si + 1, mid + 1, se); //right subtree

	st[si] = min(st[2 * si], st[2 * si + 1]);

}

int query(int si, int ss, int se, int qs, int qe)
{
	if (ss > qe || se < qs) //if seg start is of query end
		return MOD;

	if (ss > qs || se < qe) return st[si];

	int mid = (ss + se) / 2;

	return min(query(2 * si, ss, mid, qs, qe), query(2 * si + 1, mid + 1, se, qs, qe));
}

int32_t main()
{
	fast();
	int n, q, l, r;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	cin >> q;
	while (q--)
	{
		cin >> l >> r;
		cout << query(1, 1, n, l + 1, r + 1) << endl;
	}
	return 0;
}