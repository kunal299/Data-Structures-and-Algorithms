/*
    Time Complexity - O(n*target)
    Space Complexity - O(target)
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();

        vector<int> prev(amount+1, -1), curr(amount+1, -1);
        
        for(int i=0; i<=amount; i++) {
            if(i%coins[0] == 0) {
                prev[i] = i/coins[0];
            } else {
                prev[i] = 1e9;
            }
        }
        
        for(int i=1; i<size; i++) {
            for(int j=0; j<=amount; j++) {

                int notTaken = prev[j];
                int taken = 1e9;
                if(coins[i] <= j) {
                    taken = 1 + curr[j-coins[i]];
                }

                curr[j] = min(notTaken, taken);
            }
            prev = curr;
        }

        if(prev[amount] >= 1e9) {
            return -1;
        }

        return prev[amount];
    }
};