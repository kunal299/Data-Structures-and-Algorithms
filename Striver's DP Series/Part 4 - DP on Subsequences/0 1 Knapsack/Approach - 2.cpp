/*
    Time Complexity - O(n*w)
    Space Complexity - O(n*w)
*/

#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n, vector<int> (maxWeight+1, 0));
    for(int i=weight[0]; i<=maxWeight; i++) {
        dp[0][i] = value[0];
    } 
    
    for(int idx=1; idx<n; idx++) {
        for(int w=0; w<=maxWeight; w++) {
            int notPick = 0 + dp[idx-1][w];
            int pick = INT_MIN;
            if(w-weight[idx]>=0) {
                pick = value[idx] + dp[idx-1][w-weight[idx]];
            }
            
            dp[idx][w] = max(notPick, pick);
        }
    }
    
    return dp[n-1][maxWeight];
}