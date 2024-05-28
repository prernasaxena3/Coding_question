#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Next Smaller Element
//You are given an array 'ARR' of integers of length N. Your task is to find the next smaller element for each of the array elements.
// Next Smaller Element for an array element is the first element to the right of that element which has a value strictly smaller than that element.
// If for any array element the next smaller element does not exist, you should print -1 for that array element.

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int>s;
    vector<int>ans(n);
    s.push(-1);
    for(int i = n-1;i>=0;i--){
       int curr = arr[i];
       while(s.top() >= curr){
           s.pop();
       }
       ans[i] = s.top();
       s.push(curr);
    }
    return ans;
}