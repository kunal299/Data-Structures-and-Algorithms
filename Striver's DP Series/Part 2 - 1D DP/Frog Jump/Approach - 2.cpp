/*
    Time Complexity - O(n)
    Space Complexity - O(n)
*/

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    dp[0] = 0;
    
    for(int i=1; i<n; i++) {
        int jump1 = dp[i-1] + abs(heights[i]-heights[i-1]);
        int jump2 = INT_MAX;
        if(i>1) {
            jump2 = dp[i-2] + abs(heights[i]-heights[i-2]);
        }
        
        dp[i] = min(jump1, jump2);
    }
    
    return dp[n-1];
}