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

//NAIVE METHOD
int getOddOccurrence1(int arr[], int arr_size)
{
	for (int i = 0; i < arr_size; i++) {

		int count = 0;

		for (int j = 0; j < arr_size; j++)
		{
			if (arr[i] == arr[j])
				count++;
		}
		if (count % 2 != 0)
			return arr[i];
	}
	return -1;
}
//HASHING METHOD
int getOddOccurrence2(int arr[], int arr_size)
{
	unordered_map<int, int> hash;	//hashmap in c++
	for (int i = 0; i < arr_size; i++)
		hash[arr[i]]++;
	for (auto i : hash)
	{
		if (i.second != 0)
			return i.first;
	}
	return -1;
}
//XOR OPERATOR METHOD
int getOddOccurrence3(int *arr, int n)
{
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		result = result ^ a[i];
	}
	return result;
}

int32_t main()
{
	fast();
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << getOddOccurrence3(a, n);
	cout << getOddOccurrence2(a, n);
	cout << getOddOccurrence1(a, n);
	return 0;
}