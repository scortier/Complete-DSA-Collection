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

void reverse(string s)
{
	stack<char>st;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
			st.push(s[i]);

		// When we see a space, we print contents
		// of stack.
		else {
			while (st.empty() == false) {
				cout << st.top();
				st.pop();
			}
			cout << " ";
		}
	}
	// Since there may not be space after
	// last word.
	while (st.empty() == false) {
		cout << st.top();
		st.pop();
	}


}
void solve()
{
	string s = "Geeks for Geeks";
	reverse(s);

}

int32_t main()
{
	lage_rho();
	solve();
	return 0;
}