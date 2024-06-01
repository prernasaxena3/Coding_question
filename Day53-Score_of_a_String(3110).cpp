//Question - Score Of a String Leetcode - 3110
// You are given a string s. The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.

#include <iostream>
using namespace std;
class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        for(int i = 1;i<s.size();i++){
            char a = s[i];
            char b = s[i-1];
            ans += abs(int(a) - int(b));
        }
        return ans;
    }
};