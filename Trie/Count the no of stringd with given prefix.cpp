/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>

*/
#include<bits/stdc++.h>
using namespace std;



struct Trienode
{
	char data;
	int pc = 0; //prefix count
	Trienode *child[26];
};
//no wordend used as of no use saving space
Trienode nodepool[100000]; //Pool of 100k trienode
Trienode *root; //root of trie

int poolcount; //always point to next free node

void initial() {
	poolcount = 0;
	root = &nodepool[poolcount++];
	root->data = '/';
	//register to directly store i in register than in memory used for fast processing.
	//Generally, compilers themselves do optimizations and put the variables in register.
	for (register int i = 0; i < 26; i++)
		root->child[i] = NULL;
}

Trienode *getNode(char Data)
{
	Trienode *temp = &nodepool[poolcount++];
	temp->data = Data;
	for (register int i = 0; i < 26; ++i)
		temp->child[i] = NULL;
	temp->pc = 0;
	return temp;
}

// Returns true if root has no children, else false
// bool isEmpty(Trienode* root)
// {
// 	for (int i = 0; i < 26; i++)
// 		if (root->children[i])
// 			return false;
// 	return true;
// }

//INSERTION OF STRING INTO TRIE
void insert(char *s)
{
	Trienode *temp = root;
	int index;
	for (int i = 0; s[i] != '\0'; ++i)
	{
		index = s[i] - 'a';
		if (temp->child[index] == NULL)
			temp->child[index] = getNode(s[i]);
		temp->child[index]->pc += 1;
		temp = temp->child[index];
	}
}
//SEARCH OPERATION IN STRING

bool search(char *s)
{
	Trienode *temp = root;
	int index;
	for (int i = 0; s[i] != '\0'; ++i)
	{
		index = s[i] - 'a';
		if (temp->child[index] == NULL || temp->child[index]->pc == 0)
			return false;
		temp = temp->child[index];
	}
	return true;
}

void Triedelete(char *s)
{
	if (search(s))
	{
		Trienode *temp = root;
		int indx;
		for (int i = 0; s[i] != '\0'; i++)
		{
			indx = s[i] - 'a';
			temp->child[indx]->pc -= 1;
			temp = temp->child[indx];
		}
	}
}

int countPrefix(string s)
{
	Trienode *temp = root;
	int index;
	for (int i = 0; s[i] != '\0'; ++i)
	{
		index = s[i] - 'a';
		if (temp->child[index] == NULL || temp->child[index]->pc == 0)
			return 0;   //No string with given prefix is present
		temp = temp->child[index];
	}
	return temp->pc;
}

int main()
{
	initial();
	char a[5] = {'a', 'r', 'm', 'y'};
	char b[5] = {'a', 'r', 'm'};
	char c[5] = {'a', 'r', 'm', 's'};
	char d[5] = {'a', 'r', 'y'};
	char e[5] = {'a', 'm', 'y'};
	char f[5] = {'a', 'p', 'i'};


	insert(a);
	insert(b);
	insert(c);
	insert(d);
	insert(e);
	insert(f);

	//cout<<search(b)<<"\n";

	printf("No of strings with given prefix = %d\n", countPrefix("a"));
	printf("No of strings with given prefix = %d\n", countPrefix("ar"));
	printf("No of strings with given prefix = %d\n", countPrefix("arm"));
	printf("No of strings with given prefix = %d\n", countPrefix("army"));
	printf("No of strings with given prefix = %d\n", countPrefix("armi"));
	printf("No of strings with given prefix = %d\n", countPrefix("ary"));

	cout << "Deletion...STARTED\n";
	Triedelete(a);
	Triedelete(d);
	cout << "DONE...\n\n";


	printf("No of strings with given prefix = %d\n", countPrefix("a"));
	printf("No of strings with given prefix = %d\n", countPrefix("ar"));
	printf("No of strings with given prefix = %d\n", countPrefix("arm"));
	printf("No of strings with given prefix = %d\n", countPrefix("army"));
	printf("No of strings with given prefix = %d\n", countPrefix("armi"));
	printf("No of strings with given prefix = %d\n", countPrefix("ary"));

	return 0;
}