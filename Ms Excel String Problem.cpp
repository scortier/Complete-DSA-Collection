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

void printtString(int n)
{
	// string s;
	char s[500];
	int i = 0;
	int rem = n % 26;
	while (n)
	{
		if (rem == 0)
		{
			s[i++] = 'Z';
			n = (n / 26) - 1; // Z is at 25th wrt A
		}
		else
		{
			s[i++] = (rem - 1) + 'A';
			n = (n / 26);
		}
	}
	s[i] = '\0';
	// reverse(s.begin(), s.end());
	reverse(s, s + strlen(s));
	cout << s << endl;
	return;
}

//Easier Method
void printString(int n)
{
	int arr[10000];
	int i = 0;

	// Step 1: Converting to number assuming
	// 0 in number system
	while (n) {
		arr[i] = n % 26;
		n = n / 26;
		i++;
	}

	// Step 2: Getting rid of 0, as 0 is
	// not part of number system
	for (int j = 0; j < i - 1; j++) {
		if (arr[j] <= 0) {
			arr[j] += 26;
			arr[j + 1] = arr[j + 1] - 1;
		}
	}

	for (int j = i; j >= 0; j--) {
		if (arr[j] > 0)
			cout << char('A' + arr[j] - 1);
	}

	cout << endl;
}
void solve()
{
	printString(26);
	printString(51);
	printString(52);
	printString(80);
	printString(676);
	printString(702);
	printString(705);

}

int32_t main()
{
	lage_rho();
	solve();
	return 0;
}