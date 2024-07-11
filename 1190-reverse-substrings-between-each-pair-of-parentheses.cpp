//reverse-substrings-between-each-pair-of-parentheses

/*You are given a string s that consists of lower case English letters and brackets.
Reverse the strings in each pair of matching parentheses, starting from the innermost one.
Your result should not contain any brackets.*/

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        string ans;
        for(const char c : s){
            if( c == '('){
                st.push(ans.length());
            }else if( c == ')'){
                //reversing
                const int i = st.top();
                st.pop();
                reverse(ans.begin()+i,ans.end());
            }else{
                ans += c;
            }
        }
        return ans;

    }
};
