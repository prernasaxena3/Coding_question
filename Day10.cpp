/* QUESTION 1: Roman to Integer - leetcode problem*/
//SOLUTION
#include<iostream>
#include<map>
#include<string>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        map<char,int> roman = { { 'I' , 1 },
                                { 'V' , 5 },
                               { 'X' , 10 },
                               { 'L' , 50 },
                               { 'C' , 100 },
                               { 'D' , 500 },
                               { 'M' , 1000 } };
        //roman.insert(make_pair('I',1));
        int len = s.length(),num,sum = 0;
        for(int i = 0;i<len; ){
            if(i == (len-1) || (roman[s[i]] >= roman[s[i+1]])){
                num = roman[s[i]];
                i++;
            }
            else{
                num = roman[s[i+1]]-roman[s[i]];
                i = i+2;
            }
            sum = sum +num;
        }
        return sum;
    }
};

/*Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.*/
//SOLUTION
#include<vector>
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] != val){
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};