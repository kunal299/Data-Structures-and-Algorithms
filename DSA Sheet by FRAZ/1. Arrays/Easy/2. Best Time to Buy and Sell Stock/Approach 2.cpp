/*
    Using an auxilliary vector to store the maximum price from the end to start
    Time Complexity - O(n)
    Space Complexity - O(n)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> aux(n, 0);
            
        int maxPrice = INT_MIN;
        for(int i=n-1; i>=0; i--) {
            maxPrice = max(maxPrice, prices[i]);
            aux[i] = maxPrice;
        }
        
        int maxProfit = 0;
        for(int i=0; i<n; i++) {
            maxProfit = max(maxProfit, aux[i]-prices[i]);
        }
        
        return maxProfit;
    }
};