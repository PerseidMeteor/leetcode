/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//test
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head || !head->next)
            return NULL;
        ListNode *p1 = head, *p2 = head;
        int i = 0;
        while (i < n)
        {
            p1 = p1->next;
            i++;
        }
        if (!p1)
            return head->next;

        while (p1->next != NULL)
        {

            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = p2->next->next;
        return head;
    }
};