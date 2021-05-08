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

/*
Edge cases :
1. l1>l2
2. l2>l1
3. l1==l2

create a dummy node (val as 0)
cal the sum of starting node at put val in newnode next to dummy node.
then assignned dummy node to its next
and cal carry of curr sum by sum/10 which will be used to add in next sum.

ths whole process will go till (l1!=0 or l2!=0 or carry!=0)

now to return
as dummy k next se list ho rhi so vha se return kardo.
*/
//dummy as head
// temp as dummy ka next
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, first, second;
        ListNode *dummy = new ListNode(0), *temp = dummy;
        while (l1 || l2 || carry)
        {
            if (l1) {
                first = l1->val;
                l1 = l1->next;
            }
            else first = 0;

            if (l2)
            {
                second = l2->val;
                l2 = l2->next;
            }
            else second = 0;
//this line before cal carry as carry baad wale node m add horha naaki pehle wale m ,dry run u will understand
            int sum = first + second + carry;
            //new node created just next to dummy node
            temp->next = new ListNode(sum % 10);

            //dummy ko abhi jo node bnaya vo assign kardo
            temp = temp->next;

            carry = sum / 10; // to add carry of curr sum to next link ele
        }

        //as list toh dummy k next se hi start ho rha
        return dummy->next;
    }
};