//Given an integer array(0-based indexing) a of size n.
//Your task is to return the maximum value of the sum of i*a[i] for all 0<= i <=n-1, where a[i] is the element at index i in the array. 
//The only operation allowed is to rotate(clockwise or counterclockwise) the array any number of times


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
#define ll unsigned long long

class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
        }
        ll currSum = 0;
        for (int i = 0; i < n; ++i) {
            currSum += (ll)i * a[i];
        }
        ll maxi = currSum;
        for (int i = 1; i < n; ++i) {
            currSum = currSum + sum - (ll)n * a[n - i];
            maxi = max(maxi, currSum);
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends
