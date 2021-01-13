/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
METHODS:
1. MAKING ENQUEUE OPERATION COSTLY	ENQUEUE=O(N) DEQUEUE-O(1)
Suppose arr={1,5,3,D,2,D}
Put always from arr to Stack1 then shift to stack2 on each step.
example:
Put 1 in stack1 then to push 5 in stack1 before that make st1 empty by poping 1 fro st1 and push
to st2 then push 5 to st1 then make st2 empty and push 1 to st1 .Currently the st1 =[5|1] st2=[]
Now before pushing 3 into the st1 ,pop all ele from st1 to st2 .Now st1=[3] st2=[1 5]
then st1=[3 5 1] st2=[]
then D means Dequeue So pop 1 from stack1 .hence st1=[3 5] st2=[]
then st1=[] st2=[5 3]
then st1=[2] st2=[5 3]
then st1=[2 3 5] st2=[]
Now D so pop 5 from st1.



2. MAKING DEQUEUE OPERATION COSTLY
Suppose arr={1,5,3,D,2,D}
Initially push ele into st1 till koi deqeue opn na ajae.
st1=[1 5 3] st2=[]
Now dequeue so push all ele except the last ele in st1 to st2 i.e st=[1] st2=[3 5]
For dequeue pop 1 from st1. after that put all ele in st2 back to st1 and push again till dequeue
comes . And this process go on.




How to check which is best ?
Check Efficiency if
Enqueue is 70% and
Dequeue is 30%
Make Enqueue in O(1) and Dequeue in O(n) i.e dequeue costly method.


3.Implementation of method 2 using Function Call Stack:
struct Queue {
    stack<int> s;

    // Enqueue an item to the queue
    void enQueue(int x)
    {
        s.push(x);
    }

    // Dequeue an item from the queue
    int deQueue()
    {
        if (s.empty()) {
            cout << "Q is empty";
            exit(0);
        }

        // pop an item from the stack
        int x = s.top();
        s.pop();

        // if stack becomes empty, return
        // the popped item
        if (s.empty())
            return x;

        // recursive call
        int item = deQueue();

        // push popped item back to the stack
        s.push(x);

        // return the result of deQueue() call
        return item;
    }
};


*/
#include<bits/stdc++.h>
using namespace std;

//M-1 Enqueue costly
struct enq_costly {
	stack<int>s1, s2;

	void enQueue(int x) {
		while (!s1.empty())	//s1 ko khali karo
		{
			s2.push(s1.top());
			s1.pop();
		}

		//Push item into s1
		s1.push(x);

		//push everything back to s1
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}


	//Dequeue an item from the queue
	int deQueue() {
		// if first stack is empty
		if (s1.empty()) {
			cout << "Q is Empty";
			exit(0);
		}

		// Return top of s1
		int x = s1.top();
		s1.pop();
		return x;
	}
};

struct dq_costly {
	stack<int>s1, s2;

	void enQueue(int x)
	{
		s1.pus(x);
	}

	void deQueue() {
		//if both stack is empty
		if (s1.empty() and s2.empty())
		{
			cout << "Q is empty";
			exit(0);
		}

		//if s2 is empty, moe elements from s1
		if (s2.empty()) {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}

		// return the top item from s2
		int x = s2.top();
		s2.pop();
		return x;
	}
};


//M-3 Using function call stack
class func_stack {

	stack<int> s;

	// Enqueue an item to the queue
	void enQueue(int x)
	{
		s.push(x);
	}

	// Dequeue an item from the queue
	int deQueue()
	{
		if (s.empty()) {
			cout << "Q is empty";
			exit(0);
		}

		// pop an item from the stack
		int x = s.top();
		s.pop();

		// if stack becomes empty, return
		// the popped item
		if (s.empty())
			return x;

		// recursive call
		int item = deQueue();

		// push popped item back to the stack
		s.push(x);

		// return the result of deQueue() call
		return item;
	}

};


int main()
{
	enq_costly q;
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);

	cout << q.deQueue() << '\n';
	cout << q.deQueue() << '\n';
	cout << q.deQueue() << '\n';

	return 0;
}