/*Complexity Analysis:

Time Complexity: O(n).
Traversal of list is done only once and it has ‘n’ elements.
Auxiliary Space: O(n/k).

For each Linked List of size n, n/k or (n/k)+1 calls will be made during the recursion.

Input: 1->2->3->4->5->6->7->8->NULL, K = 3
Output: 3->2->1->6->5->4->8->7->NULL
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
};*/

struct LinkedList {
	Node* head;
	LinkedList() {
		head = NULL;
	}

	/* Reverses the linked list in groups
	of size k and returns the pointer
	to the new head node. */
	Node *reverse (Node *head, int k)
	{
		Node* current = head;
		Node* next = NULL;
		Node* prev = NULL;
		int count = 0;

		/*reverse first k nodes of the linked list */
		while (current != NULL && count < k)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
			count++;
		}

		/* next is now a pointer to (k+1)th node
		Recursively call for the list starting from current.
		And make rest of the list as next of first node */
		if (next != NULL)
			head->next = reverse(next, k);

		/* prev is new head of the input list */
		return prev;
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
	// Node* head = NULL;
	/* Created Linked list is 1->2->3->4->5->6->7->8->9 */
	LinkedList ll;
	ll.push(9);
	ll.push(8);
	ll.push(7);
	ll.push(6);
	ll.push(5);
	ll.push(4);
	ll.push(3);
	ll.push(2);
	ll.push(1);
	int grp = 3;
	cout << "Given linked list\n";
	ll.print();
	cout << endl;

	ll.head = ll.reverse(ll.head, grp);

	cout << "\nReversed Linked list \n";
	ll.print(); cout << endl;
	return 0;
}