//find-missing-observations

/*You have observations of n + m 6-sided dice rolls with each face numbered from 1 to 6. n of the observations went missing, and you only have the observations of m rolls.
Fortunately, you have also calculated the average value of the n + m rolls.
You are given an integer array rolls of length m where rolls[i] is the value of the ith observation. You are also given the two integers mean and n.
Return an array of length n containing the missing observations such that the average value of the n + m rolls is exactly mean. 
If there are multiple valid answers, return any of them. If no such array exists, return an empty array.
The average value of a set of k numbers is the sum of the numbers divided by k.
Note that mean is an integer, so the sum of the n + m rolls should be divisible by n + m.*/

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        vector<int>arr;
        for(int i = 0;i<m;i++){
            sum += rolls[i];
        }
        int remainingSum = (mean*(n+m))-sum;
        if(remainingSum < n || remainingSum > 6*n){
            return {};
        }
        int distributeMean = remainingSum/n;
        int increament = remainingSum%n;
        for(int i = 0;i<n;i++){
            arr.push_back(distributeMean);
        }
        for(int i = 0;i<increament;i++){
            arr[i]++;
        }
        return arr;
    }
};
