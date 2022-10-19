/*
    Time Complexity - O(n*w)
    Space Complexity - O(n*w) + O(n)
*/

#include <bits/stdc++.h> 

int helper(int idx, int w, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp) {
    if(idx==0) {
        if(w-weight[0]>=0) return value[0];
        else return 0;
    }
    
    if(dp[idx][w] != -1) return dp[idx][w];
    
    int notPick = 0 + helper(idx-1, w, weight, value, dp);
    int pick = INT_MIN;
    if(w-weight[idx]>=0) {
        pick = value[idx] + helper(idx-1, w-weight[idx], weight, value, dp);
    }
    
    return dp[idx][w]=max(notPick, pick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n, vector<int> (maxWeight+1, -1));
    return helper(n-1, maxWeight, weight, value, dp);
}