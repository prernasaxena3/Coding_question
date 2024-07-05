//find-the-minimum-and-maximum-number-of-nodes-between-critical-points

/*A critical point in a linked list is defined as either a local maxima or a local minima.
A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.
A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.
Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.
Given a linked list head, return an array of length 2 containing [minDistance, maxDistance]
where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. 
If there are fewer than two critical points, return [-1, -1].*/

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next){
            return {-1,-1};
        }
        ListNode* prev = head;
        ListNode* curr = prev->next;
        ListNode* next = curr->next;
        vector<int>v;
        int cnt = 1;
        while(next){
            if((curr->val > prev->val && curr->val > next->val) || (curr->val < prev->val && curr->val < next->val)){
                v.push_back(cnt);
            }            
            cnt++;
            prev = curr;
            curr = next;
            next = next->next; 
        }
        
        if(v.size()<2)
            return {-1,-1};
        int mini = INT_MAX;
        for(int i = 1;i<v.size();i++)
            mini = min(mini,v[i]-v[i-1]);

        return {mini,v.back()-v[0]};
    }
};
