/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
1.RECURSION
2.ANOTHER STACK : The idea is to push every element into another temporary stack and
then print elements of the temporary stack.
*/
#include <bits/stdc++.h>
using namespace std;

// Recursive function to print stack elements
// from bottom to top without changing
// their order
void PrintStack(stack<int> s)
{
	// If stack is empty then return
	if (s.empty())
		return;


	int x = s.top();

	// Pop the top element of the stack
	s.pop();

	// Recursively call the function PrintStack
	PrintStack(s);

	// Print the stack element starting
	// from the bottom
	cout << x << " ";

	// Push the same element onto the stack
	// to preserve the order
	s.push(x);
}

void PrintStack_stack(stack<int> s)
{
	stack<int> temp;
	while (s.empty() == false)
	{
		temp.push(s.top());
		s.pop();
	}

	while (temp.empty() == false)
	{
		int t = temp.top();
		cout << t << " ";
		temp.pop();

		// To restore contents of
		// the original stack.
		s.push(t);
	}
}

// Driver code
int main()
{
	// Stack s
	stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	PrintStack(s);

	return 0;
}