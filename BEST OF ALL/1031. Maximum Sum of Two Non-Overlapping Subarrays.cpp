//https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/

//Approach 1 : Sliding window
/*
For each L length subarray,
find the best possible M length subarray that occurs before and after it.
- fixing the L and M sized window
1. Cal prefix Sum to get the sum.
2.

*/
class Solution {
public:
	int maxSumTwoNoOverlap(vector<int>& a, int l, int m) {
		//intial variables


		//cal prefix sum
		for (int i = 1; i < a.size(); i++)
			a[i] += a[i - 1];

		int result = a[l + m - 1], Lmax = a[l - 1], Mmax = a[m - 1];
		for (int i = l + m; i < a.size(); i++)
		{
			Lmax = max(Lmax, a[i - m] - a[i - (l + m)]);
			Mmax - max(Mmax, a[i - l] - a[i - (l + m)]);
			res = max(res, Lmax + a[i] - a[i - m], Mmax + a[i] - a[i - l]);
		}
		return res;
	}
};
//if we use vectro to store prefix sum then just take of index as a[0]will start from a[0]+a[1] not like a[0] in above .


//DP APPROACH
/*
Without loss of generality, consider M before L:

DP approach:
Let call:

sumL[i] is the sum of subarray length L and end in i so :
sumL[i] = A[i-L+1] +....+A[i] = sumL[i-1] + A[i] - A[i-L];
sumM is the same with sumL but length M.
dpM [i] is the largest sum subarray of length M in the segment 0 -> i, so :
dpM[i] = max (sumM[i], dpM [i-1]);
then for each position i the result can be sumL[i] + dpM [i-L]:
res = max(res, sumL[i] + dpM[i-L]);

Reduce memory:
We can combine all of DP function by using one loop for all of them, and you can see that the dpM[i] update from dpM[i-1], sumL[i] and sumM[i] also update from previous (sumL[i-1] and sumM[i-1]), so we can use one variable for each of those instead using vector.
*/
class Solution {
public:
	int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
		return max(help(A, L, M), help(A, M, L));
	}

	int help(vector<int>& A, int L, int M) {
		int n = A.size();
		int sMMax = 0;
		int sL = 0, sM = 0;
		int res = 0;
		for (int i = 0; i < n; i++) {
			sL += A[i];
			if (i >= L) {
				sL -= A[i - L];
				sM += A[i - L];
			}
			if (i - L >= M) {
				sM -= A[i - L - M];
			}
			sMMax = max(sMMax, sM);
			res = max(res, sL + sMMax);
		}

		return res;
	}
};