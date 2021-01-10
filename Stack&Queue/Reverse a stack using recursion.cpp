/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
ONLY ALLOWED - isEmpty,pop,push
*/
#include<bits/stdc++.h>
using namespace std;

stack<int>st;

string s;

char insert(char x)
{
	if (st.size() == 0)
		st.push(x);
	else
	{
		char a = st.top();
		st.pop();
		insert(x);
		st.push(a);
	}
}

char reverse()
{
	if (st.size())
	{
		char x = st.top();
		st.pop();
		reverse();

		insert(x);
	}
}

int32_t main()
{

	return 0;
}