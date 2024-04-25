//Question - 2370 Longest Ideal Subsequence
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int>dp(26,0);
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            int element = s[i]-'a';
            // a = 0,b = 1,c = 2
            //left limit
            for(int j = element;j>=0 && j>=element-k;j--){
                dp[element] = max(dp[element],dp[j]+1);
            }
            //right limit
            for(int j = element+1;j<26 && j<=element+k;j++){
                dp[element] = max(dp[element],dp[j]+1);
            }
            ans = max(ans,dp[element]);
        }
        return ans;
    }
};