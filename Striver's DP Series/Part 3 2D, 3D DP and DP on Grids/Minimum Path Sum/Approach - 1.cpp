/*
    Time Complexity - O(m*n)
    Space Complexity - O(m-1 + n-1) + O(m*n)
*/

//Memoization
class Solution {
public:
    int helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];
            
        return dp[i][j] = min(grid[i][j]+helper(i-1, j, grid, dp), grid[i][j]+helper(i, j-1, grid, dp));
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return helper(m-1, n-1, grid, dp);
    }
};