/*
    Time Complexity - O(n*m)
    Space Complexity - O(n-1 + m-1) + O(n*m)
*/

//Memoization
class Solution {
public:  
    int helper(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp) {
        if(i==0 && j==0) return 1;
        if(i<0 || j<0 || mat[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
    
        return dp[i][j]=helper(i-1, j, mat, dp) + helper(i, j-1, mat, dp);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        if(mat[0][0]==1) {
            return 0;
        }
        
        if(n==1 && m==1) {
            if(mat[0][0]==0){
                return 1;
            } else {
                return 0;
            }
        }
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n-1, m-1, mat, dp);
    }
};