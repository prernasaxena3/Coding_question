//subarray-sums-divisible-by-k

/*Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
A subarray is a contiguous part of an array.

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]*/


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mod_map;
        mod_map[0] = 1; // To handle cases where the sum itself is a multiple of k
        int cum_sum = 0;
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            cum_sum += nums[i];
            int mod = (cum_sum % k + k)%k; //to handle negative mod values
            
            if (mod_map.find(mod) != mod_map.end()) {
                count += mod_map[mod];
            }
            mod_map[mod]++;
        }
        
        return count;
    }
};
