// Problem: Another Tree with Number Theory
// Contest: CodeChef - February Challenge 2021 Division 3
// URL: https://www.codechef.com/FEB21C/problems/ATWNT
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

//Handle: Scortier (Aditya Singh Sisodiya)
#include "bits/stdc++.h"
using namespace std;
#define test(t) int t;cin>>t;while(t--)
#define nl "\n"
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define all(v) (v).begin(),(v).end()
#define clr(v) memset(v,0,sizeof(v));
#define sqr(x)((x)*(x))
#define pr(x) cout << ((x)) << "\n";
typedef int ll;
typedef vector<int> vi;
typedef vector<long long int> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
typedef vector<pair<ll, ll>> vpll;
const long long int inf = 1e18;
const long long int mod = 1e9 + 7;
const long long int MOD =  998244353;

struct hashing {
	static uint64_t splitmix64(uint64_t x)
	{
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	size_t operator()(uint64_t x)const
	{
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

void lage_rho() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
/**********=============########################============***********/

ll n;
vector<vi>tree;
vi seesee;
vector<unordered_map<ll, ll, hashing>>store;
vi shreeshree;
vector<set<pll>>bakwass;
void chaining(ll nd)
{
	shreeshree[nd] = nd;
	for (auto &child : tree[nd])
	{
		chaining(child);
		if (seesee[nd] == 1)
			shreeshree[nd] = shreeshree[child];
	}
}
void dfs(ll nd)
{
	for (auto &to : tree[nd])
	{
		ll c = to;
		if (seesee[nd] == 1)
			c = shreeshree[nd];
		if (seesee[c] == 0)
		{
			store[nd][seesee[nd]]++;
			store[c][1]++;
			continue;
		}
		dfs(c);
		for (auto &it : store[c])
		{
			store[nd][seesee[nd] * 1ll * it.first] += it.second;
		}
	}
}
int main()
{
	lage_rho();
	cin >> n;
	tree.resize(n + 1);
	seesee.resize(n + 1, 0);
	store.resize(n + 1);
	shreeshree.resize(n + 1);
	bakwass.resize(n + 1);
	for (int i = 2; i <= n; ++i)
	{
		ll x;
		cin >> x;
		tree[x].emplace_back(i);
		seesee[x]++;
	}
	chaining(1);
	dfs(1);
	test(q)
	{
		ll nd, w;
		cin >> nd >> w;
		nd = shreeshree[nd];
		auto itr = bakwass[nd].lower_bound(pll {w, -1});
		if (itr != bakwass[nd].end() and itr->first == w)
		{
			pr(itr->second); continue;
		}
		ll p = 0ll;
		for (auto &i : store[nd])
		{
			if (i.first and w % i.first == 0)
			{
				p += (w / i.first) * i.second * 1ll;
			}
		}
		bakwass[nd].insert(pll {w, w - p});
		pr(w - p);
	}
	return 0;
}
