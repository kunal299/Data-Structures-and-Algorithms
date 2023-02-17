/*
    Time Complexity - O(N*W)
    Space Complexity - O(N*W) + O(N)
*/

class Solution{
public:
    int knapSackUtil(int idx, int W, int val[], int wt[], vector<vector<int>> &dp) {
        if(idx==0) {
            return (W/wt[0])*val[0];
        }
        
        if(dp[idx][W] != -1) return dp[idx][W];
        
        int notPick = knapSackUtil(idx-1, W, val, wt, dp);
        int pick = 0;
        if(W-wt[idx] >= 0) {
            pick = val[idx] + knapSackUtil(idx, W-wt[idx], val, wt, dp);
        }
        
        return dp[idx][W]=max(notPick, pick);
    }
    
    {
        vector<vector<int>> dp(N, vector<int> (W+1, -1));
        return knapSackUtil(N-1, W, val, wt, dp);
    }
};