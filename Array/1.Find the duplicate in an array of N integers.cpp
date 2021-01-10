// QUARANTINE DAYS..;)
#include <bits/stdc++.h>
using namespace std;
#define endl 		    "\n"
#define test 		    long long int tt;cin>>tt;while(tt--)
#define rep(i,a,b)      for(long long int i=a;i<b;i++)
#define rev(i,a,b)      for(long long int i=b-1;i>=a;i--)
#define reep(i,a,b)     for(long long int i=a;i<=b;i++)
#define ll 			    long long int
#define pb 			    push_back
#define mp 			    make_pair
#define f 			    first
#define s 			    second
#define MOD 		    1000000007
#define PI 			    acos(-1.0)
#define assign(x,val)   memset(x,val,sizeof(x))
#define prec(val, dig)  fixed << setprecision(dig) << val
#define vec 		    vector < ll >
#define vecpi	 	    vector < pair < ll, ll > >
#define pi 			    pair < ll , ll >
#define lower(str) 		transform(str.begin(), str.end(), str.begin(), ::tolower);
#define upper(str) 		transform(str.begin(), str.end(), str.begin(), ::toupper);
#define mk(arr,n,type)  type *arr=new type[n];
const int maxm = 2e6 + 10;

void fast() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
/**********====================########################=================***********/

void duplicate(int a[], int size)
{
	cout << "The repeating elements are:" << endl;
	for (int i = 0; i < size; i++)
	{
		if (a[abs(a[i])] >= 0)
			a[abs(a[i])] = -a[abs(a[i])];
		else
			cout << abs(a[i]) << " ";
	}

}

int32_t main()
{
	fast();
	int n; cin >> n;
	int a[n];
	rep(i, 0, n) cin >> a[i];
	duplicate(a, n);
	return 0;
}

// TC:O(N)
// SC:O(1)

/*
    https://leetcode.com/problems/find-the-duplicate-number/
*/
// class Solution {
// public:
//     // TC: O(N), SC: O(1)
//     /*
//         Since the numbers are [1:N], so we use the array indices for storing the
//         visited state of each number, only the duplicate will be visited twice.
//         For each number we goto its index position and multiply by -1. In case
//         of duplicate it will be multiplied twice and the number will be +ve.
//     */
//     // int indexSolution(vector<int>& nums) {
//     //     for(int i = 0; i < nums.size(); i++) {
//     //         int index = abs(nums[i]) - 1;

//     //         // mark as visited
//     //         nums[index] *= -1;
//     //         // incase of duplicate, this will become +ve
//     //         if(nums[index] > 0)
//     //             return abs(nums[i]);
//     //     }
//     //     return -1;
//     // }

//     // Using Floyd Cycle detection
//     // TC: O(N), SC: O(1)

//     /*
//         Assume each nums value as an address just like in linked list node addr.
//         Then since there is one number whith duplicates, that means there are multiple instances
//         of the same address, so it is a cycle just like in linked list. Do the same thing
//         as in linked list.
//     */
//     // int floydSolution(vector<int>& nums) {
//     //     // Each index is taken 1 based, as if it is zero based, then
//     //     // for nums[2] = 3, if we goto nums[nums[2] - 1], it is again nums[2]
//     //     // infinite loop
//     //     int hare = nums[0], tortoise = nums[0];

//     //     do {
//     //         hare = nums[nums[hare]];
//     //         tortoise = nums[tortoise];
//     //     } while(hare != tortoise);

//     //     // to find the starting of cycle, make tortoise to start from begining
//     //     tortoise = nums[0];
//     //     while(hare != tortoise) {
//     //         hare = nums[hare];
//     //         tortoise = nums[tortoise];
//     //     }

//     //     return hare;
//     // }

//     // Using Binary search
//     // TC: O(nlogn), SC: O(1)
//     // int binarySearchSolution(vector<int>& nums) {
//     //     // The idea is that it is known that there is a duplicate, so
//     //     // we can use pigeon hole concept here. We do binary search on the search
//     //     // space of [1:N], then count the number of elements <= middle. If the
//     //     // duplicate is on the left side, then count should be more than mid,
//     //     // else it is on the right side. Initially search space is [1: N], then
//     //     // each time narrow down the search space
//     //     int left = 1, right = nums.size() - 1;
//     //     while(left < right) {
//     //         int mid = left + (right - left) / 2;

//     //         // count the number of elements smaller/ equal than middle element
//     //         int c = 0;
//     //         for(const int& el: nums)
//     //             if(el <= mid)
//     //                 ++c;

//     //         if(c > mid)
//     //             right = mid;
//     //         else
//     //             left = mid + 1;
//     //     }
//     //     return left;
//     // }

//     // Using Sorting
//     // TC: O(nlogn)
//     // int sortingSolution(vector<int>& nums) {
//     //     // sort the numbers and find the number which has duplicate
//     //     // by checking the one which has the same at next position
//     //     sort(nums.begin(), nums.end());

//     //     int duplicate = 0;
//     //     for(int i = 0; i < nums.size() - 1; i++)
//     //         if(nums[i] == nums[i+1]) {
//     //             duplicate = nums[i];
//     //             break;
//     //         }
//     //     return duplicate;
//     // }



//     int findDuplicate(vector<int>& nums) {
//         // return sortingSolution(nums);
//         // return binarySearchSolution(nums);
//         //return floydSolution(nums);
//         return indexSolution(nums);
//     }
// };