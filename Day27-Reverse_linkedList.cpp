//question - reverse linked list

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:
    
*****************************************************************/
    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };


/*void reverselist(LinkedListNode<int>* &head, LinkedListNode<int>  *curr,LinkedListNode<int> *prev){
    //base case
    if(curr == NULL){
        head = prev;
        return;
    }

    LinkedListNode<int> *forward = curr->next;
    reverse(head,forward,curr);
    curr->next = prev;

}  */

/*LinkedListNode<int> *reverse1(LinkedListNode<int> *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    LinkedListNode<int> *head1 = reverse1(head->next);
    head->next->next = head;
    head->next = NULL;
    return head1;
}   */

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    //ITERATIVE SOLUTION
   if(head == NULL || head->next == NULL){
        return head;
    }
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    while(curr != NULL){
        LinkedListNode<int> *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;  

    //RECURSIVE SOLUTION
   /* LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    reverselist(head,curr,prev);
    return head;  */

    //ANOTHER RECURSIVE APPROACH
    // reverse1(head);
}

