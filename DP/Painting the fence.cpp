/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
SPACE OPTIMIZATION APPROACH
For n=5 and k=3 (r g b)
There are two possibility semen difference and the total equals to same plus difference for n equals to one there will be no such scenario.
For n=2  for the same total possibility will be k  and for the difference total possibility will be k*(k-1).
Now for n=3  for the same possibility we can use the difference of n equals to 2 which will be same as we have to just at the same colour which was used in the last fans of the and equals to 2 so if the possibility is 6 and the n equal to 2 so it will be the same for and equals to 3 in same.
While for the diff  use the total for previous fans just x (k-1) . if previous Hotel was 9 so current difference will be 9*2=18. and further on it goes on.

*/
#include<bits/stdc++.h>
using namespace std;

//Return count of ways to color k posts
long countWay(int n, int k)
{
	long t[n + 1];
	memset(t, -1, sizeof(t));
	long long mod = 10e+7;

	t[1] = k;
	t[2] = k * k;

	for (int i = 3; i <= n; i++)
	{
		t[i] = ((k - 1) * (t[i - 1] + t[i - 2])) % mod;
	}
	return t[n];
}

/*
Space optimization :
We can optimize the above solution to use one variable instead of a table.
*/
long countWay_optimize(int n, int k)
{
	long total = k;
	int mod = 10e+7;

	// There are 0 ways for single post to
	// violate (same color_ and k ways to
	// not violate (different color)
	int same = 0, diff = k;

	// Fill for 2 posts onwards
	for (int i = 2; i <= n; i++) {
		// Current same is same as previous diff
		same = diff;

		// We always have k-1 choices for next post
		diff = total * (k - 1);
		diff = diff % mod;

		// Total choices till i.
		total = (same + diff) % mod;
	}

	return total;
}
//Sumeet malik method
//to get more explaination refer video or try to form matrix
int cnt_Way(int n, int k)
{
	long same = k * 1;
	long diff = k * (k - 1);
	long total = same + diff;

	for (int i = 3; i <= n; i++)
	{
		same = diff * 1;
		diff = total * (k - 1);
		total = same + diff;
	}
	return total;

}

int32_t main()
{
	int n = 3, k = 2;
	cout << countWay(n, k) << endl;
	return 0;
}