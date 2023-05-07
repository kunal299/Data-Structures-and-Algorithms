/*
    Time Complexity - O(N*2)
    Space Complexity - O(N*2)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, -1));

        dp[n][0] = dp[n][1] = 0;

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {

                if(buy == 0) {
                    dp[i][buy] = max(0 + dp[i+1][0], -prices[i] + dp[i+1][1]);
                } else {
                    dp[i][buy] = max(0 + dp[i+1][1], prices[i] + dp[i+1][0]);
                }

            }
        }

        return dp[0][0];
    }
};