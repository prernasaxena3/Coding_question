//filling-bookcase-shelves

/*You are given an array books where books[i] = [thicknessi, heighti] indicates the thickness and height of the ith book. You are also given an integer shelfWidth.
We want to place these books in order onto bookcase shelves that have a total width shelfWidth.
We choose some of the books to place on this shelf such that the sum of their thickness is less than or equal to shelfWidth, 
then build another level of the shelf of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down. 
We repeat this process until there are no more books to place.
Note that at each step of the above process, the order of the books we place is the same order as the given sequence of books.
For example, if we have an ordered list of 5 books, we might place the first and second book onto the first shelf, the third book on the second shelf, and the fourth and fifth book on the last shelf.
Return the minimum possible height that the total bookshelf can be after placing shelves in this manner.*/

class Solution {
public:
   /* int n ;
    int width;
    int t[1001][1001];
    int solve(vector<vector<int>>& books,int i, int remainWidth,int maxht){
        if(i >= n){
            return maxht;
        }

        if(t[i][remainWidth] != -1) {
            return t[i][remainWidth];
        }
        int bookW = books[i][0];
        int bookH = books[i][1];

        int keep = INT_MAX;
        int skip = INT_MAX;

        //keep
        if(bookW <= remainWidth){
            keep = solve(books,i+1,remainWidth-bookW,max(maxht,bookH));
        }
        //skip
        skip = maxht + solve(books,i+1,width-bookW,bookH);

        return t[i][remainWidth] = min(keep,skip);
    }*/

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        /*memset(t,-1,sizeof(t));
        n = books.size();
        width = shelfWidth;
        int remainWidth = shelfWidth;
        return solve(books,0,remainWidth,0);*/

        //second approach
        int n = books.size();
        vector<int>mem(n+1,1000*1000);
        mem[0]=0;
        for(int i = 1;i<=n;i++){
            int w = 0,h = 0;
            for(int j = i-1;j>=0;j--){
                w += books[j][0];
                h = max(h,books[j][1]);

                if(w > shelfWidth) break;
                mem[i] = min(mem[i],mem[j]+h);
            }
        }
        return mem.back();
    }
};
