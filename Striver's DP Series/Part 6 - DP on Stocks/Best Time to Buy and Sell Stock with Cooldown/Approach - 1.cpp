/*
    Time Complexity - O(N*2)
    Space Complexity - O(N*2) + O(N)
*/

class Solution {
public:
    int helper(vector<int> &prices, int i, int buy, int n, vector<vector<int>> &dp) {
        if(i >= n) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        int op1, op2;
        if(buy == 0) {
            op1 = -prices[i] + helper(prices, i+1, 1, n, dp);
            op2 = 0 + helper(prices, i+1, 0, n, dp);
        } else {
            op1 = +prices[i] + helper(prices, i+2, 0, n, dp);
            op2 = 0 + helper(prices, i+1, 1, n, dp);
        }

        return dp[i][buy] = max(op1, op2);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int> (2, -1));
        return helper(prices, 0, 0, n, dp);
    }
};