/*The distance of a pair of integers a and b is defined as the absolute difference between a and b.
Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.
*/

class Solution {
public:
    int helper(vector<int>& nums, int k,int mid){
        int count = 0;
        int j = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            while(j<n && (nums[j]-nums[i]) <= mid){
                j++;
            }
            count += (j-i-1);
        }
        return count;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        // vector<int>dist;
        // for(int i = 0;i<nums.size();i++){
        //     for(int j = i+1;j<nums.size();j++){
        //         dist.push_back(abs(nums[i]-nums[j]));
        //     }
        // }
        // sort(dist.begin(),dist.end());
        // int ans = dist[k-1];
        // return ans;

        sort(nums.begin(),nums.end());
        int n = nums.size();
        int low = 0;
        int high = nums[n-1]-nums[0];
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int count = helper(nums,k,mid);
            if(count>=k)
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        return ans;
    }
};
