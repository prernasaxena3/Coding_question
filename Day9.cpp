/*PALINDROME NUMBER*/
//SOLUTION
class Solution {
public:
    bool isPalindrome(int x) {
        long int m = x;
        long int ans = 0;
        while(m >0){
            int a = m%10;
            ans = 10*ans + a;
            m = m/10;
        }
        return ans == x;
    }
};

/*QUESTION 2: Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.*/
//SOLUTION

#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> ans;
        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                ans.push(c);
            }else{
                if (ans.empty()){
                    return false;
                }
                if(c == ')' && ans.top() == '('){
                    ans.pop();
                }
                else if(c == '}' && ans.top() == '{'){
                    ans.pop();
                }
                else if(c == ']' && ans.top() == '['){
                    ans.pop();
                }else{
                    return false;
                }
            }
        }
        if(ans.empty()){
            return true;
        }else{
            return false;
        }
    }
};