/*
There are 2 approaches to solving the problem.

Approach 1 : Using heap.
At every instant, you need the minimum of the head of all the k linked list. Once you know the minimum, you can push the node to your answer list, and move over to the next node in that linked list.

Approach 2 : Divide and conquer.
Solve the problem for first k/2 and last k/2 list. Then you have 2 sorted lists. Then simiply merge the lists.
Analyze the time complexity.
T(N) = 2 T(N/2) + N
T(N) = O (N log N)
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		// Create an ordered map
		map<int, int> nodes;

		// Add all nodes of all the LinkedLists to the map with
		// with the ListNode->val as the key & that value's frequency as the mapped value
		for (int i = 0; i < lists.size(); ++i) {
			auto node = lists[i];
			while (node) {
				int temp = node->val;
				nodes[temp]++;
				node = node->next;
			}
		}

		ListNode dummyHead(0);
		ListNode* tail = &dummyHead;

		for (auto it : nodes) {
			while (it.second != 0) {
				ListNode* newNode = new ListNode(it.first);
				tail->next = newNode;
				tail = tail->next;
				it.second--;
			}
		}
		return dummyHead.next;
	}
};

/*
APPROACHES:
1.PRIORITY_QUEUE


class Solution {
public:
    struct comp
    {
        bool operator()(ListNode* a,ListNode*b)
        {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& l) {
     //base case
        if(l.empty() or l.size()==0)
            return NULL;
        //Min heap
        priority_queue<ListNode *, vector<ListNode *>, comp> pq;

        for(auto list:l)
            if(list) pq.push(list);

        ListNode dummyHead(0);
        ListNode *dumb = &dummyHead;

        while(!pq.empty())
        {
            // store and pop top ele
            auto temp=pq.top();
            pq.pop();

            // store the ele in the list
            dumb->next=temp;
            dumb=dumb->next;

             // if there are more nodes attached to this node in the list
            // Push the next node of the list into the heap
            if(temp->next)
                pq.push(temp->next);
        }
    // Make sure you set the next pointer of the last added node to NULL
        dumb->next=NULL;
     // We used the dummyHead to keep track of the start of the list.
        return dumnb.next;
    }
};
2.MAP

*/







class Solution {
public:

	struct CompareNode {
		bool operator()(ListNode* const & p1, ListNode* const & p2) {
			// return "true" if "p1" is ordered before "p2", for example:
			return p1->val > p2->val;
		}
	};
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		ListNode* dummy = new ListNode(0);
		ListNode* tail = dummy;

		priority_queue<ListNode*, vector<ListNode*>, CompareNode> queue;

		for (int i = 0; i < lists.size(); i++) {
			if (lists[i] != NULL) {
				queue.push(lists[i]);
			}
		}

		while (!queue.empty()) {
			tail->next = queue.top();
			queue.pop();
			tail = tail->next;

			if (tail->next) {
				queue.push(tail->next);
			}
		}

		return dummy->next;
	}
};






ListNode* Solution::mergeKLists(vector<ListNode*> &lists) {
	ListNode* head = new ListNode(0);
	if (lists.size() == 0) {return NULL;}
	head->next = lists[0];
	ListNode *p;
	ListNode *q;
	for (int i = 1; i < lists.size(); i++) {
		p = head;
		q = lists[i];
		while (q) {
			if (!p->next) {
				p->next = q;
				break;
			}
			if (p->next->val < q->val) {
				p = p->next;
			} else {
				ListNode *l = p->next;
				p->next = q;
				q = q->next;
				p->next->next = l;
				p = p->next;
			}
		}
	}
	return head->next;
}








