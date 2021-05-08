//brute force
class Solution {
public:
	//TC : O(n^3 logm) SC: O(n)
	vector<vector<int>> threeSum(vector<int>& arr, int target) {
		for (int i = 0; i < n - 2; i++)
		{
			for (int j = i + 1; j < n - 1; j++)
			{
				for (int k = j + 1; k < n; k++)
				{
					if (a[i] + a[j] + a[k] == target)
					{
						cout << "Triplet is" << a[i] << "," << a[j] << "," << a[k];
						return true;
					}
				}
			}
		}
		return false;
	}
};

class Solution {
public:
	struct Cmp
	{
		bool operator ()(const pair< pair<int, int>, double > &a, const pair< pair<int, int>, double >  &b)
		{
			return a.second < b.second;
		}
	};
	//TC : O(n^2 logm) SC: O(m+n)
	///logm for insertion time in set
	vector<vector<int>> threeSum(vector<int>& a, int target) {
		int n = a.size();
		unordered_map<int, int>mp;
		set<pair<pair<int, int>, int>, Cmp>st;
		// set<vector<int>>st;
		for (auto x : a)
			mp[x]++;
		for (int i = 0; i < n - 1; i++)
		{
			mp[a[i]]--;//no more of use
			for (int j = i + 1; j < n - 1; j++)
			{
				mp[a[j]]--;//no more of use
				//to find the remaining 3rd ele in array
				if (mp.find(-(a[i] + a[j])) != mp.end())
				{
					st.insert(make_pair(make_pair(a[j], -(a[i] + a[j])), a[i])); //put item in set in orderd like{-1,1,2};
				}
				mp[a[j]]++;//adding for next iteration
			}
			mp[a[i]]++;
		}
		return st;//it is wrong as o/p must be in 2d array
	}
};

//2 pointer
class Solution {
public:
	//TC : O(n^2 logm) SC: O(n)
	vector<vector<int>> threeSum(vector<int>& arr) {
		vector<vector<int>>ans;
		int n = arr.size();
		sort(arr.begin(), arr.end());
		//moved for x
		for (int i = 0; i < n - 2; i++)
		{
			//if first ele than except otherwise i>0 with no duplicacy accepted
			if (i == 0 or (i > 0 and arr[i] != arr[i - 1])) {
				int low = i + 1, high = n - 1, sum = 0 - arr[i];

				while (low < high) {
					if (arr[low] + arr[high] == sum) {
						vector<int>temp;
						temp.push_back(arr[i]);
						temp.push_back(arr[low]);
						temp.push_back(arr[high]);
						ans.push_back(temp);

						//to remove duplicates
						while (low < high and arr[low] == arr[low + 1]) low++;
						while (low < high and arr[high] == arr[high - 1]) high--;

						low++; high--;
					}
					else if (arr[low] + arr[high] < sum) low++;
					else high--;
				}
			}
		}
		return ans;
	}
};