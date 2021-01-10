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

void fast() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
}
/**********====================########################=================***********/

//1.count the no of 0 n print them from 0 to cnt. then print 1
//2.


int separate(int a[], int n)
{
	int l = 0; int h = n - 1;
	while (l < h)
	{
		if (a[l] == 1)
		{
			swap(a[l], a[h]);
			h--;
		}
		else
			l++;
	}

}

//3.two index method

int separate(int a[], int n)
{
	int l = 0; int h = n - 1;
	while (l < h)
	{
		while ((a[l] == 0) && (l < h)) l++;
		while ((a[h] == 1) && (h > l)) r--;
		if (l < h)
		{
			a[l++] = 0;
			a[h--] = 1;
		}
	}

}

int32_t main()
{
	fast();

	return 0;
}