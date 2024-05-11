//Question - check if Linked List is palindrome

#include<iostream>
#include<vector>
using namespace std;

/*Definition for singly-linked list.*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution{
  private:
    ListNode* getMid(ListNode* head ) {
        ListNode* slow = head;
        ListNode* fast = head -> next;
        
        while(fast != NULL && fast-> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        return slow;
    }
    ListNode* reverse(ListNode* head) {
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(ListNode *head)
    {
        if(head -> next == NULL) {
            return true;
        }
        
        //step 1 -> find Middle
        ListNode* middle = getMid(head);
        //cout << "Middle " << middle->data << endl;
        
        //step2 -> reverse List after Middle
        ListNode* temp = middle -> next;
        middle -> next = reverse(temp);
        
        //step3 - Compare both halves
        ListNode* head1 = head;
        ListNode* head2 = middle -> next;
        
        while(head2 != NULL) {
            if(head2->val != head1->val) {
                return 0;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
    
        //step4 - repeat step 2
        temp = middle -> next;
        middle -> next = reverse(temp);
        
        return true;
    }
};



//SECOND APPROACH....................

/*
#include<vector>
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
class Solution{
    private:
    
    bool check(vector<int> ans){
        int n = ans.size();
        int s = 0;
        int e = n-1;
        while(s<=e){
            if(ans[s] != ans[e]){
                return false;
            }
            s++;
            e--;
            
        }
        return true;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        vector<int>ans;
        // int i = 0;
        Node* temp = head;
        while(temp){
           ans.push_back(temp->data); 
           temp = temp->next;
        }
        return check(ans);
    }
};
*/