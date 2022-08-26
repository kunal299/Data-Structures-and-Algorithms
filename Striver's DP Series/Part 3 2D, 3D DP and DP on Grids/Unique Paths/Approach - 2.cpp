/*
    Time Complexity - O(n*m)
    Space Complexity - o(n*m)
*/

class Solution {
public:
    int solve(int m, int n, vector<vector<int>> &dp) {
        
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                
                if(i==0 && j==0) {
                    dp[i][j] = 1;
                    continue;
                }
                
                int up = 0, left = 0; 
                if(i>0) {
                    up = dp[i-1][j];
                } 
                if(j>0) {
                    left = dp[i][j-1];
                }
                
                dp[i][j] = (up+left);
            }
        }
        
        return dp[m][n];
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(m-1, n-1, dp);
    }
};