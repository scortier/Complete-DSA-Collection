/*
Queue operation
front,rear,enqueue(DAALNA),dequeue(NIKALNA),peek , FIFO
USAGE:
1) When a resource is shared among multiple consumers.
Examples include CPU scheduling, Disk Scheduling.
2) When data is transferred asynchronously (data not necessarily received at same rate as sent)
between two processes. Examples include IO Buffers, pipes, file IO, etc.

*/
#include<bits/stdc++.h>
using namespace std;

// define default capacity of the queue
#define SIZE 10

// Class for queue
class queue
{
	int *arr;       // array to store queue elements
	int capacity;   // maximum capacity of the queue
	int front;      // front points to front element in the queue (if any)
	int rear;       // rear points to last element in the queue
	int count;      // current size of the queue

public:
	queue(int size = SIZE);     // constructor
	~queue();                   // destructor

	void dequeue();
	void enqueue(int x);
	int peek();
	int size();
	bool isEmpty();
	bool isFull();
};
