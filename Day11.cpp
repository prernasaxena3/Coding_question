/*n this Leetcode Search Insert Position problem solution, we have Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order. You must write an algorithm with O(log n) runtime complexity.*/
//SOLUTION....
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = -1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] >= target){
                return i;
            }
        }
        return nums.size();
    }
};