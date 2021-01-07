/*
whether to implement it with array or ll.
if we want tc:O(1) then array cant do it.
while for ll
on push we have to move middle up and on pop move the middle down so sll cant do that .
Hence prefer DLL for that.
We can delete middle element in O(1) time by maintaining mid pointer.
We can move mid pointer in both directions using previous and next pointers.
*/

#include<bits/stdc++.h>
using namespace std;

class DLL {
public:
	DLL *prev, *next;
	int data;
};

/* Representation of the stack data structure
that supports findMiddle() in O(1) time.
The Stack is implemented using Doubly Linked List.
It maintains pointer to head node, pointer to
middle node and count of nodes */
class myStack
{
public:
	DLL *head;
	DLL *mid;
	int count;
};


/* Function to create the stack data structure */
myStack *createMyStack()
{
	myStack *st = new myStack();
	st->count = 0;
	return st;
};


void push(myStack *st, int new_data)
{
	//A DLL NODE CONTAIN 3 VALUE i.e data,prev,next.

	DLL* new_DLL = new DLL();
	new_DLL->data = new_data;

	//as adding in the beginning so prev wil be null
	new_DLL->prev = NULL;

	/* link the old list off the new DLL */
	new_DLL->next = st->head;


	/* Increment count of itest in stack */
	st->count += 1;

	/* Change mid pointer in two cases
	1) Linked List is empty
	2) Number of nodes in linked list is odd */
	if (st->count == 1)	//only one element in the list then it is both head and mid ptr
	{
		st->mid = new_DLL;
	}
	else {
		st->head->prev = new_DLL;

		if (!(st->count & 1)) // Update mid if st->count is even
			st->mid = st->mid->prev;
	}

	/* move head to point to the new DLL */
	st->head = new_DLL;

}

/* Function to pop an element from stack */
//move down the mid ptr when there are odd no of elements.As in even only change will occur in mid
//ex : {1,2,3} mid is 2 and in {1,2} still the mid is 2.
int pop(myStack *st)
{
	/* Stack underflow */
	if (st->count == 0)
	{
		cout << "Stack is empty\n";
		return -1;
	}

	DLL *head = st->head;
	int item = head->data;
	st->head = head->next;

	// If linked list doesn't
	// become empty, update prev
	// of new head as NULL
	if (st->head != NULL)
		st->head->prev = NULL;

	st->count -= 1;

	// update the mid pointer when
	// we have odd number of
	// elements in the stack, i,e
	// move down the mid pointer.
	if ((st->count) & 1 )
		st->mid = st->mid->next;

	free(head);

	return item;
}

// Function for finding middle of the stack
//just return the mid

int findMiddle(myStack *st)
{
	if (st->count == 0)
	{
		cout << "Stack is empty now\n";
		return -1;
	}

	return st->mid->data;
}

/*
FOR DELETE MIDDLE
1. IF ele=1 after removing mid , make it as head and mid;
2. if ele>1 reassign the mid's prev and next ptr.
3. determing the curr mid element
	1. if updated cnt is odd , new mid is mid's next;
	2. if the updated count is even , new mid is mid's prev.
*/
int deleteMiddle(myStack *st)
{
	if (st->count == 0)
	{
		cout << "Stack is empty\n";
		return -1;
	}
	DLL *mid = st->mid;
	int item = mid->data;
	st->count--;
	if (st->count == 1)
	{
		st->head = st->head->next;
		st->mid = st->head;
	}
	/*
	Ex: {7,6,5,4,3,2,1} now here st->mid =4, st->mid->prev=5 , st->mid->next=3.
	Now we have to delete st->mid=4 so ptr direction changes from :
	1. st->mid->prev->next(i.e 5>next) =st->mid->next (i.e 3);
	2. st->mid->next->prev=st->mid->prev;

	*/
	else if (st->count > 0)
	{
		st->mid->prev->next = st->mid->next;
		st->mid->next->prev = st->mid->prev;
		if ((st->count) & 1)
			st->mid = st->mid->next;
		else
			st->mid = st->mid->prev;
	}
	free(mid);
	return item;
}

// Driver code
int main()
{
	/* Let us create a stack using push() operation*/
	myStack *st = createMyStack();
	push(st, 11);
	push(st, 22);
	push(st, 33);
	push(st, 44);
	push(st, 55);
	push(st, 66);
	push(st, 77);

	cout << "Item popped is " << pop(st) << endl;
	cout << "Item popped is " << pop(st) << endl;
	cout << "Middle Element is " << findMiddle(st) << endl;
	return 0;
}
