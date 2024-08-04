//range-sum-of-sorted-subarray-sums

/*You are given the array nums consisting of n positive integers. 
You computed the sum of all non-empty continuous subarrays from the array and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.
Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. 
Since the answer can be a huge number return it modulo 109 + 7.*/

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>subsum;
        for(int i = 0;i<n;i++){
            int sum = 0;
            for(int j = i;j<n;j++){
                sum += nums[j];
                subsum.push_back(sum);
            }
        }
        int ans = 0;
        sort(subsum.begin(),subsum.end());
        int size = subsum.size();

        //out of bound array condition
        // left = max(1,left);
        // right = min(size, right);

        for(int i = left-1; i<right;i++){
            ans += subsum[i];
            ans %= 1000000007;
        }
        return ans;
    }
};
