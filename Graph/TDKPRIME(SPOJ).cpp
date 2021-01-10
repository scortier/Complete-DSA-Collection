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
vec primes;
int is_prime[90000001];

void sieve()
{
	int mod = 90000000;
	// for (int i = 1; i <= mod; i++) is_prime[i] = 1;
	is_prime[0] = is_prime[1] = 1;

	for (int i = 2; i * i <= mod; i++)
	{
		if (!is_prime[i])
		{
			for (int j = i * i; j <= mod; j += i)
				is_prime[j] = 1;
		}
	}

	for (int i = 2; i <= mod; i++)
		if (!is_prime[i])
			primes.pb(i);
}

int32_t main()
{	sieve();
	fast();
	test
	{
		int n; cin >> n;
		cout << primes[n - 1] << endl;

	}
	return 0;
}