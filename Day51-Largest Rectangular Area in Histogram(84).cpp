//Question - Largest Rectangular Area in Histogram
//Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
#include<climits>
using namespace std;
class Solution {
    vector<int> nextSmaller(vector<int>arr, int n){
        stack<int>s;
        vector<int>ans(n);
        s.push(-1);
        for(int i = n-1;i>=0;i--){
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int>arr,int n){
        stack<int>s;
        vector<int>ans(n);
        s.push(-1);
        for(int i = 0;i<n;i++){
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>next(n);
        next = nextSmaller(heights,n);

        vector<int>prev(n);
        prev = prevSmaller(heights,n);

        int area = INT_MIN;
        for(int i = 0;i<n;i++){
            if(next[i] == -1){
                next[i] = n;
            }
            int l = heights[i];
            int b = next[i]-prev[i]-1;
            int newArea = l*b;
            area = max(area,newArea);
        }
        return area;
    }
};