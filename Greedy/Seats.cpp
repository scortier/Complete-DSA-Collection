/*
string :  .x..x..x.
positions where x are present {1, 4, 7}
Median is 4. So we will move all x near our median. 1st person would need to jump 2 steps and 3rd person would also need to jump 2 steps. Total answer = 4.

*/

int Solution::seats(string s) {
	int n = s.size();
	const int MOD = 10000003;
	vector<int>arr;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'x')
			arr.push_back(i);
	}
	if (arr.size() == 0) return 0;
	int mid = floor(arr.size() / 2);
	int cp = arr[floor(arr.size() / 2)]; //cp is median position index in the string A, all other
//members should be seated attached to cp.
//sum is number of jumps
	int sum = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		int start = arr[i];
		int end = cp - mid + i;

		sum = (sum + abs(end - start)) % MOD;
	}

	return sum;

}
