/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
SIMILAR TO THE K STACK IN ONE ARRAY

Method 1 (Divide the array in slots of size n/k)

Following are the three extra arrays are used:
1) front[]: This is of size k and stores indexes of front elements in all queues.
2) rear[]: This is of size k and stores indexes of rear elements in all queues.
2) next[]: This is of size n and stores indexes of next item for all items in array arr[].
*/
#include<bits/stdc++.h>
using namespace std;

class kQueues {
	int *arr;// Array of size n to store actual content to be stored in queue
	int *front;// Array of size k to store indexes of front elements of the queue
	int *rear;// Array of size k to store indexes of rear elements of queue
	int *next;// Array of size n to store next entry in all queues
	int n, k;
	int free;// To store the beginning index of the free list

public:
	//constructor to create k queue in an array of size n
	kQueues(int k, int n);

	// function to check if there is space available
	bool isFull()   {  return (free == -1);  }

	// To enqueue an item in queue number 'qn' where qn is from 0 to k-1
	void enqueue(int item, int q_no);

	// To dequeue an from queue number 'qn' where qn is from 0 to k-1
	int dequeue(int q_no);

// To check whether queue number 'qn' is empty or not
	bool  isEmpty(int q_no) {return (front[q_no] == -1);}

};


// Constructor to create k queues in an array of size n
kQueues::kQueues(int k1, int n1)
{
	k = k1, n = n1;
	arr = new int[n];
	front = new int[k];
	rear = new int[k];
	next = new int[n];

// Initialize all queues as empty
	for (int i = 0; i < k; i++)
		front[i] = -1;

	// Initialize all spaces as free
	free = 0;
	for (int i = 0; i < n - 1; i++)
		next[i] = i + 1;

	next[n - 1] = -1; // -1 is used to indicate end of free list
}

// To enqueue an item in queue number 'qn' where qn is from 0 to k-1
void kQueues::enqueue(int item, int q_no)
{
	// Overflow check
	if (isFull())
	{
		cout << "\nQueue Overflow\n";
		return;
	}

	int i = free;      // Store index of first free slot

	// Update index of free slot to index of next slot in free list
	free = next[i];

	if (isEmpty(q_no))
		front[q_no] = i;
	else
		next[rear[q_no]] = i;

	next[i] = -1;

	// Update next of rear and then rear for queue number 'qn'
	rear[q_no] = i;

	// Put the item in array
	arr[i] = item;
}



int kQueues::dequeue(int q_no)
{
	if (isEmpty(q_no))
	{
		cout << "Q underflow " << endl;
		return INT_MAX;
	}
	// Find index of front item in queue number 'qn'
	int i = front[q_no];

	front[q_no] = next[i];  // Change top to store next of previous top

	// Attach the previous front to the beginning of free list
	next[i] = free;
	free = i;

	// Return the previous front item
	return arr[i];

}

int main()
{
	// Let us create 3 queue in an array of size 10
	int k = 3, n = 10;
	kQueues ks(k, n);

	// Let us put some items in queue number 2
	ks.enqueue(15, 2);
	ks.enqueue(45, 2);

	// Let us put some items in queue number 1
	ks.enqueue(17, 1);
	ks.enqueue(49, 1);
	ks.enqueue(39, 1);

	// Let us put some items in queue number 0
	ks.enqueue(11, 0);
	ks.enqueue(9, 0);
	ks.enqueue(7, 0);

	cout << "Dequeued element from queue 2 is " << ks.dequeue(2) << endl;
	cout << "Dequeued element from queue 1 is " << ks.dequeue(1) << endl;
	cout << "Dequeued element from queue 0 is " << ks.dequeue(0) << endl;

	return 0;
}