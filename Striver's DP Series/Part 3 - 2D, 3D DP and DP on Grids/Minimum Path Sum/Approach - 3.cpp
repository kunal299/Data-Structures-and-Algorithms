/*
    Time Complexity - O(m*n)
    Space Complexity - O(n)
*/

//Space Optimization
class Solution {
public:    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> prev(n, 0);
        
        for(int i=0; i<m; i++) {
            vector<int> tmp(n, 0);
            
            for(int j=0; j<n; j++) {
                
                if(i==0 && j==0) {
                    tmp[0] = grid[0][0];
                    continue;
                }
                
                int up = 1e9, left = 1e9;
                if(i>0) {
                    up = grid[i][j] + prev[j];
                } 
                
                if(j>0) {
                    left = grid[i][j] + tmp[j-1];
                }
                
                tmp[j] = min(up, left);
            }
            prev = tmp;
        }
        
        return prev[n-1];
    }
};