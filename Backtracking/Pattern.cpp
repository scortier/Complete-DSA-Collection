Intuition: Since we are asked to calculate all the possible permutations, hence we will use backtracking , accepting the cases which satisfy cases and reject the others.

Concept: In every backtracking problem , there are two things to keep in mind , which we will explore here as well :

Base Case: Every problem of backtracking has some base case which tells us at which point we have to stop with the recursion process. In our case, when the size of our temporary vector v becomes equal to size of nums i.e. v.size()=nums.size(), we stop with the recursion for that combination.

        Conditions : There is just one thing to keep in mind here :
After generating permutations corresponding to a particular nums[i] , pop the element as it has been used already.

//https://leetcode.com/discuss/interview-question/1141947/backtracking-study-and-analysis


class Solution {
public:
	vector<vector<string>>ans; //isme final ans store karenge

	void util(int index, vector<int>&temp, req chize)
	{
		//base case or jaha par recursion last leafse backtrack karega or where recursion will stop
		if (index == temp.size())
		{
			ans.push_back(temp);
			return;
		}

		for (int i = index; i < nums.size(); i++)
		{
			here either swap / boolean check / vector push_back
			util(index + 1, temp, ...);
			agr vector hi hai toh fir pop_back
		}
	}



	vector<vector<string>> ques(given vector) {
		vector<string>
		util(board, n, 0);
		return ans;
	}
};



//example
//https://leetcode.com/problems/subsets-ii/
class Solution {
public:
	vector<vector<int>>ans;
	void util(int index, vector<int>&temp, vector<int>&nums)
	{
		// if(index==nums.size())
		ans.push_back(temp);

		for (int i = index; i < nums.size(); i++)
		{
			if (i != index and nums[i] == nums[i - 1]) continue; //to remove duplicacy
//add the curr ele to consider the subset corresponding to it.
			temp.push_back(nums[i]);
			util(i + 1, temp, nums); //for next iteration
			temp.pop_back(); //to use it another recusrse tree while caling back
		}

	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int>temp;
		util(0, temp, nums);
		return ans;
	}
};