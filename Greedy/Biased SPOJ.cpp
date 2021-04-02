/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
counting sort
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int




int32_t main()
{
	int a[100000] = {0};
	int t;
	cin >> t;
	while (t--)
	{
		memset(a, 0, sizeof(a));
		string name;
		int n, rank;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> name >> rank;
			a[rank]++;
		}


		//Greedy approach - assign the team nearest rank available
		int actual_rank = 1;
		int sum = 0;
		for (int i = 1; i <= n; i++) //every bucket
		{
			while (a[i]) {
				sum += abs(actual_rank - i);
				a[i]--;//removing team
				actual_rank++;
			}
		}
		cout << sum << endl;

	}
	return 0;
}