/*
methods:
1. divide the arryay into k parts each of size n/k.

2.
The idea is to use two extra arrays for efficient implementation of k stacks in an array.
This may not make much sense for integer stacks, but stack items can be large for example stacks of employees,
students, etc where every item is of hundreds of bytes. For such large stacks, the extra space used is
comparatively very less as we use two integer arrays as extra space.

Following are the two extra arrays are used:
1) top[]: This is of size k and stores indexes of top elements in all stacks.
2) next[]: This is of size n and stores indexes of next item for the items in array arr[].
Here arr[] is actual array that stores k stacks.
Together with k stacks, a stack of free slots in arr[] is also maintained.
The top of this stack is stored in a variable ‘free’.

All entries in top[] are initialized as -1 to indicate that all stacks are empty.
All entries next[i] are initialized as i+1 because all slots are free initially and pointing to next slot.
Top of free stack, ‘free’ is initialized as 0.

*/

#include<bits/stdc++.h>
using namespace std;

class Stack {
	int *arr;   // Array of size n to store actual content to be stored in stacks
	int *top;   // Array of size k to store indexes of top elements of stacks
	int *next;  // Array of size n to store next entry in all stacks
	// and free list

	int n, k;
	int free;  // To store beginning index of free list

public:
	//constructor to create k stacks in an array of size n
	kStacks(int k, int n);

	// A utility function to check if there is space available
	bool isFull()   {  return (free == -1);  }

	// To push an item in stack number 'sn' where sn is from 0 to k-1
	void push(int item, int sn);

	// To pop an from stack number 'sn' where sn is from 0 to k-1
	int pop(int sn);

	// To check whether stack number 'sn' is empty or not
	bool isEmpty(int sn)  {  return (top[sn] == -1); }

};

//constructor to create k stacks in an array of size n
kStacks::kStacks(int k1, int n1)
{
	//intialize n and k, and allocate memory for all arrays
	k = k1, n = n1;
	arr = new int[n];
	top = new int[k];	// just to store the top of each stack
	next = new int[n];

//intialize all stacks as empty
	for (int i; i < k; i++)
		top[i] = -1;

	//intialize all spaces as free to use them for other array
	//this free denote the index in next array for free spot available in arr and the value at next denote the
	//index at arr for inserting the value.
	free = 0;
	for (int i = 0; i < n - 1; i++)
		next[i] = i + 1;
	next[n - 1] = -1; //to denote end of free list
}
/*
1. where to push the element -- arr[free]
2. what is the next free spot -- next[free]
3. update the top of stack
	1. the new element becomes top of stack.update the index in top[sn];

*/
// To push an item in stack number 'sn' where sn is from 0 to k-1
void kStacks::push(int item, int sn)
{
	// Overflow check
	if (isFull())
	{
		cout << "\nStack Overflow\n";
		return;
	}

	int i = free;      // Store index of first free slot

	// Update index of free slot to index of next slot in free list
	free = next[i];

	// Update next of top and then top for stack number 'sn'
	next[i] = top[sn];
	top[sn] = i;

	// Put the item in array
	arr[i] = item;		//USAGE OF i=free
}

// To pop an from stack number 'sn' where sn is from 0 to k-1
int kStacks::pop(int sn)
{
	// Underflow check
	if (isEmpty(sn))
	{
		cout << "\nStack Underflow\n";
		return INT_MAX;
	}

	/*
	ex push(20,2) push(25,2) pop(2)
	this means top is 25 now we have to remove an ele from stack 2 i.e 25 itself
	arr{20,25, , , , , , , } 	top {-1,-1, 1 ,-1,-1} next{-1, 0 ,3,4,5,6...} free{2}
	after removing 25 the new top will be 20 so update top {-1,-1, 0 , -1,-1} next{-1, 2 ,3,4,5,...}	free{1}
	*/
	// Find index of top item in stack number 'sn'
	int i = top[sn];	//acc to abbove ex. i=1

	top[sn] = next[i];  // Change top to store next of previous top ... next[i] denote the next ele to 25 i.e 20 so new top=20

	// Attach the previous top to the beginning of free list
	next[i] = free; // next free spot ko store karo in next i.e 2
	free = i; //now make free updated as 1 due to popping of top i. 25 so free spot vo hojaega.

	// Return the previous top item
	return arr[i];
}

/* Driver program to test twStacks class */
int main()
{
	// Let us create 3 stacks in an array of size 10
	int k = 3, n = 10;
	kStacks ks(k, n);

	// Let us put some items in stack number 2
	ks.push(15, 2);
	ks.push(45, 2);

	// Let us put some items in stack number 1
	ks.push(17, 1);
	ks.push(49, 1);
	ks.push(39, 1);

	// Let us put some items in stack number 0
	ks.push(11, 0);
	ks.push(9, 0);
	ks.push(7, 0);

	cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
	cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
	cout << "Popped element from stack 0 is " << ks.pop(0) << endl;

	return 0;
}