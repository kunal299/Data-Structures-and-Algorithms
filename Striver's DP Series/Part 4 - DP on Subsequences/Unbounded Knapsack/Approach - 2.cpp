/*
    Time Complexity - O(N*W)
    Space Complexity - O(N*W)
*/

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int> (W+1, 0));
        
        for(int i=0; i<=W; i++) {
            dp[0][i] = (i/wt[0])*val[0];
        }
        
        for(int idx=1; idx<N; idx++) {
            for(int w=0; w<=W; w++) {
                int notPick = dp[idx-1][w];
                int pick = 0;
                if(w-wt[idx] >= 0) {
                    pick = val[idx] + dp[idx][w-wt[idx]];
                }
                
                dp[idx][w] = max(notPick, pick);
            }
        }
        
        return dp[N-1][W];
    }
};