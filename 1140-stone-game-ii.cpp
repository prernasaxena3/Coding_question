//stone-game-ii

/*Alice and Bob continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]. 
The objective of the game is to end with the most stones. 
Alice and Bob take turns, with Alice starting first.  Initially, M = 1.
On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).
The game continues until all the stones have been taken.
Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

Example 1:

Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total. 
If Alice takes two piles at the beginning, then Bob can take all three piles left.
In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since it's larger.*/

class Solution {
public:
    int n;
    int t[2][101][101];

    int solveForAlice(vector<int>&piles,int person,int i ,int m){
        if(i>=n)
            return 0;
        
        if(t[person][i][m] != -1)
            return t[person][i][m];
        
        int stone = 0;
        int result = (person == 1)?-1:INT_MAX;

        for(int x = 1;x <= min(2*m,n-i);x++){
            stone += piles[i+x-1];
            if(person == 1){
                //ALice
                result = max(result,stone+solveForAlice(piles,0,i+x,max(m,x)));
            }else{
                //Bob
                result = min(result,solveForAlice(piles,1,i+x,max(m,x)));
            }
        }
        return t[person][i][m] = result;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(t,-1,sizeof(t));
        return solveForAlice(piles,1,0,1);
    }
};
