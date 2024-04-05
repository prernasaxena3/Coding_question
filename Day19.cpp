//Question - LeetCode problem 1544: Make the String Great

#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    string makeGood(string s) {
        stack<char> c;
        string result ;
        for(char a:s){
            if(!c.empty() && abs(c.top()-a) == 32){
                c.pop();
            }else{
                c.push(a);
            }
        }
        while(!c.empty()){
            result = c.top() + result;
            c.pop();
        }
        return result;
    }
};