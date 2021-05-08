/*
BRUTE FORCE
Input arrays are sorted so try to pick all the array first element and push the minimum to output ,push the next element of the array which contained the minimum element.

Think of data structure which can maintain the minimum all the way along.

*/




/*
An efficient solution is to use heap data structure. The time complexity of heap based solution is O(N Log k). where N is count of all elements

Create an output array.
Create a min heap of size k and insert 1st element in all the arrays into the heap
Repeat following steps while priority queue is not empty.
Remove minimum element from heap (minimum is always at root) and store it in output array.
Insert next element from the array from which the element is extracted. If the array doesn’t have any more elements, then do nothing.

*/
vector<int> Solution::solve(vector<vector<int> > &a) {

    int r = a.size(), c = a[0].size();
    priority_queue<int, vector<int>, greater<int>>pq;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            pq.push(a[i][j]);
        }
    }
    vector<int>ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;

}
