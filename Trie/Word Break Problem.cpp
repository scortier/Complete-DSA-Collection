/*
GOOGLE KA FAV QUESTION HAI
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
input: ilikemango
o.p: "i like mango"
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 26


struct TrieNode {
	TrieNode* child[MAX];
	// word_cnt is true if the node represents
	// end of a word
	bool word_cnt;
}

TrieNode *newNode
{
	TrieNode* temp = new TrieNode;
	temp->word_cnt = false;
	for (int i = 0; i < MAX; i++)
		temp->child[i] = NULL;
	return temp;
};


// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
//INSERTION OF STRING INTO TRIE
void insert(Node* root, string s)
{
	Node* temp = root;
	// for (auto x : s)
	for (int i = 0; i < s.size(); i++)
	{
		// int indx = x - 'a';
		int indx = s[i] - 'a';	// for finding the node in the root
		//agr rparent root ka vo indx ka node khali hai toh uus index se naya trie aage bna do
		if (temp->children[indx] == NULL ) //if(child node belonging to current char is null)
		{
			temp->children[indx] = newNode();//child node=new Node();
		}
		//after making the new trie from index appoint that node as current node for further continuation
		temp = temp->children[indx];//current_node=child_node;
		//word count just to mark that we have visited
		temp->word_count = true;

	}
	// cout << word_count;
}


// Returns true if key presents in trie, else
// false
//SEARCH OPERATION IN STRING
bool search(Node* temp, string s)
{
	// for (auto x : s)
	for (int i = 0; i < s.size(); i++)
	{
		// int indx = x - 'a';
		int indx = s[i] - 'a';
		if (temp->children[indx] == NULL)
			return 0;	//mtlb us index ko kabhi visit kiya hi nhi so false
		temp = temp->children[indx];//agr us indx ka trie hai toh aage bado
	}
	return temp->word_count;// or return (!temp=NULL and temp->word_cnt);
}


//main function for the program
bool wordBreak(TrieNode* root, string s)
{
	if (s.size() == 0) return true;

	for (int i = 1; i <= s.size(); i++)
	{
		//pick substr from length=0 upto i then search for it ,if present then check for remaining
		//substr through recursive call on main function if present then return true;
		// else false
		if (search(root, s.substr(0, i)) and wordBreak(s.substr(i, s.size() - i), root))
			return true;
	}
	return false;
}



int32_t main()
{
	string dictionary[] = {"mobile", "samsung", "sam",
	                       "sung", "ma\n", "mango",
	                       "icecream", "and", "go", "i",
	                       "like", "ice", "cream"
	                      };
	int n = sizeof(dictionary) / sizeof(dictionary[0]);
	struct TrieNode *root = getNode();

	// Construct trie
	for (int i = 0; i < n; i++)
		insert(root, dictionary[i]);

	wordBreak("ilikesamsung", root) ? cout << "Yes\n" : cout << "No\n";
	wordBreak("iiiiiiii", root) ? cout << "Yes\n" : cout << "No\n";
	wordBreak("", root) ? cout << "Yes\n" : cout << "No\n";
	wordBreak("ilikelikeimangoiii", root) ? cout << "Yes\n" : cout << "No\n";
	wordBreak("samsungandmango", root) ? cout << "Yes\n" : cout << "No\n";
	wordBreak("samsungandmangok", root) ? cout << "Yes\n" : cout << "No\n";
	return 0;
}