/*
    Time Complexity - O(n*m)
    Space Complexity - O(m)
*/

//Space Optimization
class Solution {
public:    
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> prev(m, 0);
        
        for(int i=0; i<n; i++) {
            vector<int> tmp(m, 0);
            
            for(int j=0; j<m; j++) {
                if(mat[i][j]==1) tmp[j] = 0;
                else if(i==0 && j==0) tmp[j] = 1;
                else {
                    int up = 0, left = 0;
                    
                    if(i>0) up = prev[j];
                    if(j>0) left = tmp[j-1];
                    
                    tmp[j] = (up+left);
                }
            }
            prev = tmp;
        }
        
        return prev[m-1];
    }
};