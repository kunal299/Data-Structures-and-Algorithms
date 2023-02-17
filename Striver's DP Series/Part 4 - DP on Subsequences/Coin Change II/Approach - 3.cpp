/*
    Time Complexity - O(n*k)
    Space Complexity - O(k)
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int size = coins.size();

        vector<long> prev(amount+1, 0), curr(amount+1, 0);

        for(int i=0; i<=amount; i++) {
            if(i%coins[0]==0) {
                prev[i] = 1;
            }
        }

        for(int idx=1; idx<size; idx++) {
            for(int tar=0; tar<=amount; tar++) {
                long notPick = prev[tar];
                long pick = 0;
                if(tar-coins[idx] >= 0) {
                    pick = curr[tar-coins[idx]];
                }

                curr[tar] = notPick+pick;
            }
            prev = curr;
        }
       
        return prev[amount];
    }
};