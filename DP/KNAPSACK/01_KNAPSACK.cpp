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
//0-1 KNAPSACK BOTTOM UP APPROACH
//w is knapsack ki capacity, n is arr size,wt is item weight
int knapsackBU(int wt[], int val[], int w, int n)
{	//BASE CONDN
	if (n == 0 || w == 0) return 0;
	//RECURSIVE
	if (wt[n - 1] <= w)
		// val[n-1] is added weight , w-wt[n-1] is bacha hua weight.
		return max((val[n - 1] + knapsackBU(wt, val, w - wt[n - 1], n - 1)), knapsackBU(wt, val, w, n - 1));

	else if (wt[n - 1] > w)
		return knapsackBU(wt, val, w, n - 1);
}




int32_t main()
{
	fast();

	return 0;
}