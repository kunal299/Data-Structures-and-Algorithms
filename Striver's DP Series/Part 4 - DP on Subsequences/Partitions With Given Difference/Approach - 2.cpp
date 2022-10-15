/*
    Time Complexity - O(n*k)
    Space Complexity - O(n*k)
*/

#include <bits/stdc++.h> 

int mod =(int)1e9+7;

int countPartitions(int n, int d, vector<int> &arr) {
    int totSum = 0;
    for(int i=0; i<n; i++) {
        totSum += arr[i];
    }
    
    if((totSum-d)<0 || (totSum-d)%2==1) {
        return 0;
    }
    
    int tmp = (totSum - d)/2;
    vector<vector<int>> dp(n, vector<int> (tmp+1, 0));
    
    if(arr[0]==0) dp[0][0] = 2;
    else dp[0][0] = 1;
    
    if(arr[0]!=0 && arr[0]<=tmp) dp[0][arr[0]] = 1;
    
    for(int idx=1; idx<n; idx++) {
        for(int tar=0; tar<=tmp; tar++) {
            
            int notPick = dp[idx-1][tar];
            int pick = 0;
            if(tar-arr[idx]>=0) {
                pick = dp[idx-1][tar-arr[idx]];
            }
            
            dp[idx][tar] = (notPick+pick)%mod;
        }
    }
    
    return dp[n-1][tmp]; 
}