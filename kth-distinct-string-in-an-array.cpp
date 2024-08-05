//kth-distinct-string-in-an-array

/*A distinct string is a string that is present only once in an array.
Given an array of strings arr, and an integer k, return the kth distinct string present in arr. If there are fewer than k distinct strings, return an empty string "".
Note that the strings are considered in the order in which they appear in the array.*/

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int>m;
        for(const string& s: arr){
            ++m[s];
        }
        for(const string& s:arr){
            if(m[s] == 1 && --k == 0){
                return s;
            }
        }
        return "";
  }
};
