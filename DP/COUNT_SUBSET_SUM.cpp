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



int t[1001][1001]; //matrix for intialization

//0-1 KNAPSACK TOP-DOWN APPROACH
int knapsackTD(int wt[],  int w, int n)
{
	//base condn ,fill comp matrix t with 0. INITIALIZATION
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < w + 1; j++)
		{
			if (i == 0)
				t[i][j] = 0;
			else if (j == 0)
				t[i][j] = 1;
		}
	}


	//TO FILL THE REMAINING MATRIX. replace n->i , w->j
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < w + 1; j++)
		{
			if (wt[i - 1] <= j)
				t[i][j] = t[i - 1][j - wt[i - 1]] + t[i - 1][j];

			else
				t[i][j] = t[i - 1][j];
		}
	}

	return t[n][w];

}



int32_t main()
{
	fast();
	int w = 10;
	int wt[] = { 7, 8};
	int n = 2;
	cout << knapsackTD(wt, n, w);

	return 0;

}
