/*
    //Using a trick in a single for loop
    Time Complexity - O(n)
    Space Complexity - O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int profit = 0;
        
        for(int i=0; i<prices.size(); i++) {
            min_price = min(min_price, prices[i]); //Storing the minimum price so far
            profit = max(profit, prices[i]-min_price); //Storing the maximum profit so far
        }
        
        return profit;
    }
};