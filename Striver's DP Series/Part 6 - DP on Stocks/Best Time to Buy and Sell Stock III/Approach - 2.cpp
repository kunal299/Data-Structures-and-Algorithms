/*
    Time Complexity - O(N*2*3)
    Space Complexity - O(N*2*3)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                for(int cap=1; cap<=2; cap++) {

                    int op1, op2;
                    if(buy == 0) {
                        op1 = -prices[i] + dp[i+1][1][cap];
                        op2 = 0 + dp[i+1][0][cap];
                    } else {
                        op1 = +prices[i] + dp[i+1][0][cap-1];
                        op2 = 0 + dp[i+1][1][cap];
                    }

                    dp[i][buy][cap] = max(op1, op2);

                }
            }
        }
        return dp[0][0][2];
    }
};