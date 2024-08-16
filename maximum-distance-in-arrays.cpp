//maximum-distance-in-arrays

/*You are given m arrays, where each array is sorted in ascending order.
You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.
Return the maximum distance.

Example 1:

Input: arrays = [[1,2,3],[4,5],[1,2,3]]
Output: 4
Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.*/

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minV = arrays[0].front();
        int maxV = arrays[0].back();
        int result = 0;
        for(int i = 1;i<arrays.size();i++){
            result = max(result,max(abs(arrays[i].back()-minV),abs(maxV-arrays[i].front())));
            minV = min(minV,arrays[i].front());
            maxV = max(maxV,arrays[i].back());

        }
        return result;
    }
};
