/*
    Time Complexity - O(N*2)
    Space Complexity - O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> ahead1(2, 0);
        vector<int> ahead2(2, 0);
        vector<int> curr(2, 0);

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {

                int op1, op2;
                if(buy == 0) {
                    op1 = -prices[i] + ahead1[1];
                    op2 = 0 + ahead1[0];
                } else {
                    op1 = +prices[i] + ahead2[0];
                    op2 = 0 + ahead1[1];
                }

                curr[buy] = max(op1, op2);

            }
            ahead2 = ahead1;
            ahead1 = curr;
        }
        return curr[0];
    }
};