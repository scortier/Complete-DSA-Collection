//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

class Solution {
public:
	string removeDuplicates(string s, int k) {
		//pair<character,count>
		vector<pair<char, int>> v;
		string res;

		for (auto ch : s) {

			if (v.empty() or v.back().first != ch)
				v.push_back({ ch, 0 });
			if (++v.back().second == k)
				v.pop_back();
		}
		for (auto p : v)
			res.append(p.second, p.first);
		return res;
	}
};



string removeDuplicates(string s, int k, bool replaced = true) {
	while (replaced) {
		replaced = false;
		for (auto i = 1, cnt = 1; i < s.size() && !replaced; ++i) {
			if (s[i] != s[i - 1]) cnt = 1;
			else if (++cnt == k) {
				s = s.substr(0, i - k + 1) + s.substr(i + 1);
				replaced = true;
			}
		}
	}
	return s;
}

/*
Complexity Analysis
Time: O(n * n / k). We scan the entire string for each duplicte we find and remove.
Memory :

O(n * n / k) for the recursive approach.
	O(1) for the iterative approach.
Approach 2 : Two pointers
*/

string removeDuplicates(string s, int k) {
	auto j = 0;
	vector<int> cnt(s.size(), 1);
	for (auto i = 0; i < s.size(); ++i, ++j) {
		s[j] = s[i];
		if (j > 0 && s[j] == s[j - 1]) cnt[j] = cnt[j - 1] + 1;
		else cnt[j] = 1;
		if (cnt[j] == k) j -= k;
	}
	return s.substr(0, j);
}


/*
Complexity Analysis
Time: O(n). We process each character in the input string once.
Memory: O(n) to track the running count for each character.
*/