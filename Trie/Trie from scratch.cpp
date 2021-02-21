/*
https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/tries-78733022/submissions/

Tries are an extremely special and useful data-structure that are based on the
prefix of a string. They are used to represent the “Retrieval” of data and thus
 the name Trie.
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;

struct Node {
	Node *children[26];
	int word_count;
};

Node *newNode()
{
	Node* temp = new Node;
	temp->word_count = 0;
	for (int i = 0; i < 26; i++)
	{
		temp->children[i] = NULL;
	}
	return temp;
}

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
		temp->word_count += 1;

	}
	// cout << word_count;
}
//we also start the iteration with the first character and the dummy node.
// If we do not find the character in its children, we can return false/0.
// Remember to check Word_count after reaching the end of word.
//SEARCH OPERATION IN STRING
int search(Node* temp, string s)
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
	return temp->word_count;//
}

// The pseudo code to check wether a single word exists in a dictionary of words or not is as follows:
/*
boolean check(String s)
{
    for(every char in String s)
    {
        if(child node is null)
        {
            return false;
        }
    }
    return true;
}
*/












int32_t main()
{
	Node* root = newNode();
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
