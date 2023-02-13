/*
    Time Complexity - O(n*target)
    Space Complexity - O(n*target) + O(n)
*/

class Solution {
public:
    int findMin(int idx, int target, vector<int> &coins, vector<vector<int>> &dp) {
        if(idx==0) {
            if(target%coins[idx] == 0) {
                return target/coins[idx];
            } else {
                return 1e9;
            }
        }

        if(dp[idx][target] != -1) return dp[idx][target];

        int notTaken = findMin(idx-1, target, coins, dp);
        int taken = 1e9;

        if(coins[idx] <= target) {
            taken = 1 + findMin(idx, target-coins[idx], coins, dp);
        }

        return dp[idx][target]=min(notTaken, taken);
    }

    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();

        vector<vector<int>> dp(size, vector<int> (amount+1, -1));
        
        int minCoins = findMin(size-1, amount, coins, dp);
        if(minCoins >= 1e9) {
            return -1;
        }

        return minCoins;
    }
};