/*
    Time Complexity - O(n*k)
    Space Complexity - O(n) + O(n*k)
*/

bool helper(int idx, int target, vector<int> &arr, vector<vector<int>> &dp) {
    if(target==0) return true;
    if(idx==0) {
        if(arr[idx]==target) {
            return true;
        } 
        return false;
    }
    if(dp[idx][target]!=-1) return dp[idx][target];
    
    bool unpick = helper(idx-1, target, arr, dp);
    bool pick = false;
    if(target-arr[idx]>=0) {
        pick = helper(idx-1, target-arr[idx], arr, dp);
    }
    
    return dp[idx][target] = unpick or pick;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int> (k+1, -1));
    return helper(n-1, k, arr, dp);
}