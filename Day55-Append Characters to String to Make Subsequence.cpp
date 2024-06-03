//QUESTION : 2486. Append Characters to String to Make Subsequence
/*You are given two strings s and t consisting of only lowercase English letters.
Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.
A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.  */


#include<iostream>
using namespace std;
class Solution {
public:
    int appendCharacters(string s, string t) {
        int m = s.size();
        int n = t.size();
        for(int i = 0,j = 0;j<n;j++){
            while(i<m && s[i] != t[j]){
                i++;
            }if(i++ == m){
                return n-j;
            }
        }
        return 0;
    }
};