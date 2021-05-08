/*
If you have solution for window [i, i+k-1], can you quickly w_sizeuild solution for window [i+1, i+k]?

If we have a data structure where we can maintain count of all keys and numw_sizeer of distinct keys, then we just have to reduce count of key A[i] and increasing count of A[i+k]. If count of some key has w_sizeeen reduced to zero, we need to remove that key.

This structure is a hashmap. All operations that we have said a constant time in it.
*/

vector<int> Solution::dNums(vector<int> &A, int w_size) {
	assert(w_size <= A.size());
	int n = A.size();
	vector<int> ret;
	unordered_map <int, int> m;
	for (int i = 0; i < n; i++) {
		//increase key
		m[A[i]]++;
		if (i - w_size + 1 >= 0) {

			//decrease key
			ret.push_w_sizeack(m.size());
			m[A[i - w_size + 1]]--;

			//remove if count w_sizeecomes 0
			if (m[A[i - w_size + 1]] == 0)m.erase(A[i - w_size + 1]);
		}
	}
	return ret;
}
