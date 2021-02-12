/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*>mp;
        Node* ptr = head;
        while (ptr != NULL) //A->B->C => A->A`->B->B`->C->C`
        {
            mp[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr != NULL)
        {
            mp[ptr]->next = mp[ptr->next];
            mp[ptr]->random = mp[ptr->random];
            ptr = ptr->next;
        }
        return mp[head];
    }
};


//ALTERNATE SOLUTION WITHOUT MAP
Node* copyRandom(Node* head)
{
    Node* copy_head = NULL, copy_tail = NULL;
    Node* next_ptr = NULL;

    //add the copy to the original link list
    Node* temp = head;
    while (temp)
    {
        Node* node = new Node(temp->val);
        next_ptr = temp->next;
        temp->next = node; //A->A` A` is node
        next_ptr = node->next; //A`->next
        temp = next_ptr;
    }
    temp = head;
    while (temp)
    {   //set the random ptr of cloned node
        (temp->next)->random = temp->random ? (temp->random)->next : NULL;
        //next node
        temp = temp->next->next;
    }

    temp = head;

    //remove the cloned list
    while (temp)
    {
        //remove the cloned node
        //when curr is the head of cloned list
        if (!copy_head)
        {
            copy_head = temp->next;
            copy_tail = copy_head;
        }
        else
        {

        }
    }
}








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



#include <vector>

#include<cstdio>

using namespace std;

#define int long long

const int MaxN = 1 << 19, M = 998244353;

int mod = 998244353;

int ws[MaxN];

int inverse_factorial[500005];

int book_keeping[500005];

int factorial[500005];

int gpa[1 << 19], gpb[1 << 19];

long long binpow(long long a, long long b = mod - 2, long long m = mod) {

    a %= m;

    long long res = 1;

    while (b > 0) {

        if (b & 1)

            res = res * a % m;

        a = a * a % m;

        b >>= 1;

    }

    return res;

}

void fourier(int *a, int n, int f = 0) {

    int i, j, k, m, u, v, w, wm;

    for (i = n >> 1, j = 1, k; j < n - 1; j++) {

        if (i > j)swap(a[i], a[j]);

        for (k = n >> 1; k <= i; k >>= 1)i ^= k; i ^= k;

    }

    for (m = 2; m <= n; m <<= 1)

        for (i = 0, wm = binpow(3, f == 1 ? (M - 1) / m : (M - 1) / m * (m - 1), M); i < n; i += m)

            for (j = i, w = 1; j < i + (m >> 1); j++) {

                u = a[j], v = 1ll * w * a[j + (m >> 1)] % M;

                if ((a[j] = u + v) >= M)a[j] -= M;

                if ((a[j + (m >> 1)] = u - v) < 0)a[j + (m >> 1)] += M;

                w = 1ll * w * wm % M;

            }

    if (f == 1)for (w = binpow(n, M - 2, M), i = 0; i < n; i++)a[i] = 1ll * a[i] * w % M;

}


vector<int> mul(vector<int> arr, vector<int> brr) {

    int n_a = arr.size() - 1;

    int n_b = brr.size() - 1;

    int n_final = 1;

    while (n_final <= n_a + n_b)n_final *= 2;

    int i = 0;

    while (i < n_final) {

        gpa[i] = i <= n_a ? arr[i] : 0;

        i++;

    }

    i = 0;

    while (i < n_final) {

        gpb[i] = i <= n_b ? brr[i] : 0;

        i++;

    }

    fourier(gpb, n_final);

    fourier(gpa, n_final);

    i = 0;

    while (i < n_final) {

        gpa[i] = gpa[i] * gpb[i] % M;

        i++;

    }

    fourier(gpa, n_final, 1);

    vector<int> c;

    i = 0;

    while (i <= (n_a + n_b)) {

        c.push_back(gpa[i]);

        i++;

    }

    return c;

}

int nCr(int n, int r) {

    if (r > n)return 0;

    return (((inverse_factorial[r] * inverse_factorial[n - r]) % mod) * factorial[n]) % mod;

}

void prepare() {

    inverse_factorial[1] = inverse_factorial[0] = 1;

    book_keeping[1] = book_keeping[0] = 1;

    factorial[1] = factorial[0] = 1;

    for (int i = 2; i < 200005; i++) {

        book_keeping[i] = book_keeping[mod % i] * (mod - mod / i) % mod;

    }

    for (int i = 2; i < 200005; i++) {

        factorial[i] = (factorial[i - 1] * i) % mod;

    }

    for (int i = 2; i < 200005; i++) {

        inverse_factorial[i] = (book_keeping[i] * inverse_factorial[i - 1]) % mod;

    }

}

signed main() {

    prepare();

    int n;

    scanf("%lld", &n);

    vector<int> arr(n);

    vector<int> book_keeping(30);

    for (int i = 0; i < n; i++) {

        scanf("%lld", &arr[i]);

    }

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < 30; j++) {

            if (arr[i] & (1 << j)) {

                book_keeping[j]++;

            }

        }

    }

    vector<int> sol(n + 1);

    for (int ii = 0; ii < 30; ii++) {

        vector<int> eno = {0};

        vector<int> orez = {1};

        for (int i = 1; i <= book_keeping[ii]; i += 2) {

            eno.push_back(nCr(book_keeping[ii], i));

            eno.push_back(0);

        }

        int i = 1;

        while (i <= (n - book_keeping[ii])) {

            orez.push_back(nCr(n - book_keeping[ii], i));;

            i++;

        }

        auto gotit = mul(eno, orez);

        i = 0;

        while (i <= n) {

            sol[i] = (sol[i] + ((1 << ii) * gotit[i])) % mod;;

            i++;

        }

    }

    int i = 1;

    while (i <= n) {

        sol[i] += sol[i - 1];

        sol[i] %= mod;

        i++;

    }

    int q;

    scanf("%lld", &q);

    while (q--) {

        int g;

        scanf("%lld", &g);

        printf("%lld\n", sol[g]);

    }

}