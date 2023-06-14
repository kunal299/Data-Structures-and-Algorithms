/*
    Time Complexity - O(N * LogN)
    Space Complexity - O(N)
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1), hash(n, 1);
        int ans = -1, last_idx = 0;
        for(int i=0; i<n; i++) {
            hash[i] = i;
            for(int prev=0; prev<i; prev++) {
                if(nums[i]%nums[prev]==0 && dp[i] < 1 + dp[prev]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > ans) {
                ans = dp[i];
                last_idx = i;
            }
        }
        
        vector<int> res;
        res.push_back(nums[last_idx]);
        
        while(hash[last_idx] != last_idx) {
            last_idx = hash[last_idx];
            res.push_back(nums[last_idx]);
        }

        return res;
    }
};