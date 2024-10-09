/*
1248. Count Number of Nice Subarrays

Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
 

Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length
*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSubArrays(vector<int>& nums, int k){
        int l=0,r=0,sum=0,count=0;
        while(r<nums.size()){
            sum = sum + (nums[r] % 2);
            while(sum > k){
                sum = sum - (nums[l] % 2);
                l++;
            }
            count = count + (r-l+1);
            r++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return countSubArrays(nums,k) - countSubArrays(nums,k-1);
    }
};