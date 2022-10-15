/*
    Time Complexity - O(n*k)
    Space Complexity - O(n*k) + O(n)
*/

#include <bits/stdc++.h> 

int mod =(int)1e9+7;

int helper(int idx, int tar, vector<int> &arr, vector<vector<int>> &dp) {
    if(idx==0) {
        if(tar==0 && arr[0]==0) return 2;
        if(tar==arr[0] || tar==0) return 1;
        return 0;
    }
    
    if(dp[idx][tar]!=-1) return dp[idx][tar];
    
    int notPick = helper(idx-1, tar, arr, dp);
    int pick = 0;
    if(tar-arr[idx]>=0) {
        pick = helper(idx-1, tar-arr[idx], arr, dp);
    }
    
    return dp[idx][tar]=(pick+notPick)%mod;
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totSum = 0;
    for(int i=0; i<n; i++) {
        totSum += arr[i];
    }
    
    if((totSum-d)<0 || (totSum-d)%2==1) {
        return 0;
    }
    
    int tmp = (totSum - d)/2;
    vector<vector<int>> dp(n, vector<int> (tmp+1, -1));
    
    return helper(n-1, tmp, arr, dp);
}