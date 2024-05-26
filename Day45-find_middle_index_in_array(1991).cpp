//A middleIndex is an index where nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1].
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int left = 0;
        //accumulate function returns the sum of all values lying under the range(start,end) with variable sum
        int right = accumulate(nums.begin(),nums.end(),0);
        for(int i = 0;i<nums.size();i++){
            right -= nums[i];
            if(left == right){
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};