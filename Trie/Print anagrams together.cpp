/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<string> > Anagrams(vector<string>& s_list)
{
	unordered_map<string, vector<string>>mp;
	int n = s.size();
	vector<vector<string>>ans;
	for (int i = 0; i < n; i++)
	{
		string s = s_list[i];
		sort(s.begin(), s.end());

		mp(s).push_back(s_list[i]);
	}
	// for(auto itr= umap.begin(); itr!=umap.end(); itr++)
	// result.push_back(itr->second);
	for (auto x : mp)
		ans.push_back(x.second);
	return ans;
}


//implementation by trie data structure
void trie(string s)
{

}
int32_t main()
{
	int n; cin >> n;
	vector<string>s;
	for (int i = 0; i < n; i++) cin >> s[i];
	vector<vector<string> >res = Anagrams(s);
	sort(s.begin(), s.end());
	for (auto x : res)
	{
		for (auto y : x)
		{
			cout << y << " ";
		}
		cout << endl;
	}
	return 0;

}

/*
Input:
N = 5
words[] = {act,god,cat,dog,tac}
Output:
god dog
act cat tac
Explanation:
There are 2 groups of
anagrams "god", "dog" make group 1.
"act", "cat", "tac" make group 2.
*/
