//3016 - minimum-number-of-pushes-to-type-word-ii

/*You are given a string word containing lowercase English letters.
Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. 
For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .
It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. 
The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.
Return the minimum number of pushes needed to type word after remapping the keys.
An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters.*/

class Solution {
public:
    int minimumPushes(string word) {
        int arr[26];
        //To calculate frequency
        for(char ch : word){
            arr[ch-'a']++;
        }
        sort(arr,arr+26);
        int count = 0;
        int minKeyPress = 0;
        for(int i = 25;i>=0;i--){
            // int mul = 0;
            // if(count<8){
            //     mul = 1;
            // }else if(count<16){
            //     mul = 2;
            // }else if(count < 24){
            //     mul = 3;
            // }else{
            //     mul = 4;
            // }
            // int value = arr[i]*mul;
            int value = arr[i]*(count/8 +1);
            minKeyPress += value;
            count++;
        }
        return minKeyPress;
    }
};
