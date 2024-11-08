/*
76. Minimum Window Substring

Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()){
            return "";
        }
        unordered_map<char,int> mp;
        for(char c : t){
            mp[c]++;
        }
        int l=0,r=0,count = t.size(),minLen = INT_MAX,start = 0;
        while(r<s.size()){
            if(mp[s[r]] > 0){
                count--;
            }
            mp[s[r]]--;
            r++;

            while(count == 0){
                if(r-l < minLen){
                    minLen = r-l;
                    start = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0){
                    count++;
                }
                l++;
            }
        }
        if(minLen == INT_MAX){
            return "";
        }
        return s.substr(start,minLen);
    }
};