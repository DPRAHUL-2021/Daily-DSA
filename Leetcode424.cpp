/*424. Longest Repeating Character Replacement

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length

*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,count=0,maxLen = 0;
        vector<int> hash(26);
        while(r<s.size()){
            hash[s[r] - 'A']++;
            count = max(count,hash[s[r] - 'A']);
            if((r-l+1) - count > k){
                hash[s[l] - 'A']--;
                l++;
            }
            maxLen = max(r-l+1,maxLen);
            r++;
        }
        return maxLen;
    }
};