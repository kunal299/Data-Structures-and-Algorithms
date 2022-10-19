/*
    Time Complexity - O(n*w)
    Space Complexity - O(w)
*/

#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<int> prev(maxWeight+1, 0);
    for(int i=weight[0]; i<=maxWeight; i++) {
        prev[i] = value[0];
    } 
    
    for(int idx=1; idx<n; idx++) {
        for(int w=maxWeight; w>=0; w--) {
            int notPick = 0 + prev[w];
            int pick = INT_MIN;
            if(w-weight[idx]>=0) {
                pick = value[idx] + prev[w-weight[idx]];
            }
            
            prev[w] = max(notPick, pick);
        }
    }
    
    return prev[maxWeight];
}