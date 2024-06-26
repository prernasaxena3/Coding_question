
/* Given two arrays of integers a[] and b[] of size n and m, the task is to check if a pair of values (one value from each array) exists such that swapping the elements of the pair will make the sum of two arrays equal.

Note: Return 1 if there exists any such pair otherwise return -1. 
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        int sumA = accumulate(a,a+n,0);
        int sumB = accumulate(b,b+m,0);
        if((sumA-sumB) % 2 != 0){
            return -1;
        }
        int target = (sumA-sumB)/2;
        unordered_set<int>s(b,b+m);
        for(int i = 0;i<n;i++){
            if(s.find(a[i]-target) != s.end()){
                return 1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
