/*
IMPORTANT :
Suppose for the phone directory
If we have to store the 1000 contacts -
Hashmap is preferred as less collision and trie rquire large complexity

But for 1,00,000 contacts -
Trie will be better option as hashmap will have large collision.



https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/tries-78733022/submissions/

Tries are an extremely special and useful data-structure that are based on the
prefix of a string. They are used to represent the “Retrieval” of data and thus
 the name Trie.
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;
#define ALPHABET_SIZE 26

struct TrieNode {
	TrieNode *children[ALPHABET_SIZE];
	int word_count; //bool isEndofWord;
};

TrieNode *newTrieNode()
{
	TrieNode* temp = new TrieNode;

	temp->word_count = 0; //isEndofWord=false;
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		temp->children[i] = NULL;
	}
	return temp;
}

//INSERTION OF STRING INTO TRIE
void insert(TrieNode* root, string s)
{
	TrieNode* temp = root;
	// for (auto x : s)
	for (int i = 0; i < s.size(); i++)
	{
		// int indx = x - 'a';
		int indx = s[i] - 'a';	// for finding the Trienode in the root
		//agr parent root ka vo indx ka Trienode khali hai toh uus index se naya trie aage bna do
		if (temp->children[indx] == NULL ) //if(child Trienode belonging to temprent char is null)
		{
			temp->children[indx] = newTrieNode();//child Trienode=new TrieNode();
		}
		//after making the new trie from index appoint that Trienode as temprent Trienode for further continuation
		temp = temp->children[indx];//temprent_Trienode=child_Trienode;
		//word count just to mark that we have visited
		temp->word_count += 1; // temp->isEndofWord=true;

	}
	// cout << word_count;
}



//we also start the iteration with the first character and the dummy Trienode.
// If we do not find the character in its children, we can return false/0.
// Remember to check Word_count after reaching the end of word.
//SEARCH OPERATION IN STRING
int search(TrieNode* temp, string s)
{
	// for (auto x : s)
	for (int i = 0; i < s.size(); i++)
	{
		// int indx = x - 'a';
		int indx = s[i] - 'a';
		if (temp->children[indx] == NULL)
			return 0;//return false	//mtlb us index ko kabhi visit kiya hi nhi so false
		temp = temp->children[indx];//agr us indx ka trie hai toh aage bado
	}
	return temp->word_count;//return(temp!=NULL and temp->isEndofWord);
}

// The pseudo code to check wether a single word exists in a dictionary of words or not is as follows:
/*
boolean check(String s)
{
    for(every char in String s)
    {
        if(child Trienode is null)
        {
            return false;
        }
    }
    return true;
}
*/

// Returns true if root has no children, else false
bool isEmpty(TrieNode* root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i])
			return false;
	return true;
}

// To DELETE
TrieNode* remove(TrieNode* root, string key, int depth = 0)
{
	if (!root) return NULL;

	//if last character of key is being processed
	if (depth == key.size())
	{
		//this node is no more end of word after removal of given key
		if (root->isEndofWord)
			isEndofWord = false;

		//if given is not prefix of prefix of any word
		if (isEmpty(root))
		{
			delete(root);
			root = NULL;
		}
		return root;
	}

	//if not last character ,reccur for the child obtained using ascii val
	int index = key[depth] - 'a';
	root->children[index] = remove(root->children[index], key, depth + 1);

	//if root does not have any child (its only child get deleted),and it is not end of another word.
	if (isEmpty(root) and root->isEndofWord == false)
	{
		delete(root);
		root = NULL;
	}
	return root;
}



int32_t main()
{
	TrieNode* root = newTrieNode();
	int n = 1;
	// cin >> n;
	for (int i = 0; i < n; i++)
	{
		string a = "add";
		string b = "hack";
		// cin >> a >> b;
		if (a == "add")
			insert(root, b);
		else
			cout << search(root, b) << endl;
	}
	return 0;
}

/*
INPUT
4
add hack
add hackerrank
find hac
find hak

OUTPUT
2
0

*/



class TrieTrieNode {
public:
	// Initialize your data structure here.
	bool is_word;
	TrieTrieNode *children[ALPHABET_SIZE];

	TrieTrieNode() {
		is_word = false;
		for (int i = 0; i < ALPHABET_SIZE; i++)
			children[i] = NULL;
	}
};

class Trie {
private:
	TrieNode* root;
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		int word_len = word.length();
		int k = 0;
		TrieNode *temp = root;

		for (int i = 0; i < word_len; i++)
		{
			k = word[i] - 'a';

			if (temp->children[k] == NULL)
			{
				temp->children[k] = new TrieNode();
			}

			temp = temp->children[k];
		}

		temp->is_word = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		int word_len = word.length();
		TrieNode *temp = root;

		for (int i = 0; i < word_len; i++)
		{
			int index = word[i] - 'a';
			temp = temp->children[index];

			if (temp == NULL)
				return false;
		}

		return temp->is_word;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		int word_len = prefix.length();
		TrieNode *temp = root;

		for (int i = 0; i < word_len; i++)
		{
			int index = prefix[i] - 'a';
			temp = temp->children[int index];

			if (temp == NULL)
				return false;
		}

		return true;
	}


};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");