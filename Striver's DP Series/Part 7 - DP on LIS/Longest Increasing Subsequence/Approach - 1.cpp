/*
    Time Complexity - O(N*N)
    Space Complexity - O(N*N) + O(N)
*/

class Solution {
public:
    int helper(vector<int> &nums, int i, int prev, int n, vector<vector<int>> &dp) {
        if(i == n) return 0;

        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        int take = 0, notTake = 0;

        if(prev == -1 || nums[i] > nums[prev]) {
            take = 1 + helper(nums, i+1, i, n, dp);
        } 

        notTake = helper(nums, i+1, prev, n, dp); 

        return dp[i][prev+1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return helper(nums, 0, -1, n, dp);
    }
};