//QUESTION - The Celebrity Problem

//A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
//A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
//Return the index of the celebrity, if there is no celebrity return -1.

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution 
{
    private:
    bool knows(vector<vector<int> >& M,int a, int b, int n){
        if(M[a][b] ==1){
            return true;
        }else{
        return false;
        }
    }
    
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>s;
        //step1: insert all elements in stack
        for(int i = 0;i<n;i++){
            s.push(i);
        }
        
        //step2 : pop 2 elements and compare them 
        while(s.size() > 1){
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M,a,b,n)){
                s.push(b);
            }else{
                s.push(a);
            }
        }
        
        //step 3: verifying the potential celebrity 
        int ans = s.top();
        
        //Row check
        int zeroCount = 0;
        for(int i =0;i<n;i++){
            if(M[ans][i] == 0){
                zeroCount++;
            }
        }
        
        //ALL ZEROS
        if(zeroCount != n){
            return -1;
        }
        
        //Column check
        int oneCount = 0;
        for(int i = 0;i<n;i++){
            if(M[i][ans] == 1)
                oneCount++;
        }
        
        if(oneCount != n-1){ //n-1 = neglecting the diagonal element
            return -1;
        }
        return ans;
    }
};