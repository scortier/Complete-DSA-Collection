// QUARANTINE DAYS..;)
// Calculating the BFS output
//and Distance of the mode from the parent node.
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
		adjlist = new list <int>[V]; //link list..
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



	void bfs(int src)
	{
		queue<int> q;
		bool*visit = new bool[V + 1] {0}; //intitially no visited node
		int *dist = new int[V + 1] {0}; //intitially all distances are zero
		int *parents = new int[V + 1];

		for (int i = 0.; i < V; i++) { parents[i] = -1;}
		//src ka parents koi nhi hai

		q.push(src); //pushing the starting node in queue.(obviously from the back)
		visit[src] = true; //its visit value assign to true.
		while (!q.empty()) //Tab tak chalao jab tak queue empty nhi ho jaata.
		{
			int node = q.front(); //sabse aage wale element ko node naam diya
			cout << node << " ";
			q.pop();  //sabse front wale ko pop kiya.

			for (int neighbour : adjlist[node])
			{
				if (!visit[neighbour]) {	//node k adj nodes par agr vidit nhi hue ho toh.
					q.push(neighbour); //use neighbour ko queue m push karo
					visit[neighbour] = true;
					dist[neighbour] = dist[node] + 1; //neighbour k parent node se +1 dist hogi starting se.
					parents[neighbour] = node;
				}
			}
		}
		cout << endl;


		//distance of every node from the src.
		for (int i = 0; i < V; i++) {
			cout << i << " " << "node having the distance == " << dist[i] << endl;
		}
// cout << "THe Shortes path between the node" << dist[dest];
// cout << "Shortest path is this";
// int temp = dest;
// while (temp != -1)
// {
// 	cout << temp << "<--";
// 	temp = parent[temp];
// }

	}
};


int main()
{
	fast();
	Graph g(6); //as there are 6 vertices iin a graph
	g.addedge(0, 1);
	g.addedge(0, 4);
	g.addedge(1, 2);
	g.addedge(2, 4);
	g.addedge(2, 3);
	g.addedge(3, 4);
	g.addedge(3, 5);

	//g.printadjlist();
	g.bfs(0);
	return 0;
}