/*
    Time Complexity - O(m*n)
    Space Complexity - O(m*n)
*/

class Solution {
public:
    int helper(int s, int e, int m, int n, vector<vector<int>>& dp) {
        if(s==m && e==n) {
            return 1;
        }
        
        if(s>m || e>n) {
            return 0;
        } 
        
        if(dp[s][e]!=-1) {
            return dp[s][e];
        }
        
        return dp[s][e] = helper(s+1, e, m, n, dp) + helper(s, e+1, m, n, dp);
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(0, 0, m-1, n-1, dp);
    }
};