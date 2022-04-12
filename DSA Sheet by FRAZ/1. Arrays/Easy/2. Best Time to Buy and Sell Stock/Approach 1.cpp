/*
    Using 2 for loops
    Time Complexity - O(n^2)
    Space Complexity - O(1)

    It will most probably give a TLE 
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;

        //Buy loop
        for(int i=0; i<n; i++) {
            //Sell loop
            for(int j=i; j<n; j++) {
                maxProfit = max(maxProfit, prices[j]-prices[i]);
            }
        }
        
        return maxProfit;
    }
};