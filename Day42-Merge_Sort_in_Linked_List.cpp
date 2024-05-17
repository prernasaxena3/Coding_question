//question - merge sort in linked list
#include<iostream>
using namespace std;

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    

node* findMid(node* head){
    node* slow = head;
    node* fast = head->next;
    while(fast !=  NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

//not replacing the data but changing the links
node* merge(node* &left , node* &right){
    if(left == NULL)
        return right;
    if(right == NULL)
        return left;
    node* ans = new node(-1);
    node* temp = ans;
    while(left != NULL && right != NULL){
        if(left->data < right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    while(left != NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while(right != NULL){
        temp->next = right;
        temp = right;
        right = right->next;     
    }
    ans = ans->next;
    return ans;
}

node* mergeSort(node *head) {
    // Base Case
    if(head == NULL || head->next == NULL){
        return head;
    }
    //finding mid element 
    node* mid = findMid(head);

    //dividing the list into two halves
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    //recursively call for both halves
    left = mergeSort(left);
    right = mergeSort(right);

    //sorting the two sorted lists
    node* ans = merge(left,right);
    return ans;
}
