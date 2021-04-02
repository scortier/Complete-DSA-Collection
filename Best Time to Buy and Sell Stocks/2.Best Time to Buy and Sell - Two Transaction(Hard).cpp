/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
BSBS allowed
bbss not allowed
 for day4 - we can buy

*/
#include<bits/stdc++.h>
using namespace std;



int32_t main()
{
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];

	int most_profit_Sofar = 0;
	int least_sofar = a[0];
	int mpsut[n];  //max pro_sold  upto today
	for (int i = 1; i < n; i++)
	{
		if (a[i] < leas_sofar)
			least_sofar = a[i];
	}


	most_profit_Sofar = a[i] - least_sofar;
	if (most_profit_Sofar > mpsut[i - 1])
		mpsut[i] = most_profit_Sofar;


	return 0;
}