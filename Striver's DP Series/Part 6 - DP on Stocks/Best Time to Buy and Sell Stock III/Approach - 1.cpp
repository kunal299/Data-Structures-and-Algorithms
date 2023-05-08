/*  
    Time Complexity - O(N*2*3)
    Space Complexity - O(N*2*3) + O(N) 
*/

class Solution {
public:
    int helper(vector<int> &prices, int i, int buy, int cap, int n, vector<vector<vector<int>>> &dp) {
        if(i == n || cap == 0) return 0;

        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];

        int op1, op2;
        if(buy == 0) {
            op1 = -prices[i] + helper(prices, i+1, 1, cap, n, dp);
            op2 = 0 + helper(prices, i+1, 0, cap, n, dp);
        } else {
            op1 = +prices[i] + helper(prices, i+1, 0, cap-1, n, dp);
            op2 = 0 + helper(prices, i+1, 1, cap, n, dp);
        }

        return dp[i][buy][cap] = max(op1, op2);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        return helper(prices, 0, 0, 2, n, dp);
    }
};