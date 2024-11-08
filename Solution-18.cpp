#include <bits/stdc++.h>
using namespace std;

// A memoization table for digit DP
long long dp[20][2][1000];  // max 20 digits, tight condition, and product limit

// Recursive function for digit DP
long long countNumbersWithProduct(int pos, bool tight, long long product, const string &numStr, long long K) {
    if (product > K) return 0;  // If product exceeds K, it's invalid

    // Base case: if we processed all digits
    if (pos == numStr.size()) return 1;

    // Use memoization to avoid recalculating for the same state
    if (dp[pos][tight][product] != -1) return dp[pos][tight][product];

    int limit = tight ? numStr[pos] - '0' : 9;  // Set digit limit based on tightness
    long long result = 0;

    // Try all digits from 0 to limit
    for (int digit = 0; digit <= limit; ++digit) {
        // Avoid leading zeros by checking product = 1 (initial neutral product)
        if (digit == 0 && product == 1) {
            result += countNumbersWithProduct(pos + 1, tight && (digit == limit), 1, numStr, K);
        } else {
            result += countNumbersWithProduct(pos + 1, tight && (digit == limit), product * digit, numStr, K);
        }
    }
    dp[pos][tight][product] = result;
    return result;
}

// Wrapper function
long long solve(long long N, long long K) {
    string numStr = to_string(N); 
    memset(dp, -1, sizeof(dp));    
    return countNumbersWithProduct(0, 1, 1, numStr, K);
}
