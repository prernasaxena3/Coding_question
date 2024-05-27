#include <iostream>
#include<stack>
using namespace std;

//Question - reverse stack using recursion

void insertAtBottom(stack<int> &stack,int num){
    //base case
    if(stack.empty()){
        stack.push(num);
        return;
    }
    
    int num1 = stack.top();
    stack.pop();
    insertAtBottom(stack,num);
    stack.push(num1);
}

void reverseStack(stack<int> &stack) {
    //base case
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();
    
    //recursive call for reversal of remaining stack
    reverseStack(stack);

    //insert at bottom
    insertAtBottom(stack,num);
}