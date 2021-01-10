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
//JO PEHLE JYADA BAAR OCCUR KAREGA UUSE PRINT KIYA HAI.

#define SIZE 256
void repeat(string s)
{	int max = INT_MIN; char res;
	int cnt[SIZE] = {0};
	for (int i = 0; i < s.size(); i++)
	{
		cnt[s[i]]++;
		if (max < cnt[s[i]])
		{
			max = cnt[s[i]];
			res = s[i];
		}
	}
	cout << max << res;

}
void solve()
{
	string s; cin >> s;
	repeat(s);

}

int32_t main()
{
	lage_rho();
	// test
	solve();
	return 0;
}