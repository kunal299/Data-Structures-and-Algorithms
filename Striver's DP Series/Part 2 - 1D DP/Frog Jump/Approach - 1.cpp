/*
    Time Complexity - O(n)
    Space Complexity - O(n)
*/

int helper(int idx, vector<int> &heights, vector<int> &dp) {
    if(idx==0) return 0;
    if(dp[idx]!=-1) return dp[idx];
    
    int left = helper(idx-1, heights, dp) + abs(heights[idx]-heights[idx-1]);
    int right = INT_MAX;
    if(idx>1) {
        right = helper(idx-2, heights, dp) + abs(heights[idx]-heights[idx-2]);
    }
    
    return dp[idx]=min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    return helper(n-1, heights, dp);
}