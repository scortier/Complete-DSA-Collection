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
#define pii 			pair < pair < ll, ll >, ll >
#define lower(str) 		transform(str.begin(), str.end(), str.begin(), ::tolower);
#define upper(str) 		transform(str.begin(), str.end(), str.begin(), ::toupper);
const int maxm = 2e6 + 10;

void fast() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
/**********====================########################=================***********/

class Graph {
	int V;	//no of vertex
	list<int> *adjlist; 	//array of link list of size V
public:
	Graph(int v) {		//constructor
		V = v;
		adjlist = new list <int>[V];
	}
	void addedge(int u, int v , bool bidirn = true)
	{
		adjlist[u].pb(v);
		if (bidirn) adjlist[v].pb(u);
	}
	void printadjlist() {
		for (int i = 0; i < V; i++)
		{
			cout << i << "-->";
			for (int node : adjlist[i]) {
				cout << node << ",";
			}
			cout << endl;
		}
	}
};


int main()
{
	fast();
	Graph g(4);
	g.addedge(0, 1);
	g.addedge(0, 2);
	g.addedge(0, 3);
	g.addedge(1, 3);
	g.addedge(3, 2);

	g.printadjlist();


	return 0;
}