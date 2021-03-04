/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {


        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        int l1 = 0;
        int l2 = 0;

        while (temp1 != NULL)
        {
            l1++;
            temp1 = temp1->next;
        }

        while (temp2 != NULL)
        {
            l2++;
            temp2 = temp2->next;
        }

        temp1 = headA;
        temp2 = headB;

        if (l1 > l2)
        {
            for (int i = 0; i < l1 - l2; i++)
            {
                temp1 = temp1->next;
            }
        }

        else
        {
            for (int i = 0; i < l2 - l1; i++)
            {
                temp2 = temp2->next;
            }
        }

        while (temp1 != temp2)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return temp1;


    }
};