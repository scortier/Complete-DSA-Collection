// QUARANTINE DAYS..;)
#include <bits/stdc++.h>
using namespace std;
#define endl 		    "\n"
#define test 		    int tt;cin>>tt;while(tt--)
#define fl(i,a,b)       for( int i=a;i<b;i++)
#define bfl(i,a,b)      for( int i=b-1;i>=a;i--)
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

void lage_rho() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
/**********====================########################=================***********/


// void solve()
// {
// 	int n;cin>>n;
// 	int a[n];
// 	for(int i=0;i<n;i++) cin>>a[i];
// 	int cnt[n]={0};
// 	fl(i,0,n) cnt[a[i]]++;
// 	fl(i,0,n)
// 	{
// 		int ct=x-a[i];
// 		if()
// 	}

// }



void sum(int a[], int n, int sum)
{
	unordered_map<int, int>map;
	int cur_sum = 0;
	fl(i, 0, n)
	{
		cur_sum = cur_sum + a[i];


		if (cur_sum == sum) cout << 0 << "to" << i << endl;

		else if (map.find(cur_sum - sum) != map.end())
		{
			cout << map[cur_sum - sum] + 1 << "to" << i << endl;
			return;
		}
		map[cur_sum] = i;



	}
	cout << "no subarray exist";
}

void solve() {
	int n, summ; cin >> n >> summ;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	sum(a, n, summ);
}
int32_t main()
{
	lage_rho();
	// test
	solve();
	return 0;
}