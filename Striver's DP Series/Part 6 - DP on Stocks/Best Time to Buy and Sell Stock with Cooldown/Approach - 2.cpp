/*
    Time Complexity - O(N*2)
    Space Complexity - O(N*2)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n+2, vector<int> (2, 0));

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {

                int op1, op2;
                if(buy == 0) {
                    op1 = -prices[i] + dp[i+1][1];
                    op2 = 0 + dp[i+1][0];
                } else {
                    op1 = +prices[i] + dp[i+2][0];
                    op2 = 0 + dp[i+1][1];
                }

                dp[i][buy] = max(op1, op2);

            }
        }
        return dp[0][0];
    }
};