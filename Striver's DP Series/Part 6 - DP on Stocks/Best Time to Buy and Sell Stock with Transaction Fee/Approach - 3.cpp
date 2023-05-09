/*
    Time Complexity - O(N*2)
    Space Complexity - O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<int> ahead(2, 0);
        vector<int> curr(2, 0);

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {

                int op1, op2;
                if(buy == 0) {
                    op1 = -prices[i] + ahead[1];
                    op2 = 0 + ahead[0];
                } else {
                    op1 = (prices[i]-fee) + ahead[0];
                    op2 = 0 + ahead[1];
                }

                curr[buy] = max(op1, op2);

            }
            ahead = curr;
        }
        return curr[0];
    }
};