//Question -  Sort linked list of 0s 1s 2s
//Given a linked list of 'N' nodes, where each node has an integer value that can be 0, 1, or 2. You need to sort the linked list in non-decreasing order and the return the head of the sorted list.

#include<iostream>
using namespace std;

/*Following is the class structure of the Node class: */

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

void insertATtail(Node* &tail,Node* curr){
    tail->next = curr;
    tail = curr;
}

Node* sortList(Node *head){

    //by counting the zeros, ones and twos
    /*
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    Node* temp = head;
    while(temp){
        if(temp->data == 0){
            zeroCount ++;
        }else if(temp->data == 1){
            oneCount++;
        }else if(temp->data == 2){
            twoCount++;
        }
        temp = temp->next;
    }
    temp = head;
    while(temp){
        if(zeroCount != 0){
            temp->data = 0;
            zeroCount--;
        }else if(oneCount != 0){
            temp->data = 1;
            oneCount--;
        }else if(twoCount != 0){
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
    return head;*/

    //making three list
    //using dummy nodes to avoid bunch of if statements
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    //creating the list
    Node* curr = head;
    while(curr){
        if(curr->data == 0){
            insertATtail(zeroTail,curr);
        }
        else if(curr->data == 1){
            insertATtail(oneTail,curr);
        }
        else if(curr->data == 2){
            insertATtail(twoTail,curr);
        }
        curr = curr->next;
    }

    //merging the list
    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    }else{
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    //setup head 
    head = zeroHead->next;

    //deleting dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}