/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;

#define MAX 256
#define MAX_wlen 500

struct TrieNode {
	TrieNode* child[MAX];
	int word_cnt;
}

TrieNode *newNode
{
	TrieNode* temp = new TrieNode;
	temp->word_cnt = 0;
	for (int i = 0; i < MAX; i++)
		temp->child[i] = NULL;
	return temp;
};

//method to insert a new string into Trie
void insert(TrieNode* root, string s)
{
	TrieNode* temp = root;
	for (int i = 0; i < s.size(); i++)
	{
		int index = s[i] - 'a';
		if (temp->child[index] == NULL)
			temp->child[index] = newNode();
		else
			temp->child[index]->word_cnt += 1;
		temp = temp->child[index];
	}
}

void util(TrieNode* root, char prefix[], int indx)
{
	//curr case
	if (root == NULL)
		return;

	//base case
	if (root->word_cnt == 1)
	{
		prefix[indx] = '\0';
		cout << prefix << " ";
		return;
	}

	for (int i = 0; i < MAX; i++)
	{
		if (root->child[i] != NULL)
		{
			prefix[ind] = i;
			util(root->child[i], prefix, indx + 1);
		}
	}
}

void findPrefix(string a[], int n)
{
	TrieNode* temp = newNode();
	temp->word_cnt = 0;
	for (int i = 0; i < n; i++)
	{
		insert(root, a[i]);
	}

	//create an array to store all prefix
	char prefix[MAX_wlen];

	//print all prefix using triw traversal
	util(root, prefix, 0);

}


int32_t main()
{

	string arr[] = {"zebra", "dog", "duck", "dove"};
	int n = sizeof(arr) / sizeof(arr[0]);
	findPrefixe(arr, n);

	return 0;
}



// class Solution {
// public:
//     int maximumScore(vector<int>& num, vector<int>& mul) {
//         int n=num.size();
//         int m=mul.size();
//         int t[n+1][m+1]//r->num c->mul
//         for(int i=0;i<n+1;i++)
//         {
//         	for(int j=0;j<m+1;j++)
//         	{
//         		if(i==0 or j==0)
//         			t[i][j]=0;
//         	}
//         }

//           for(int i=1;i<n+1;i++)
//         {
//         	for(int j=1;j<m+1;j++)
//         	{
//         		if(i==0 or j==0)
//         			t[i][j]=0;
//         	}
//         }
//     }
// };