/*
    Time Complexity - O(n*n)
    Space Complexity - O(n*n)
*/

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        
        for(int i=0; i<=n; i++) {
            dp[0][i] = price[0]*i;
        }
        
        for(int idx=1; idx<n; idx++) {
            for(int N=0; N<=n; N++) {
                int notTaken = dp[idx-1][N];
                int taken = 0;
        
                int rodLength = idx+1;
                if(N-rodLength >= 0) {
                    taken = price[idx] + dp[idx][N-rodLength];   
                }
                
                dp[idx][N] = max(notTaken, taken);
            }
        }
        
        return dp[n-1][n];
    }
};