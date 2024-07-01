//three-consecutive-odds
//Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for(const int i :arr){
            count = i%2 == 1 ? count+1 : 0;
            if(count == 3){
                return true;
            }
        }
        return false;
    }
};
