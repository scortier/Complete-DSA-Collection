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
#define pi 			    pair < int , int >
#define pr(gg)          cout<<gg<<endl
#define mk(arr,n,type)  type *arr=new type[n];

void lage_rho() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
/**********=============########################============***********/
//brute force
string removeDuplicates(string s, int k) {
	for (auto i = 1, cnt = 1; i < s.size(); ++i) {
		if (s[i] != s[i - 1]) cnt = 1;
		else if (++cnt == k)
			return removeDuplicates(s.substr(0, i - k + 1) + s.substr(i + 1), k);
	}
	return s;
}
//two pointer
string remove(string s, int k)
{
	int j = 0;
	vector<int> cnt(s.size());
	for (int i = 0; i < s.size(); ++i, ++j) {
		s[j] = s[i];
		if (j > 0 && s[j] == s[j - 1]) cnt[j] = cnt[j - 1] + 1;
		else cnt[j] = 1;
		if (cnt[j] == k) j -= k;
	}
	return s.substr(0, j);

}

//Time: O(n). We process each character in the input string once.
//Memory: O(n) to track the running count for each character.

//Approach 3: Stack
// string removeDuplicates(string s, int k) {
// 	vector<pair<char, short>> st;
// 	string res;
// 	for (auto ch : s) {
// 		if (st.empty() || st.back().first != ch) st.push_back({ ch, 0 });
// 		if (++st.back().second == k) st.pop_back();
// 	}
// 	for (auto& p : st) res += string(p.second, p.first);
// 	return res;
// }
string emoveDuplicates(string s, int k) {
	vector<pair<int, char>> stack = {{0, '#'}};
	for (char c : s) {
		if (stack.back().second != c) {
			stack.push_back({1, c});
		} else if (++stack.back().first == k)
			stack.pop_back();
	}
	string res;
	for (auto & p : stack) {
		res.append(p.first, p.second);
	}
	return res;
}
void solve()
{
	int k; cin >> k;
	string s;
	cin >> s;
	cout << remove(s, k);

}

int32_t main()
{
	lage_rho();
	// test
	solve();
	return 0;
}


//wrong method
// int n = s.size();

// int st = 0;
// fl(i, 0, n)
// {
// 	st = i - 1;
// 	if (s[i] == s[i - 1])
// 		while (s[i] == s[i - 1])
// 		{
// 			if (i - (st - 1) == k)
// 			{
// 				s.erase(st, k);
// 			}
// 			i++;
// 		}
// 	else i++;
// }
// cout << s;