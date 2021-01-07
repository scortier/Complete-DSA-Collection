/*
TWO METHODS:
1. DIVIDE THE ARRAY INTO TWO HALF.
2. START BOTH THE STACK FROM CORNERS OF ARRAY TO UTILIZE EFFICIENTLY

Complexity Analysis:

Time Complexity:
Push operation : O(1)
Pop operation : O(1)
Auxiliary Space :O(N).
*/
/*
1st method can cause stack overflow
*/


//METHOD 1
#include<bits/stdc++.h>
using namespace std;

// define default capacity of the stack
#define SIZE 10
class  twoStack {
	int* arr;
	int capacity;
	int top1, top2;

public:
	//consructor
	twoStack(int size = SIZE);
	~twoStack();

	void push1(int);
	void push2(int);
	int pop1();
	int pop2();

};

twoStack:: twoStack(int size)
{
	capacity = size;
	arr = new int[size];
	top1 = size / 2 + 1;
	top2 = size / 2;
}
twoStack:: ~twoStack() {
	delete [] arr;
}

void twoStack::push1(int x)
{
	// There must be at least one empty
	// space for new element
	if (top1 > 0) {
		top1--;	//As the stack is filling from n/2 to 0
		arr[top1] = x;
	}
	else {
		cout << "Stack overflow" << "by element" << x << endl;
		return;
	}

}

void twoStack::push2(int x) {
	if (top2 < capacity - 1) {
		top2++; 			//As the stack2 is filling from n/2 to n-1
		arr[top2] = x;
	}
	else {
		cout << "Stack Overflow"
		     << " By element :" << x << endl;
		return;
	}
}


int twoStack::pop1() {
	if (top1 <= capacity / 2)
	{
		int x = arr[top1++];
		return x;
	}
	else
	{
		cout << "overflow" << endl;
		exit(1);
	}
}

int twoStack::pop2() {
	if (top2 >= capacity / 2 + 1) {
		int x = arr[top2];
		top2--;
		return x;
	}
	else {
		cout << "Stack UnderFlow";
		exit(1);
	}
}

//M-2 EFFICIENT WAY
//BOTH STACK STARTING FROM ENDS OF THE ARRAY

class TWOStacks {
	int* arr;
	int size;
	int top1, top2;

public:
	TWOStacks(int n) // constructor
	{
		size = n;
		arr = new int[n];
		top1 = -1;
		top2 = size;
	}

	// Method to push an element x to stack1
	void push1(int x)
	{
		// There is at least one empty space for new element
		if (top1 < top2 - 1) {
			top1++;
			arr[top1] = x;
		}
		else {
			cout << "Stack Overflow";
			exit(1);
		}
	}

	// Method to push an element x to stack2
	void push2(int x)
	{
		// There is at least one empty
		// space for new element
		if (top1 < top2 - 1) {
			top2--;
			arr[top2] = x;
		}
		else {
			cout << "Stack Overflow";
			exit(1);
		}
	}

	// Method to pop an element from first stack
	int pop1()
	{
		if (top1 >= 0) {
			int x = arr[top1];
			top1--;
			return x;
		}
		else {
			cout << "Stack UnderFlow";
			exit(1);
		}
	}

	// Method to pop an element from second stack
	int pop2()
	{
		if (top2 < size) {
			int x = arr[top2];
			top2++;
			return x;
		}
		else {
			cout << "Stack UnderFlow";
			exit(1);
		}
	}
};
int main()
{
	twoStack ts(5);
	//TWOStacks ts(5);
	ts.push1(5);
	ts.push2(10);
	ts.push2(15);
	ts.push1(11);
	ts.push2(7);
	cout << "Popped element from stack1 is "
	     << " : " << ts.pop1()
	     << endl;
	ts.push2(40);
	cout << "\nPopped element from stack2 is "
	     << ": " << ts.pop2()
	     << endl;
	return 0;
}


