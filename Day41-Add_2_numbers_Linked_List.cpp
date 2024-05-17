//Question - adding 2 numbers representing by linked list
#include<iostream>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
class Solution
{
    private:
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void insertAtTail(Node* &head,Node* &tail,int val){
        Node* temp = new Node(val);
        
        //emptylist
        if(head == NULL){
            head = temp;
            tail = temp;
            return ;
        }else{
            tail->next = temp;
            tail = temp;
        }
    }
    
    struct Node* add(struct Node* num1, struct Node* num2){
        int carry = 0;
        
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        while(num1 != NULL || num2 != NULL || carry != 0){
            int val1 = 0, val2 =0;
            if(num1){
                val1 = num1->data;
            }
            if(num2){
                val2 = num2->data;
            }
            
            int sum = val1 + val2 + carry;
            int digit = sum%10;
            
            insertAtTail(ansHead,ansTail,digit);
            
            carry = sum/10;
            
            if(num1 != NULL){
                num1 = num1->next;
            }
            
            if(num2 != NULL){
                num2 = num2->next;
            }
        }
        return ansHead;
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        //step1 - Reversing the list
        num1 = reverse(num1);
        num2 = reverse(num2);
        
        //step2 - adding the list
        Node* ans = add(num1,num2);
        
        //step3 - reversing the list
        ans = reverse(ans);
        
        while((ans->data)==0&&ans->next!=NULL){
           Node* temp=ans;
           delete(temp);
           ans=ans->next;
       }
        return ans;
    }
};