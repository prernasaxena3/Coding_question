//Question - 205 leetcode Isomorphic Strings
// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char, char> charMapS, charMapT;

        for (int i = 0; i < s.length(); ++i) {
            char charS = s[i];
            char charT = t[i];

            // Check if mappings are consistent for both strings
            if (charMapS.count(charS) > 0) {
            if (charMapS[charS] != charT) {
                return false;
            }
            } else if (charMapT.count(charT) > 0) {
            if (charMapT[charT] != charS) {
                return false;
            }
            } else {
            // New mapping, assign characters to each other
            charMapS[charS] = charT;
            charMapT[charT] = charS;
            }
        }
        return true;
    }
};