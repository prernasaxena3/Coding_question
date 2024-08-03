//make-two-arrays-equal-by-reversing-subarrays

/*You are given two integer arrays of equal length target and arr. In one step, you can select any non-empty subarray of arr and reverse it. You are allowed to make any number of steps.
Return true if you can make arr equal to target or false otherwise.*/

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        bool ans = true;
        sort(arr.begin(),arr.end());
        sort(target.begin(),target.end());
        for(int i = 0;i<arr.size();i++){
            if(arr[i] != target[i]){
                ans = false;
            }
        }
        return ans;
    }
};
