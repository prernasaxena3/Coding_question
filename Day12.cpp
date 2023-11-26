/*Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.*/
//SOLUTION
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] != nums[k]){
                ++k;
                nums[k] = nums[i];
            }
        }
        nums.resize(k+1);
        return nums.size();
    }
};