/*
Algorithm:

Declare a character stack S.
Now traverse the expression string exp.
If the current character is a starting bracket (‘(‘ or ‘{‘ or ‘[‘) then push it to stack.
If the current character is a closing bracket (‘)’ or ‘}’ or ‘]’) then pop from stack and if the popped character is the matching starting bracket then fine else brackets are not balanced.
After complete traversal, if there is some starting bracket left in stack then “not balanced”
Time Complexity: O(n)
Auxiliary Space: O(n) for stack.
*/

#include<bits/stdc++.h>
using namespace std;
bool paren_checker(string s)
{
	stack<int>st;
	char x;
	int n = s.size();

	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(' or s[i] == '[' or s[i] == '{')
		{
			st.push(s[i]);
			continue;
		}

		// IF current current character is not opening
		// bracket, then it must be closing. So stack
		// cannot be empty at this point.
		if (st.empty())
			return false;

		switch (s[i]) {
		case')':

			x = st.top();
			st.pop();
			if (x == '{' or x == '[')
				return false;
			break;

		case ']':

			x = st.top();
			st.pop();
			if (x == '(' or x == '{')
				return false;
			break;

		case '}':
			x = st.top();
			st.pop();
			if (x == '(' or x == '[')
				return false;
			break;

		}
	}
	return (st.empty());	//check empty stack
}



int main()
{
	string expr = "{()}[]";

	// Function call
	if (paren_checker(expr))
		cout << "Balanced";
	else
		cout << "Not Balanced";
	return 0;
}