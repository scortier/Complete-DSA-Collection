/*
ONLY 1 CELEBRITY IS POSSIBLE MAX.
CELEBRITY - KNOWN BY EVERYONE BUT DON'T KNOW ANYONE.
IN MATRIX PEOPLE - ROW , CELEB- COLUMN
Example : each index from 0 represent a person.
a[R][C] : a[2][1] //means whether 2 know 1 or not
Methods to solve:
1.Graph 2.Recursion 3.

*/

#include <bits/stdc++.h>
#include <list>
using namespace std;

// Max # of persons in the party

#define N 8

// Person with 2 is celebrity
int arr[N][N] =
{	{0, 0, 1, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 0},
	{0, 0, 1, 0}
};



// Returns -1 if celebrity
// is not present. If present,
// returns id (value from 0 to n-1).
int find_celeb(int n)
{
	stack<int>st;
	//Push everyone into the stack
	for (int i = 0; i < n; i++)
		st.push(i);



//find CELEB
	while (st.size() >= 2)
	{
		//extract top 2
		int A = st.top();
		st.pop();
		int B = st.top();
		st.pop();

		if (arr[A][B] == 1)
			//as A knows B so A cant be a celeb
			st.push(B);
		else
			//as B knows A so B cant be a celeb
			st.push(A);
	}

//when st.size()<2

	int potential = st.top();
	st.pop();
	//check every cell associated with potential
	for (int i = 0; i < n; i++)
	{
		if (i != potential) // a[pot][pot] check nhi karna hota hai baaki sab check karo
		{
			//any i which dont know poten. or  any i which potent knows
			if (arr[i][potential] == 0 or arr[potential][i] == 1)
				// cout << "None is CELEB" << endl;
				return -1;
		}
	}

	//cout << potential << endl;
	return potential;
}

int main()
{
	int n = 4;
	int id = find_celeb(n);
	id == -1 ? cout << "No celebrity" :
	                cout << "Celebrity ID " << id;
	return 0;
}