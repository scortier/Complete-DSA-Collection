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


// every k size sub-array
void print_max(int a[], int n, int k)
{
	// max_upto array stores the index
	// upto which the maximum element is a[i]
	// i.e. max(a[i], a[i + 1], ... a[max_upto[i]]) = a[i]

	int max_upto[n];

	// Update max_upto array similar to
	// finding next greater element
	stack<int> s;
	s.push(0);
	for (int i = 1; i < n; i++) {
		while (!s.empty() && a[s.top()] < a[i]) {
			max_upto[s.top()] = i - 1;
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		max_upto[s.top()] = n - 1;
		s.pop();
	}
	int j = 0;
	for (int i = 0; i <= n - k; i++) {

		// j < i is to check whether the
		// jth element is outside the window
		while (j < i || max_upto[j] < i + k - 1)
			j++;
		cout << a[j] << " ";
	}
	cout << endl;
}
void solve()
{
	int n, k; cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];

}

int32_t main()
{
	lage_rho();
	solve();
	return 0;
}