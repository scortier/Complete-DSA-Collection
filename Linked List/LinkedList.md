Description
One of the basic structures in algorithm which can be used to achieve lots of funny algorithms and problems.

Problems
There will be some of the most typical problems in this aspect, which I believe almost covers all the basic techniques that you need to solve a linked list problem.

Remove Duplicates from Sorted List
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

Solution
We can just solve it like in an array using another index to collect the valid nodes. Here, once I made a serious mistake inserting extra ; after while which directly result in an in-debuggeable situation.

ListNode* deleteDuplicates(ListNode* head) {
    if(!head) return head;
    ListNode *t = head, *p = head->next;
    int pre = head->val;
    while(p) {
        if(pre != p->val) {
            t->next = p;
            pre = p->val;
            t = t->next;
        }
        p = p->next;
    }
    t->next = NULL;
    return head;
}
Remove Duplicates from Sorted List II
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

Solution
Iterative
ListNode* deleteDuplicates(ListNode* head) {
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode* cur = dummy;
	int duplicate;
	while (cur->next && cur->next->next) {
		if (cur->next->val == cur->next->next->val) {
			duplicate = cur->next->val;
			while (cur->next && cur->next->val == duplicate) 
				cur->next = cur->next->next;
		}
		else cur = cur->next;
	}
	return dummy->next;
}
Recursive
ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return 0;
    if (!head->next) return head;
    int val = head->val;
    ListNode* p = head->next;
    if (p->val != val) { head->next = deleteDuplicates(p); return head;} 
    else { 
        while (p && p->val == val) p = p->next; 
        return deleteDuplicates(p); 
    }
}
Palindrome Linked List
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

Solution
Converting the linked list into an array to simplify the checking.

bool isPalindrome(ListNode* head) {
    vector<int> v;
    while(head) {
        v.push_back(head->val);
        head = head->next;
    }
    for(int i = 0; i < v.size()/2; ++i) {
        if(v[i] != v[v.size()-i-1]) return false;
    }
    return true;
}
Just do it using linked list

bool isPalindrome(ListNode* head) {
    if(!head || !head->next) return true;
    ListNode *slow = head, *fast = head->next;
    while(fast && fast->next) {//split into two halves while the first half can be one-node longer;
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;
    ListNode newHead(0); //reverse the second half;
    ListNode *next = NULL, *p = fast;
    while(p) {
        next = p->next;
        p->next = newHead.next;
        newHead.next = p;
        p = next;
    }
    fast = newHead.next; //compare the two lists;
    while(fast) {
        if(fast->val != head->val) return false;
        fast = fast->next;
        head = head->next;
    }
    return fast == NULL;
}
Rotate List
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

Solution
ListNode* rotateRight(ListNode* head, int k) {
    if(!head) return head;
    int len = 1;
    ListNode *p = head;
    while(p->next) { len++; p = p->next; }
    p->next = head;
    if(k %= len)
        for(int i = 0; i < len-k; ++i, p=p->next) ; 
    ListNode* newHead = p->next;
    p->next = NULL;
    return newHead;
}
Add Two Numbers
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Solution
Iterative
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int c = 0;
    ListNode newHead(0);
    ListNode *t = &newHead;
    while(c || l1 || l2) {
        c += (l1? l1->val : 0) + (l2? l2->val : 0);
        t->next = new ListNode(c%10);
        t = t->next;
        c /= 10;
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    return newHead.next;
}
Recursive
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if(!l1 && !l2) return NULL;
    int c = (l1? l1->val:0) + (l2? l2->val:0);
    ListNode *newHead = new ListNode(c%10), *next = l1? l1->next:NULL;
    c /= 10;
    if(next) next->val += c;
    else if(c) next = new ListNode(c);
    newHead->next = addTwoNumbers(l2? l2->next:NULL, next);
    return newHead;
}
Reverse Linked List II
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.

Note: Given m, n satisfy the following condition: 1 ≤ m ≤ n ≤ length of list.

Solution
ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode newHead(0);
    newHead.next = head;
    ListNode *pre = &newHead, *cur = head, *next = NULL;
    int i = 1;
    while(i < n) {
        if(i++ < m) { pre = cur; cur = cur->next; }
        else { 
            next = cur->next; 
            cur->next = cur->next->next; 
            next->next = pre->next; 
            pre->next = next; 
        }
    }
    return newHead.next;
}
Linked List Cycle II
Given a linked list, return the node where the cycle begins. If there is no cycle, return null. Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?

Solution
Actually we can just use set.insert(key).second to check but it will take up O(n) space which is quite an awful waste, so here we just going to check the circle and then locate it.

If there is a circle then once the slow meets the fast the first time, there will be a formula as follows: a+b+kl = 2(a+b) -> kl-b = a (a is the length between the head and the start of the circle, b is the steps the slow pointer moves in the circle while l is the length of the circle).
After that we can reset the fast and slow down the fast (same speed as the slow using kl-b = a) then once they meet again, the location will be the start of the circle.
At last we take up constant space to solve this and traverse the linked list twice at most (as for the slow pointer).

ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;   
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    if(slow != fast) return NULL;
    fast = head;
    while(fast && fast->next) {
        if(slow == fast) return slow;
        slow = slow->next;
        fast = fast->next;
    }
    return NULL;
}
Copy List with Random Pointer
linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.

test

Solution
Recursive
class Solution {
    unordered_map<RandomListNode*, RandomListNode*> cloneMap;
    RandomListNode *helper(RandomListNode* head){
        if(head == NULL) return NULL;
        if(cloneMap.count(head)) return cloneMap[head];
        RandomListNode *cloned = new RandomListNode(head->label);
        cloneMap[head] = cloned; //crucial;
        cloned->next = helper(head->next);
        cloned->random = helper(head->random);
        return cloned;
    }
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        return helper(head);
    } 
};
Iterative
RandomListNode *copyRandomList(RandomListNode *head) {
	RandomListNode newHead(0), *p = head, *t = NULL;
	while(p) {
		RandomListNode *cloned = new RandomListNode(p->label);
		cloned->next = p->next;
		p->next = cloned;
		p = cloned->next;
	}
	p = head;
	while(p && p->next) {
		if(p->random) p->next->random = p->random->next;
		p = p->next->next;
	}
	p = head;
	t = &newHead;
	while(p && p->next) {
		t->next = p->next;
		p->next = p->next->next;
		t = t->next;
		p = p->next;
	}
	t->next = NULL;
	return newHead.next;
}
Reverse Nodes in k-Group
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is. You may not alter the values in the nodes, only nodes itself may be changed. Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5

Solution
ListNode* reverseKGroup(ListNode* head, int k) {
	if(!head || !head->next) return head;
	ListNode newHead(0);
	ListNode *pre = &newHead, *cur = head, *next = NULL;
	newHead.next = head;
	int len = 0;
	for(ListNode *p = head; p; p = p->next) len++;
	int times = len/k;
	while(times) {
		for(int i = 1; i < k; ++i) {
			next = cur->next;
			cur->next = cur->next->next;
			next->next = pre->next;
			pre->next = next;
			if(i == k-1) {
				pre = cur;
				cur = cur->next;
			}
		}
		times--;
	}
	return newHead.next;
}