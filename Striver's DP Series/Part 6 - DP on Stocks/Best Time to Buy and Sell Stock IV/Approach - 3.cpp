/*
    Time Complexity - O(N*2*K)
    Space Complexity - O(K)
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> ahead(2, vector<int> (k+1, 0));
        vector<vector<int>> curr(2, vector<int> (k+1, 0));

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                for(int cap=1; cap<=k; cap++) {

                    int op1, op2;
                    if(buy == 0) {
                        op1 = -prices[i] + ahead[1][cap];
                        op2 = 0 + ahead[0][cap];
                    } else {
                        op1 = +prices[i] + ahead[0][cap-1];
                        op2 = 0 + ahead[1][cap];
                    }

                    curr[buy][cap] = max(op1, op2);

                }
                ahead = curr;
            }
        }
        return ahead[0][k];
    }
};