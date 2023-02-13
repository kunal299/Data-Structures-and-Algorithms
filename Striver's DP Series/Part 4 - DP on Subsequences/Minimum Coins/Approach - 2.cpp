/*
    Time Complexity - O(n*target)
    Space Complexity - O(n*target)
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();

        vector<vector<int>> dp(size, vector<int> (amount+1, 0));
        
        for(int i=0; i<=amount; i++) {
            if(i%coins[0] == 0) {
                dp[0][i] = i/coins[0];
            } else {
                dp[0][i] = 1e9;
            }
        }
        
        for(int i=1; i<size; i++) {
            for(int j=0; j<=amount; j++) {

                int notTaken = dp[i-1][j];
                int taken = 1e9;
                if(coins[i] <= j) {
                    taken = 1 + dp[i][j-coins[i]];
                }

                dp[i][j] = min(notTaken, taken);
            }
        }

        if(dp[size-1][amount] >= 1e9) {
            return -1;
        }

        return dp[size-1][amount];
    }
};