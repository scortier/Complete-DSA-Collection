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
//Template for generic graph any kind of data,ints,string,bool etc.
template<typename T>
class Graph {
	map<T, list<T> > adjlist;

public:
	Graph() {

	}
	//Assuming bidirectional graph
	void addedge(T u, T v, bool bidirn = true)
	{
		adjlist[u].pb(v);
		if (bidirn) adjlist[v].pb(u);

	}
	void printadjlist() {
		//iterate over maps as each key khud m ek link list hai.
		for (auto row : adjlist) {
			T key = row.first;
			cout << key << "-->";

			for (T element : row.second) //row.sec are the values for each corresponding key
			{
				cout << element << " ";
			}
			cout << endl;
		}
	}
};
int main()
{
	fast();
	//key are sorted in the map. Har ek key khud m link list hai.
	Graph <string>g;
	g.addedge("0", "1");
	g.addedge("0", "2");
	g.addedge("0", "3");
	g.addedge("1", "3");
	g.addedge("3", "2");

	g.printadjlist();


	return 0;
}
// FOR A WEIGHTED GRAPH :  map<T,list<pair<T,int>> //last int represent the weight.
//example :-  1-->(4,40) 1 is connected with 4 with weight 40.