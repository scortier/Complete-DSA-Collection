/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;

struct item
{
	int value, weight;
	item(int val, int wei)
	{
		this->value = val;
		this->weight = wei;
	}
};

bool comp(struct item a, struct item b)
{
	double r1 = (double)a.value / (double)a.weight;
	double r2 = (double)b.value / (double)b.weight;

	return r1 > r2;
}
int fract_knap(int W, struct item a[], int n)
{
	sort(a, a + n, comp);
//    Uncomment to see new order of Items with their
	//    ratio
	/*
	for (int i = 0; i < n; i++)
	{
	    cout << arr[i].value << "  " << arr[i].weight << " :
	"
	         << ((double)arr[i].value / arr[i].weight) <<
	endl;
	}
	*/
	int curr_wei = 0;
	double finalval = 0.0;
	for (int i = 0; i < n; i++)
	{
		// If adding Item won't overflow, add it completely
		if (curr_wei + a[i].weight <= W)
		{
			curr_wei += a[i].weight;
			finalval += a[i].value;
		}
		// If we can't add current Item, add fractional part
		// of it
		else
		{
			int remain = W - curr_wei;
			finalval += a[i].value * ((double)remain / (double)a[i].weight);
			break;
		}
	}
	return finalval;
}
int main()
{
	int W = 50; //    Weight of knapsack
	item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };

	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << "Maximum value we can obtain = "
	     << fract_knap(W, arr, n);
	return 0;
}