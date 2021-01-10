/*
Input: Head of following linked list
1->2->3->4->NULL
Output: Linked list should be changed to,
4->3->2->1->NULL

APPROACH:
-- pointers : head,curr,prev,next.
prev and next == NULL
curr == first ele (i.e head)

STEPS:

DO IT TILL curr becomes NULL i.e [while(curr!=NULL)]
1.Before changing curr->next store it in `next`. i.e next=curr->next;
2.Now change curr->next(next of curr) by reversing the curr->next dirn.
3.Now move the prev and curr forward in resp manner.



Time Complexity: O(n)
Space Complexity: O(1)

*/
#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *next;
};

Node *newNode(int x)
{
	Node* temp = new Node;
	temp->data = x;
	return temp;
}

/*
struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
*/

struct LinkedList
{
	Node* head;
	LinkedList() {
		head = NULL;
	}

	void reverse()
	{
		//initializing
		Node *curr = head;
		Node *prev = NULL, *next = NULL;

		//Main Condition
		while (curr != NULL)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}

	void print()
	{
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}


	void push(int data)
	{
		Node* temp = newNode(data);
		temp->next = head;
		head = temp;
	}
};




int main() {
	LinkedList ll;
	ll.push(20);
	ll.push(4);
	ll.push(15);
	ll.push(85);

	cout << "Given linked list\n";
	ll.print();

	ll.reverse();

	cout << "\nReversed Linked list \n";
	ll.print();
	return 0;
}