//brute force
class Solution {
public:
	//TC : O(n^2 logm) SC: O(n)
	vector<vector<int>> threeSum(vector<int>& arr, int target) {
		int closest_sum = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				for (int k = j + 1; k < n; k++)
				{
					int sum = a[i] + a[j] + a[k];
					if (abs(target - closest_sum) > abs(target - sum))
					{
						closest_sum = sum;
					}
				}
			}
		}
		return closest_sum;
	}
};

//2 pointer technique
/*
sort
if less move forward
if more move backward
*/
class Solution {
public:
	int threeSumClosest(vector<int>& a, int target) {
		sort(a.begin(), a.end());
		int closest_sum = INT_MAX;
		for (int i = 0; i < a.size() - 2; i++)
		{
			int left = i + 1, right = a.size() - 1;

			while (left < right)
			{
				int curr_sum = a[i] + a[left] + a[right];
				if (abs(1LL * target - curr_sum) < abs(1LL * target - closest_sum))
					closest_sum = curr_sum;


				if (curr_sum > target)
					right--;
				else left++;
			}
		}

		return closest_sum;

	}
};