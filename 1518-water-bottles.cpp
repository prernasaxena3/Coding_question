//water-bottles

/*There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle.
The operation of drinking a full water bottle turns it into an empty bottle.
Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.*/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        //wrong approach
        // int ans = numBottles + 1 + (numBottles/numExchange);
        // int remain = numBottles%numExchange;
        // while(remain > 0){
        // if(remain > numExchange){
        //     ans += remain/numExchange;
        // }
        // remain %= numExchange;
        // }
        // return ans;

        //3ms 
        /*int ans = 0;
        int remain = 0;
        while(numBottles){
            ans += numBottles;
            int total = numBottles + remain;
            numBottles = total/numExchange;
            remain = total%numExchange;
        }
        return ans; */

        //0ms  -- O(log(numBottles))
        int ans = numBottles;
        while(numBottles >= numExchange){
            ans += numBottles/numExchange;
            numBottles = numBottles/numExchange + numBottles%numExchange;
        }
        return ans;
    }
};
