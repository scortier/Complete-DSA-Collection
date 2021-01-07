/*
operation of the stack are
push,pop,peek(return top without modifying stack)
*/
//STACK IMPLEMENTATION FROM ARRAY USING CLASS

#include<bits/stdc++.h>
using namespace std;

// define default capacity of the stack
#define SIZE 10

// Class for stack
class Stack
{
	int *arr;
	int top;
	int capacity;

public:
	Stack(int size = SIZE); //constructor
	~Stack();			  //destructor

	void push(int);
	int pop();
	int peek();

	int size();
	bool isEmpty();
	bool isFull();


};

// Constructor to initialize stack
Stack::Stack(int size)
{
	arr = new int[size];	//dynamic memory allocation to arr
	capacity = size;
	top = -1;	//as no element so -1
}

// Destructor to free memory allocated to the stack
Stack::~Stack()
{
	delete[] arr; //not delete arr as arr is array not pointer
}

// Utility function to add an element x in the stack
void Stack::push(int x)
{
	if (isFull())
	{
		cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Inserting " << x << endl;
	arr[top++] = x;

}


// Utility function to pop top element from the stack
int Stack::pop()
{
	// check for stack underflow
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Removing " << peek() << endl;

	// decrease stack size by 1 and (optionally) return the popped element
	return arr[top--];
}

// Utility function to return top element in a stack
int Stack::peek()
{
	if (!isEmpty())
		return arr[top];
	else
		exit(EXIT_FAILURE);
}

// Utility function to return the size of the stack
int Stack::size()
{
	return top + 1;
}

// Utility function to check if the stack is empty or not
bool Stack::isEmpty()
{
	return top == -1;    // or return size() == 0;
}

// Utility function to check if the stack is full or not
bool Stack::isFull()
{
	return top == capacity - 1;    // or return size() == capacity;
}

int main()
{
	Stack pt(3);

	pt.push(1);
	pt.push(2);

	pt.pop();
	pt.pop();

	pt.push(3);

	cout << "Top element is: " << pt.peek() << endl;
	cout << "Stack size is " << pt.size() << endl;

	pt.pop();

	if (pt.isEmpty())
		cout << "Stack Is Empty\n";
	else
		cout << "Stack Is Not Empty\n";

	return 0;
}