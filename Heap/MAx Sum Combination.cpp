//UNDERSTANDING THE APPROACH
/* We here use the concept of merging k - sorted linked lists.
Let the given vectors after sorting be
A : 16, 11, 7, 1
B : 15, 10, 9, 2

Now we know that 4 ^ 4 different sums are possible for this combination and we need to
find the largest C out of these. Let the pairs be:
(16,15), (16,10), (16,9), (16,2),
(11,15), (11,10), (11,9), (11,2),
(7,15), (7,10), (7,9), (7,2),
(1,15), (1,10), (1,9), (1,2),

Note that the numbers (pair of the sums) in every row are sorted in descending order. Now we
need to merge these sorted LinkedLists.
*/




//
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<int>res;
    priority_queue<tuple<int, int, int>>q;
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    for (int i = 0; i < C; i++) {
        q.push({A[i] + B[0], i, 0});
    }
    while (res.size() < C) {
        auto [sum, i, j] = q.top(); q.pop();
        res.push_back(sum);
        q.push({A[i] + B[j + 1], i, j + 1});
    }
    return res;
}