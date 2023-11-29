/*Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.*/
 //SOLUTION
 #include <bits/stdc++.h>
 #include<vector>
 using namespace std;
 class Solution {
    public:
    void backtrack(vector<vector<int>> &output, vector<int> &current, vector<int> &candidates, int remain, int start){
    if(remain < 0)
        return;
    else if(remain == 0)output.push_back(current);
    else {
        for(int i=start;i<candidates.size();i++){
            current.push_back(candidates[i]);
            backtrack(output, current, candidates, remain - candidates[i], i);
            current.pop_back();
        }
    }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> output;
    vector<int> current;
    sort(candidates.begin(), candidates.end());
    backtrack(output, current, candidates, target, 0);
    return output;
    }

};