/*
    Time Complexity - O(N*2)
    Space Complexity - O(N*2) + O(N)
*/

class Solution {
public:
    int helper(vector<int> &prices, int i, int buy, int n, vector<vector<int>> &dp) {
        if(i==n) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        if(buy == 0) {
            return dp[i][buy] = max(0 + helper(prices, i+1, 0, n, dp), -prices[i] + helper(prices, i+1, 1, n, dp));
        } else {
            return dp[i][buy] = max(0 + helper(prices, i+1, 1, n, dp), prices[i] + helper(prices, i+1, 0, n, dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, -1));

        return helper(prices, 0, 0, n, dp);
    }
};