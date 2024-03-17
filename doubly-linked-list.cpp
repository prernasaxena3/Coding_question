#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory is free for data "<<value<<endl;
    }
};

void insertAtHead(Node* &head,Node* &tail,int data){
    //if list is empty
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }else{
        Node* temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    
}

void insertAtTail(Node* &head,Node* &tail,int data){
    //if empty
    if(tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }else{
        Node* temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* &tail,Node* &head,int pos,int d){
    //insert at start
    if(pos == 1){
        insertAtHead(head,tail,d);
        return;
    }

    Node* temp = head;
    int count = 1;
    while(count <pos-1){
        temp = temp->next;
        count++;
    }

    //insert at end
    if(temp->next == NULL){
        insertAtTail(head,tail,d);
        return ;
    }

    //inserting in middle
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void Deletion(int pos,Node* &head,Node* &tail){
    //deleting first node
    if(pos == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        //memory free
        temp->next = NULL;
        delete temp;

    }else{
        //deleting any middle or last node
        Node* prev = NULL;
        Node* curr = head;
        int count = 1;
        while(count < pos){
            prev = curr;
            curr = curr->next;
            count++;
        }
        //updating the tail while deleting the last node
        // if(curr->next == NULL){
        //     tail = prev;
        // }
        
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int getLength(Node* &head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    print(head);
    cout<<"length of linked list is "<<getLength(head)<<endl;
    //Node* head = NULL;
    //Node* tail = NULL;
}