//Question - reverse list in K groups 
#include<iostream>
using namespace std;
/** Definition for singly-linked list.  **/
  class Node {
     public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
 };


    Node* _reverseKGroup(Node* head, int size, int k){
        if(head==nullptr || size<k) return head;
        Node* prev=nullptr, *cur=head, *next=nullptr;
        int count=0;
        while(cur!=nullptr && count<k){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            count++;
        }
        head->next=_reverseKGroup(next, size-k, k);
        return prev;
    }
    Node* kReverse(Node* head, int k) {
        int size=0;
        Node* temp=head, *root;
        while(temp!=nullptr){
            temp=temp->next;
            size++;
        }
        return _reverseKGroup(head, size, k);
    }
