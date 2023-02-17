/*
    Time Complexity - O(n*k)
    Space Complexity - O(n*k)
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int size = coins.size();

        vector<vector<long>> dp(size, vector<long> (amount+1, 0));

        for(int i=0; i<=amount; i++) {
            if(i%coins[0]==0) {
                dp[0][i] = 1;
            }
        }

        for(int idx=1; idx<size; idx++) {
            for(int tar=0; tar<=amount; tar++) {
                long notPick = dp[idx-1][tar];
                long pick = 0;
                if(tar-coins[idx] >= 0) {
                    pick = dp[idx][tar-coins[idx]];
                }

                dp[idx][tar] = notPick+pick;
            }
        }
       
        return dp[size-1][amount];
    }
};