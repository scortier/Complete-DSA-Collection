// QUARANTINE DAYS..;)
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
struct Point
{
	int x, y;
};

bool overlap(Point l1, Point r1, Point l2, Point r2)
{
	if (l1.x >= r2.x || l2.x >= r1.x)
		return false;
	else if (l1.y <= r2.y || l2.y <= r1.y)
		return false;

	return true;
}


void solve()
{
	Point l1 = {0, 10}, r1 = {10, 0};
	Point l2 = {5, 5}, r2 = {15, 0};
	if (overlap) cout << "Overlap kar rhe";
	else pr("Nhi kar rhe");
}

int32_t main()
{
	lage_rho();
	solve();
	return 0;
}