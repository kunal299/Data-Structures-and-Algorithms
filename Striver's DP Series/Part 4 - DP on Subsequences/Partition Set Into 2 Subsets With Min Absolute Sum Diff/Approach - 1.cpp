/*
    Time Complexity-  O(n*k) + O(n) + O(n)
    Space Complexity - O(n*k) + O(n)

    where k is the total sum of elements in the arr
*/

bool helper(int idx, int target, vector<int> &arr, vector<vector<int>> &dp) {
    if(target==0) return dp[idx][target]=true;
    if(idx==0) return dp[idx][target]=target==arr[idx];
    if(dp[idx][target]!=-1) return dp[idx][target];
    
    int unpick = helper(idx-1, target, arr, dp);
    int pick = false;
    if(target-arr[idx]>=0) {
        pick = helper(idx-1, target-arr[idx], arr, dp);   
    }
    
    return dp[idx][target]=(pick or unpick);    
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
    int totSum = 0;
    for(int i=0; i<n; i++) {
        totSum += arr[i];
    }
    
    vector<vector<int>> dp(n, vector<int> (totSum+1, -1));
    for(int i=0; i<=totSum; i++) {
         bool tmp = helper(n-1, i, arr, dp);   
    }
    
    int mini = 1e9;
    for(int i=0; i<=totSum; i++) {
        if(dp[n-1][i]==true) {
            mini = min(mini, abs(i-(totSum-i)));
        }
    }
    
    return mini;
}