//merge-nodes-in-between-zeros

/*You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.
For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.
Return the head of the modified linked list.*/

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
    ListNode* mergeNodes(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        if (!head->next->val) {
            ListNode* node = new ListNode(head->val);
            node->next = mergeNodes(head->next->next);
            return node;
        }

        ListNode* next = mergeNodes(head->next);
        next->val += head->val;
        return next;
    }
};
