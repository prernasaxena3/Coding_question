//Question Maximum Nesting Depth of the Parentheses. (Leetcode 1614)

#include <iostream>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, open = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if(c == '('){
                open++;
            }if(c == ')'){
                open--;
            }
            depth = max(depth,open);
        }
        return depth;
    }
};