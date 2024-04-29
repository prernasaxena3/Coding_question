//Question - 2997 - leetcode - Minimum Number of operations to make array XOR equals to K
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for (int x : nums) {
            k ^= x;
        }
        return __builtin_popcount(k);
    }
};