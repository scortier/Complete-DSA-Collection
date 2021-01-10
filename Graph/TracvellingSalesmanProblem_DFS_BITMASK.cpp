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
#define fi 			    first
#define se 			    second
#define MOD 		    1000000007
#define PI 			    acos(-1.0)
#define assign(x,val)   memset(x,val,sizeof(x))
#define prec(val, dig)  fixed << setprecision(dig) << val
#define vec(vct) 	    vector < ll > vct
#define vecpi(vct) 	    vector < pair < ll, ll > > vct
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

int n = 4; //adjacency matrix
int dist[10][10] = {
	{0, 20, 42, 25},
	{20, 0, 30, 34},
	{42, 30, 0, 10},
	{25, 34, 10, 0}
};
int VISITED_ALL = (1 << n) - 1; //2^n-1
//mask-> set of visited cities so far. pos->current city index.
int tsp(int mask, int pos) {
//base case
	if (mask == VISITED_ALL)
		return dist[pos][0];
	//from curr node go to evey other node
	int ans = INT_MAX;
	//visit all the unvisited city n take best route
	rep(city, 0, n) {
		//check unset bit
		if ((mask & (1 << city)) == 0) {
			int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
			ans = min(ans, newAns);
		}
	}
	return ans;
}

int32_t main()
{
	fast();
	cout << "Travelling Salesman Path is " << tsp(1, 0); //mask m 1 stands for visited
	return 0;
}