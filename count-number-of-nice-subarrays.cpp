//count-number-of-nice-subarrays
/*Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].*/


class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numberOfSubarraysAtMost(nums, k) -
           numberOfSubarraysAtMost(nums, k - 1);
    }

 private:
  int numberOfSubarraysAtMost(vector<int>& nums, int k) {
    int ans = 0;

    for (int l = 0, r = 0; r <= nums.size();)
      if (k >= 0) {
        ans += r - l;
        if (r == nums.size())
          break;
        if (nums[r] & 1)
          --k;
        ++r;
      } else {
        if (nums[l] & 1)
          ++k;
        ++l;
      }

    return ans;
    }
};
