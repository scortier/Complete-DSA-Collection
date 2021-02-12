#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;



#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>



#define ll long long

#define sg string

int mod(1000000007);

#define emb emplace_back

#define my_love ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

#define bug(x) cout<<#x<<" "<<x<<"\n"

#define f(i,k,n) for(ll i=k;i<=n;i++)


ll min(ll a, ll b)

{

    return (a <= b ? a : b);

}

ll max(ll a, ll b)

{

    return (a >= b ? a : b);

}

ll gd(ll a, ll b)

{

    if (b == 0)

        return a;

    return gd(b, a % b);

}

ll pwr(ll a, ll b)

{

    ll res = 0;

    while (b)

    {

        if (b % 2 == 1)

        {

            res *= a;

        }

        a = a * a;

        b >>= 1;

    }

    return res;

}


int main()

{

    my_love

    //freopen("input.txt", "r", stdin);

//  freopen("output.txt", "w", stdout);

    int t;

    cin >> t;

    while (t--)

    {

        int n, q, m;

        cin >> n >> q >> m;

        int a[n];

        for (int i = 0; i < n; i++)

            cin >> a[i];

        int b[1000001] = {};

        int ans[m + 1] = {};

        map<pair<int, int>, int>m1;

        while (q--)

        {

            int l, r;

            cin >> l >> r;

            l--, r--;

            if (a[l] > m)

                continue;

            else if (a[l] <= m && a[r] > m)

            {

                b[a[l]]++, b[m + 1]--;

            }

            else if (a[r] <= m)

            {

                b[a[l]]++, b[m + 1]--;

                m1[ {a[l], a[r]}]++;

            }

        }

        for (auto x : m1)

        {

            int k = x.first.first, p = x.first.second, l = x.second;

            b[p + k] -= l, b[p + 2 * k] += l;

            // m1[{a[l],a[r]}]++;

            int c = p + 2 * k;

            while (c + p <= m)

            {

                c += p;

                b[c] -= l, b[c + k] += l;

                c += k;

            }

        }

        for (int i = 1; i <= m; i++)

        {

            b[i] += b[i - 1];

            // ans[i]+=b[i];

        }

        int maxx = 0;

        for (int i = 0; i <= m; i++)

        {

            //  cout<<ans[i]<<" ";

            maxx = max(b[i], maxx);

        }

        cout << maxx << "\n";

    }

    return 0;

}