//hand-of-straights
/*Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

Example 1:
Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // int n = hand.size();
        // if(groupSize%n != 0){
        //     return false;
        // }
        // return true;

        unordered_map<int, int> cnt;
        for (int& v : hand) ++cnt[v];
        sort(hand.begin(), hand.end());
        for (int& v : hand) {
            if (cnt.count(v)) {
                for (int x = v; x < v + groupSize; ++x) {
                    if (!cnt.count(x)) {
                        return false;
                    }
                    if (--cnt[x] == 0) {
                        cnt.erase(x);
                    }
                }
            }
        }
        return true;
    }
};
