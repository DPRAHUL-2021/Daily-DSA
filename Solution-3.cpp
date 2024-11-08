#include<bits/stdc++.h>
using namespace std;

int decodeNum(const string& s) {
    if (s.empty() || s[0] == '0') return 0;  // If the string is empty or starts with '0', there are no ways to decode it.

    int n = s.size();
    vector<int> dp(n + 1, 0);  // Create a DP array of size n+1, initialized to 0
    dp[0] = 1;  // Base case: an empty string has one way to be decoded

    for (int i = 1; i <= n; ++i) {
        // Single digit decode (1 to 9)
        if (s[i - 1] != '0') {
            dp[i] += dp[i - 1];
        }

        // Two digit decode (10 to 26)
        if (i > 1) {
            int twoDigit = stoi(s.substr(i - 2, 2));  // Extract the last two characters as a number
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }
    }
    return dp[n];  // The answer is the number of ways to decode the entire string
}