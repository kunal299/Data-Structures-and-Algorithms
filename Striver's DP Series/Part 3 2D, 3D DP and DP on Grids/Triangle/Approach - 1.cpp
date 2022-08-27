/* 
    Time Complexity - O(m*m)
    Space Complexity - O(m) + O(m*m)
*/

class Solution {
public:
    int helper(int i, int j, int m, vector<vector<int>> &triangle, vector<vector<int>> &dp) {
        if(i==m-1) return triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        
        return dp[i][j] = min(triangle[i][j] + helper(i+1, j, m, triangle, dp), triangle[i][j] + helper(i+1, j+1, m, triangle, dp));
    }
        
    int minimumTotal(vector<vector<int>>& triangle) {   
        int m = triangle.size();
        
        vector<vector<int>> dp(m, vector<int> (m, -1));
        return helper(0, 0, m, triangle, dp);
    }
};