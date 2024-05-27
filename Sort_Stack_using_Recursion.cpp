#include <bits/stdc++.h> 
#include <stack>
using namespace std;

//Question - Sort a Stack Using Recursion

void sorted(stack<int> &s,int n){
	//base case
	if(s.empty() || (!s.empty() && s.top()<n)){
		s.push(n);
		return ; 
	}
	int num1  = s.top();
	s.pop();
	sorted(s,n);
	s.push(num1);
}

void sortStack(stack<int> &stack)
{
	//base case
	if(stack.empty()){
		return ;
	}
	int num = stack.top();
	stack.pop();

	sortStack(stack);

	//sorted stack
	sorted(stack,num);
}