/*
    Time Complexity - O(n*k)
    Space Complexity - O(n*k) 
*/

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool> (k+1, 0));
    
    for(int idx=0; idx<n; idx++) {
        dp[idx][0] = true;
    }
    
    dp[0][arr[0]] = true;
    
    for(int idx=1; idx<n; idx++) {
        for(int target=1; target<=k; target++) {
            bool unpick = dp[idx-1][target];
            bool pick = false;
            if(target-arr[idx]>=0) {
                pick = dp[idx-1][target-arr[idx]];
            }
            
            dp[idx][target] = unpick or pick;
        }
    }
    
    return dp[n-1][k];
}