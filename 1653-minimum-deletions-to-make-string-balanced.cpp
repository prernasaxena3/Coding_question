//minimum-deletions-to-make-string-balanced

/*You are given a string s consisting only of characters 'a' and 'b'​​​​.
You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.
Return the minimum number of deletions needed to make s balanced.*/

class Solution {
public:
    int minimumDeletions(string s) {
        int deletion = 0;
        int n = s.length();
        int countB = 0;
        for(int i =0;i<n;i++){
            if(s[i] == 'b'){
                countB++;
            }else if(s[i] == 'a'){
                deletion = min(deletion+1,countB);
            }
        }
        return deletion;
    }
};
