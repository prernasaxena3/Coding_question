//minimum-difference-between-largest-and-smallest-value-in-three-moves
/*You are given an integer array nums.
In one move, you can choose one element of nums and change it to any value.
Return the minimum difference between the largest and smallest value of nums after performing at most three moves.*/

class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n <=3) return 0;
        int diff =  INT_MAX;
        for(int i = 0;i<4;i++){
            diff = min(diff, nums[n-1-i]-nums[3-i]);
        }
        
        return diff;
    }
};
