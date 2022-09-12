/*
    Time Complexity - O(n*k)
    Space Complexity - O(n*k) + O(n)

    where k is the target value
*/

int helper(int idx, int target, vector<int> &num, vector<vector<int>> &dp) {
    if(target<0) return 0;
    if(idx==-1) {
        if(target==0) {
            return 1;
        }
        return 0;
    }
    if(dp[idx][target]!=-1) return dp[idx][target];
    
    int unpick = helper(idx-1, target, num, dp);
    int pick = 0;
    if(target-num[idx]>=0) {
        pick = helper(idx-1, target-num[idx], num, dp);
    }
    
    return dp[idx][target]=unpick+pick;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    
    vector<vector<int>> dp(n, vector<int> (tar+1, -1));
    return helper(n-1, tar, num, dp);
}