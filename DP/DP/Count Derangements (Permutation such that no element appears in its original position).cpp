/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;

//recursive
int countDer(int n)
{
	if (n == 1) return 0;
	if (n == 2) return 1;
	return (n - 1) * (countDer(n - 1) + countDer(n - 2));
}

//dp-bottom up
int cntDer_bottomUp(int n)
{
	int t[n + 1] = {0};

	t[1] = 0;
	t[2] = 1;

	for (int i = 3; i <= n; i++)
		t[i] = (i - 1) * (t[i - 1] + t[i - 2]);


	return t[n];
}





int32_t main()
{
	int n = 4;
	cout << countDer(n) << endl;
	cout << cntDer_bottomUp(n);
	return 0;
}