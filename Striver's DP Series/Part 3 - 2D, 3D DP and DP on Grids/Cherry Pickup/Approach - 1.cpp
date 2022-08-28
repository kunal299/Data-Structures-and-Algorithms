//Using Bactracking
class Solution {
public:
    void helper1(int i, int j, int sum, int &ans, int n, vector<vector<int>> &grid) {
        if(i>=n || j>=n || grid[i][j]==-1) return;
        
        if(i==n-1 && j==n-1) {
            helper2(i, j, sum, ans, n, grid);
        }
        
        int cherries = grid[i][j];
        grid[i][j] = 0;
        helper1(i+1, j, sum+cherries, ans, n, grid);
        helper1(i, j+1, sum+cherries, ans, n, grid);
        grid[i][j] = cherries;
    }
    
    void helper2(int i, int j, int sum, int &ans, int n, vector<vector<int>> &grid) {
        if(i<0 || j<0 || grid[i][j]==-1) return;
        
        if(i==0 && j==0) {
            ans = max(ans, sum);
            return;
        }
        
        int cherries = grid[i][j];
        grid[i][j] = 0;
        helper2(i-1, j, sum+cherries, ans, n, grid);
        helper2(i, j-1, sum+cherries, ans, n, grid);
        grid[i][j] = cherries;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        
        if(n==1) return grid[0][0];
        
        helper1(0, 0, 0, ans, n, grid);
        return ans;
    }
};