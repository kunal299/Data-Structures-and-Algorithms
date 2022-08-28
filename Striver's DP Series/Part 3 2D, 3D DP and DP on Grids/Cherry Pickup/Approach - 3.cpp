//Space Optimization
class Solution {
public:
    int helper(int i1, int j1, int i2, int n, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
        int j2 = (i1 + j1) - i2;

        if(i1>=n || i2>=n || j1>=n || j2>=n || grid[i1][j1]==-1 || grid[i2][j2]==-1) return -1e8;
        
        if(i1==n-1 && j1==n-1) return grid[i1][j1];
        
        if(dp[i1][j1][i2] != -1) return dp[i1][j1][i2];
        
        int cherries = 0;
        if(i1==i2 && j1==j2) {
            cherries = grid[i1][j1];
        } else {
            cherries = grid[i1][j1] + grid[i2][j2];
        }
        
        int d1 = helper(i1+1, j1, i2+1, n, grid, dp);
        int d2 = helper(i1, j1+1, i2, n, grid, dp);
        int d3 = helper(i1+1, j1, i2, n, grid, dp);
        int d4 = helper(i1, j1+1, i2+1, n, grid, dp);
        
        cherries += max(max(d1, d2), max(d3, d4));
        return dp[i1][j1][i2] = cherries;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (n, -1)));
        
        return max(0, helper(0, 0, 0, n, grid, dp));
    }
};