/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
Time complexity:
O(No of words * Max word length + query time (no of queue * max word length))

*/
#include<bits/stdc++.h>
using namespace std;

//Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

//basic trie structure
struct TrieNode {

	TrieNode *child[ALPHABET_SIZE];
	// isWordEnd is true if the node represents
	// end of a word
	bool isWordEnd;
};

// Returns new trie node (initialized to NULLs)
TrieNode *getNode()
{
	TrieNode *temp = new TrieNode;
	temp->isWordEnd = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		temp->child[i] = NULL; //to make the child node null initially
	}
	return temp;
}

// If not present, inserts key into trie. If the
// key is prefix of trie node, just marks leaf node
void insert(TrieNode *root, string key)
{
	TrieNode *temp = root;

	for (int level = 0; level < key.size(); level++)
	{
		int index = key[level] - 'a';
		//if(child node belonging to current char is null)
		if (!temp->child[index])
			temp -> child[index] = getNode();

		temp = temp->child[index];
	}

	//mark last node as leaf
	temp->isWordEnd = true;
}

//Return true if key present in trie else false
bool search(TrieNode *root, string key)
{
	int n = key.size();
	TrieNode *temp = root;

	for (int level = 0; level < n; level++)
	{
		int index = key[level] - 'a';

		if (temp->child[index] == NULL)
			return false;
		temp = temp->child[index];
	}
	return (temp != NULL and temp->isWordEnd);
}

//Return 0 if current node has a child
//if all child are null , return 1;
bool isLastNode(TrieNode *root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->child[i])
			return 0;
	return 1;
}

// Recursive function to print auto-suggestions for given
// node.
void suggestionsRec(struct TrieNode* root, string currPrefix)
{
	// found a string in Trie with the given prefix
	if (root->isWordEnd)
	{
		cout << currPrefix;
		cout << endl;
	}

	// All child struct node pointers are NULL
	if (isLastNode(root))
		return;

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (root->child[i])
		{
			// append current character to currPrefix string
			currPrefix.push_back(97 + i);

			// recur over the rest
			suggestionsRec(root->child[i], currPrefix);
		}
	}
}

// print suggestions for given query prefix.
int printAutoSuggestions(TrieNode* root, const string query)
{
	struct TrieNode* pCrawl = root;

	// Check if prefix is present and find the
	// the node (of last level) with last character
	// of given string.
	int level;
	int n = query.length();
	for (level = 0; level < n; level++)
	{
		int index = CHAR_TO_INDEX(query[level]);

		// no string in the Trie has this prefix
		if (!pCrawl->child[index])
			return 0;

		pCrawl = pCrawl->child[index];
	}

	// If prefix is present as a word.
	bool isWord = (pCrawl->isWordEnd == true);

	// If prefix is last node of tree (has no
	// child)
	bool isLast = isLastNode(pCrawl);

	// If prefix is present as a word, but
	// there is no subtree below the last
	// matching node.
	if (isWord && isLast)
	{
		cout << query << endl;
		return -1;
	}

	// If there are are nodes below last
	// matching character.
	if (!isLast)
	{
		string prefix = query;
		suggestionsRec(pCrawl, prefix);
		return 1;
	}
	return 0;
}

// Driver Code
int main()
{
	struct TrieNode* root = getNode();
	insert(root, "hello");
	insert(root, "dog");
	insert(root, "hell");
	insert(root, "cat");
	insert(root, "a");
	insert(root, "hel");
	insert(root, "help");
	insert(root, "helps");
	insert(root, "helping");
	int comp = printAutoSuggestions(root, "hel");

	if (comp == -1)
		cout << "No other strings found with this prefix\n";

	else if (comp == 0)
		cout << "No string found with this prefix\n";

	return 0;
}