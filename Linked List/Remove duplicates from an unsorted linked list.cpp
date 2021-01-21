#include<bits/stdc++.h>
using namespace std;

/* A linked list node */
struct Node
{
	int data;
	struct Node *next;
};

// Utility function to create a new Node
struct Node *newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void removeDup(Node* start)
{
	Node *p1, *p2, *dup;
	p1 = start;

	while (p1 != NULL and p1->next != NULL) //consider as a outer for loop
	{
		p2 = p1;
		while (p2->next != NULL) //inner for loop
		{
			if (p1->data == p2->next->data)
			{
				dup = p2->next;
				p2->next = p2->next->next;
				free(dup);
			}
			else
				p2 = p2->next;
		}
		p1 = p1->next;
	}
}

void printList(Node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

int main()
{
	/* The constructed linked list is:
	 10->12->11->11->12->11->10*/
	struct Node *start = newNode(10);
	start->next = newNode(12);
	start->next->next = newNode(11);
	start->next->next->next = newNode(11);
	start->next->next->next->next = newNode(12);
	start->next->next->next->next->next =
	    newNode(11);
	start->next->next->next->next->next->next =
	    newNode(10);

	printf("Linked list before removing duplicates ");
	printList(start);

	removeDuplicates(start);

	printf("\nLinked list after removing duplicates ");
	printList(start);

	return 0;
}