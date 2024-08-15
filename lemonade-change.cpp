//lemonade-change

/*At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). 
Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. 
You must provide the correct change to each customer so that the net transaction is that the customer pays $5.
Note that you do not have any change in hand at first.
Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int countFive = 0,countTen = 0;
        for(int bill : bills){
            if(bill == 5){
                countFive++;
            }else if(bill == 10){
                if(countFive > 0){
                    countFive--;
                    countTen++;
                }else{
                    return false;
                }
            }else if(bill == 20){
                if(countFive > 0 && countTen > 0){
                    countFive--;
                    countTen--;
                }else if(countFive >= 3){
                    countFive -= 3;
                }else{
                    return false;
                }
            }
        }
        return true;


        // int countFive = 0;
        // int countTen = 0;
        // int countTwenty = 0;
        // bool possible = false;
        // for(int i = 0;i<bills.size();i++){
        //     if(bills[i]-5 == 0){
        //         countFive++;
        //     }else{
        //         // countFive--;
        //         if(bills[i] == 10){
        //             countTen++;
        //         }if(bills[i] == 20){
        //             countTwenty++;
        //         }
        //     }
        //         int temp = bills[i];
        //         if(temp/5 >= countFive){
        //             possible = true;
        //             countFive -= (temp/5);
        //         }else if(temp/10 >= countTen){
        //             possible = true;
        //             countTen -= (temp/10);
        //         }else if(temp/20 >= countTwenty){
        //             possible = true;
        //             countTwenty -= (temp/20);
        //         }else{
        //             possible = false;
        //         }
                
        // }
        // return possible;
    }
};
