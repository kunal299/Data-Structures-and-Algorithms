/*
    Time Complexity - O(N*2)
    Space Complexity - O(2)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> next(2, -1), curr(2, -1);

        next[0] = next[1] = 0;

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {

                if(buy == 0) {
                    curr[buy] = max(0 + next[0], -prices[i] + next[1]);
                } else {
                    curr[buy] = max(0 + next[1], prices[i] + next[0]);
                }

            }
            next = curr;
        }

        return next[0];
    }
};