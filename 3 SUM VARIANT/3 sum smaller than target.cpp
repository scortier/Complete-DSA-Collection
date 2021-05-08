/*
Question:
Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
For example, given nums = [-2, 0, 1, 3], and target = 2.
Return 2. Because there are two triplets which sums are less than 2:
[-2, 0, 1]
[-2, 0, 3]
*/

//brute
class Solution {
public:
	//TC : O(n^3) SC: O(n)
	vector<vector<int>> threeSum(vector<int>& a, int target) {
		int n = a.size();
		if (n < 3) return 0;
		int ans = 0;

		// Fix the first element as A[i]
		for (int i = 0; i < n - 2; i++)
		{
			// Fix the second element as A[j]
			for (int j = i + 1; j < n - 1; j++)
			{
				// Now look for the third number
				for (int k = j + 1; k < n; k++)
					if (arr[i] + arr[j] + arr[k] < sum)
						ans++;
			}
		}

		return ans;
	}
};

//brute force
class Solution {
public:
	//TC : O(n^2) SC: O(n)
	vector<vector<int>> threeSum(vector<int>& a, int target) {
		int n = a.size();
		if (n < 3) return 0;
		sort(a.begin(), a.end());
		int cnt = 0;
		for (int i = 0; i < n - 2; i++)
		{
			int j = i + 1; k = n - 1;
			while (j < k) {
				if (a[i] + a[j] + a[k] < target)
				{
					cnt += (k - j);
					j++;
				}
				else {
					k--;
				}
			}
		}
		return cnt;
	}
};

