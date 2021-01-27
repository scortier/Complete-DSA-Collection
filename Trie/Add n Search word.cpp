/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
Implement dictionary with '.' as skip character.
*/
#include<bits/stdc++.h>
using namespace std;

class WordDictionary {
	struct Trienode
	{
		char c;//for debugging
		int end;//
		Trienode *child[26];
	};

	Trienode *NewNode(char data)
	{
		Trienode *temp = root;
		temp->c = data;
		temp->end = 0;
		for (inti = 0; i < 26; i++)
			temp->child[i] = NULL;
		return temp;
	}
	Trienode *root = NewNode('/');

	void insert(string s)
	{
		int index; int i = 0;
		Trienode *temp = root;
		while (s[i])
		{
			index = s[i] - 'a';
			if (!temp->child[index])
				temp->child[index] = NewNode(s[i]);
			temp = temp->child[temp];
			++i;
		}
		temp->end += 1;
	}

	bool Trie_search(string s, node *curr, int pos, int n)
	{
		if (s[pos] == '.')
		{
			bool res = false;
			node *current = curr;
			for (int i = 0; i < 26; ++i)
			{
				if (pos == n - 1 && curr->child[i])
				{
					current = curr->child[i];
					res |= current->end > 0 ? true : false;
				}
				else if (curr->child[i] && Trie_search(s, curr->child[i], pos + 1, n))
					return true;
			}
			return res;
		}
		else if (curr->child[s[pos] - 'a'])
		{
			if (pos == n - 1)
			{
				curr = curr->child[s[pos] - 'a'];
				return curr->end > 0 ? true : false;
			}
			return Trie_search(s, curr->child[s[pos] - 'a'], pos + 1, n);
		}
		return false;
	}
public:
	/** Initialize your data structure here. */
	WordDictionary() {
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		Trie_insert(word);
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return Trie_search(word, root, 0, word.size());
	}
};

static const auto io_sync_off = []()
{
	// turn off sync
	std::ios::sync_with_stdio(false);
	// untie in/out streams
	std::cin.tie(nullptr);
	return nullptr;
}();
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int32_t main()
{

	return 0;
}