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

//TC:O(N) SC:O(N)
void re1(int a[], int n)
{
	int flag = 1;
	int temp[n];
	int s = 0; int l = n - 1

	                   fl(i, 0, n)
	{
		if (flag)
			temp[i] = a[l--];
		else
			temp[i] = a[s++];
		flag = !flag;
	}

	fl(i, 0, n)
	a[i] = temp[i];
}


//TC:O(N) SC:O(1)
void re2(int a[], int n) {
	int max_idx = n - 1, min_idx = 0;
	int max_ele = a[n - 1] + 1;
	fl(i, 0, n)
	{
		if (i % 2 == 0)
		{
			a[i] += (a[max_idx] % max_ele) * max_ele;
			max_idx--;
		}
		else {
			a[i] += (a[min_idx] % max_ele) * max_ele;
			min_idx++;
		}
	}
	fl(i, 0, n)
	cout << a[i] / max_ele;



}


int32_t main()
{
	lage_rho();
	test
	solve();
	return 0;
}