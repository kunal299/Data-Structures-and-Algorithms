/*
    Time Complexity - O(n*k)
    Space Complexity - O(n*k) + O(n)
*/

class Solution {
public:
    int helper(int idx, int target, vector<int> &coins, vector<vector<long>> &dp) {
        if(idx==0) {
            return (target%coins[0]==0);
        }

        if(dp[idx][target] != -1) return dp[idx][target];

        long notPick = helper(idx-1, target, coins, dp);
        long pick = 0;
        if(target-coins[idx] >= 0) {
            pick = helper(idx, target-coins[idx], coins, dp);
        }

        return dp[idx][target]=(notPick+pick);
    }

    int change(int amount, vector<int>& coins) {
        int size = coins.size();

        vector<vector<long>> dp(size, vector<long> (amount+1, -1));

        int noOfComb = helper(size-1, amount, coins, dp);
        return noOfComb;
    }
};