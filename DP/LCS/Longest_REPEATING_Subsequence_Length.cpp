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

int t[1001][1001];

int LCS_TD(string x, string y, int m, int n)
{
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			if (j == 0 || i == 0)
				t[i][j] = 0;
		}
	}

	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (x[i - 1] == y[j - 1] && i != j)
				// return LCS_TD(x,y,i-1,j-1);
				//i!=j EXTRA ADDED FOR REPEATNG SUBSEQUNCE.EXPLAINATION ON LAST.
				t[i][j] = 1 + t[i - 1][j - 1];
			else
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
		}
	}
	return t[m][n];
}


int32_t main()
{
	fast();
	memset(t, -1, sizeof(t));	//initialize whole matrix with -1.
	string x;
	cin >> x ;
	string y = x;
	int n = y.size();
	int m = x.size();
	cout << LCS_TD(x, y, m, n);
	return 0;
}


// input:
// abcdgh
// abedfhr

//EXAMPLE : x=y=AABEBCDD INDEX:0 TO 8
// in x A : 0 1
// in y A : 0 1
// take the A diagonally instead of i==j i.e {0,0 or 1,1}.