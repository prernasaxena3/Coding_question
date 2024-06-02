//Construct list using given q XOR queries
/*Given a list s that initially contains only a single value 0. There will be q queries of the following types:

0 x: Insert x in the list
1 x: For every element a in s, replace it with a ^ x. ('^' denotes the bitwise XOR operator)
Return the sorted list after performing the given q queries.

Example 1:

Input:
q = 5
queries[] = {{0, 6}, {0, 3}, {0, 2}, {1, 4}, {1, 5}}
Output:
1 2 3 7
Explanation:
[0] (initial value)
[0 6] (add 6 to list)
[0 6 3] (add 3 to list)
[0 6 3 2] (add 2 to list)
[4 2 7 6] (XOR each element by 4)
[1 7 2 3] (XOR each element by 5)
The sorted list after performing all the queries is [1 2 3 7]. */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
  public:
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        vector<int>result = {0};
        int count  = 0;
        for(const auto& query : queries){
            int type = query[0];
            int x = query[1];
            
            if(type == 0){
                //insert x into list
                result.push_back(x^count);
            }else if(type == 1){
                //update XOR
                count ^= x;
            }
        }
        // Apply the XOR to all elements in the list
        for(auto& a : result){
            a ^= count;
        }
        
        sort(result.begin(),result.end());
        return result;
    }
};