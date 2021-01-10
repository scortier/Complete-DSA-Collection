/*
/*
Input: Head of following linked list
1->2->3->4->NULL
Output: Linked list should be changed to,
4->3->2->1->NULL

APPROACH:



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

struct LinkedList {
	Node* head;
	// Node *tail ;

	LinkedList() {
		head = NULL;
		// tail->next = NULL;
	}

	// void rev_util(Node* node)
	// {
	// 	if (node == NULL) return;
	// 	rev_util(node->next);

	// 	if (node == tail) {}
	// 	//nothing to do
	// 	else
	// 	{
	// 		node->next->next = node;
	// 	}
	// }
	Node* reverse(Node* head)
	{
		if (head == NULL || head->next == NULL)
			return head;

		/* reverse the rest list and put
		  the first element at the end */
		Node* rest = reverse(head->next);
		head->next->next = head;

		/* tricky step -- see the diagram */
		head->next = NULL;

		/* fix the head pointer */
		return rest;
	}

	// Node* reverse()
	// {
	// 	rev_util(head);
	// 	head->next = NULL;
	// 	Node *temp = head;
	// 	head = tail;
	// 	tail = temp;

	// 	return ;
	// }
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
	ll.push(9);
	ll.push(8);
	ll.push(7);
	ll.push(6);
	ll.push(5);
	ll.push(4);
	ll.push(3);
	ll.push(2);
	ll.push(1);

	cout << "Given linked list\n";
	ll.print();

	ll.head = ll.reverse(ll.head);

	cout << "\nReversed Linked list \n";
	ll.print();
	return 0;
}