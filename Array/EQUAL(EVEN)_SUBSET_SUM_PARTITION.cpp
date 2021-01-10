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
//FIND THAT ARRAY CAN BE SPLIT INTO TWO SUBSET HAVING EQUAL SUM.

//0-1 KNAPSACK TOP-DOWN APPROACH
bool knapsackTD(int wt[], int w, int n)
{

	int w = 0;
	for (int i = 0; i < n; i++)
		w += wt[i];

	// if (w % 2 != 0)
	// 	return false;

	//base condn ,fill comp matrix t with 0. INITIALIZATION
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < w + 1; j++)
		{
			if (i == 0)
				t[i][j] = false;
			else if (j == 0)
				t[i][j] = true;
		}
	}

	//top-down
	// //t[n][w] is to maximize current block ,using prev solved subproblems
	// if (wt[n - 1] <= w)
	// 	//max(include the item ,exclude the item).
	// 	t[n][w] = max(val[n - 1] + t[w - wt[n - 1]][n - 1], t[w][n - 1]);

	// else if (wt[n - 1] > w)
	// 	t[n][w] = t[n - 1][w];

	//TO FILL THE REMAINING MATRIX. replace n->i , w->j
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < w + 1; j++)
		{
			if (wt[i - 1] <= j)
				t[i][j] = ( t[i - 1][j - wt[i - 1]] ||  t[i - 1][j]);

			else
				t[i][j] = t[i - 1][j];
		}
	}

	return t[n][w];

}

bool isPartition(int wt[], int n)
{
	int w = 0;
	for (int i = 0; i < n; i++)
		w += wt[i];

	if (w % 2 == 0) return knapsackTD(wt, w / 2, n);
	else return false;
}





int32_t main()
{
	fast();
	int wt[] = {1, 5, 11,  5};
	int n = 4;


	int t[n + 1][w + 1];
	if (isPartition(wt, n) == true)
		cout << "YES";
	else cout << "NO";

	return 0;
}