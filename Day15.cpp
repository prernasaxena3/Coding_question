// Question - subarrays with k different integers
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(k,nums) - atmost(k-1,nums);
    }
    int atmost(int k,vector<int>& nums){
        int i = 0;
        int j = 0;
        int count = 0;
        map<int,int>m;
        while(i<nums.size()){
            m[nums[i]]++;
            while(m.size()>k){
                auto it = m.find(nums[j]);
                it->second--;
                if(it->second == 0)m.erase(it);
                j++;
            }
            count += (i-j+1);
            i++;
        }
        return count;
    }
};