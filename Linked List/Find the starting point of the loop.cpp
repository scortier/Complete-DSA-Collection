Node* Start_point(Node* head)
{
	if (head == NULL or head->next == NULL)
		return NULL;

	Node*slow = head, *fast = head;

	slow = slow->next;
	fast = fast->next->next;

	while (fast and fast->next)
	{
		if (slow == fast)
			break;
		slow = slow->next;
		fast = fast->next->next;
	}
// If loop does not exist
	if (slow != fast)
		return NULL;

	// If loop exists. Start slow from
	// head and fast from meeting point.
	slow = head;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}


//Using Hashing
Node* detectCycle(Node* A)
{

	// declaring map to store node address
	unordered_set<Node*> uset;

	Node *ptr = A;

	// Default consider that no cycle is present
	while (ptr != NULL) {

		// checking if address is already present in map
		if (uset.find(ptr) != uset.end())
			return ptr;

		// if address not present then insert into the set
		else
			uset.insert(ptr);

		ptr = ptr->next;
	}
	return NULL;
}