/*
/*
Input: Head of following linked list
1->2->3->4->NULL
Output: Linked list should be changed to,
4->3->2->1->NULL

APPROACH:
1.hashing
2.flag
3.Floyd’s Cycle-Finding Algorithm
4.store the length



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

//1.hashing
    bool detect loop(Node *h)
    {
        unordered_set<Node *>s;
        while (h != NULL)
        {
            if (s.find(h) != s.end())
                return true;

            s.insert(h);
            h = h->next;
        }
        return false;
    }

//2.flag
    bool detectLoop(struct Node* h)
    {
        while (h != NULL) {
            // If this node is already traverse
            // it means there is a cycle
            // (Because you we encountering the
            // node for the second time).
            if (h->flag == 1)
                return true;

            // If we are seeing the node for
            // the first time, mark its flag as 1
            h->flag = 1;

            h = h->next;
        }

        return false;
    }

//3.Floyd’s Cycle-Finding Algorithm
    int detectLoop(Node* list)
    {
        Node *slow_p = list, *fast_p = list;

        while (slow_p && fast_p && fast_p->next) {
            slow_p = slow_p->next;
            fast_p = fast_p->next->next;
            if (slow_p == fast_p) {
                return 1;
            }
        }
        return 0;
    }

// 4: Marking visited nodes without modifying the linked list data structure
    bool detectLoop(Node* head)
    {

        // Create a temporary node
        Node* temp = new Node;
        while (head != NULL) {

            // This condition is for the case
            // when there is no loop
            if (head->next == NULL) {
                return false;
            }

            // Check if next is already
            // pointing to temp
            if (head->next == temp) {
                return true;
            }

            // Store the pointer to the next node
            // in order to get to it in the next step
            Node* nex = head->next;

            // Make next point to temp
            head->next = temp;

            // Get to the next node in the list
            head = nex;
        }

        return false;
    }
    /*
    Solution 5: Store length

    In this method, two pointers are created, first (always points to head) and last.
    Each time last pointer moves we calculate no of nodes in between first and last and
    check whether current no of nodes > previous no of nodes, if yes we proceed by moving
    last pointer else it means we’ve reached the end of the loop, so we return output
    accordingly.
    */


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