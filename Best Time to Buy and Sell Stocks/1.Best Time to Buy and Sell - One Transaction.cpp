/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
aaj fayda kse hoga , simply go to min pt before selling today and find out profit and it
goes on for every day.

suppose aaj bechana mandatory hai toh tum bologe mujhe time machine dedo pice jaake dekhlunga
lowest price kab tha fir us din kharid k aaj bech dunga simpuul.
*/
#include<bits/stdc++.h>
using namespace std;


int32_t main()
{
	int n; cin >> n;
	int prices[n];
	for (int i = 0; i < n; i++) cin >> prices[i];

	int least_sofar = 0;
	int overall_profit = 0;
	int pit = 0; //profit_ifsold_today

	for (int i = 0; i < n; i++)
	{
		least_sofar = min(least_sofar, prices[i]);

		pit = prices[i] - least_sofar;
		if (pit < overall_profit)
		{
			overall_profit = pit;
		}
	}
	cout << overall_profit << endl;

	return 0;
}