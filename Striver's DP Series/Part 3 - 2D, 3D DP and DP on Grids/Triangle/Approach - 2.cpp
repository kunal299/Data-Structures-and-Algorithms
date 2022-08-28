/*
    Time Complexity - O(m*m)
    Space Complexity - O(m*m)
*/

class Solution {
public:    
    int minimumTotal(vector<vector<int>>& triangle) {   
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int> (m, 0));
        
        for(int j=0; j<m; j++) {
            dp[m-1][j] = triangle[m-1][j];
        }
        
        for(int i=m-2; i>=0; i--) {
            for(int j=i; j>=0; j--) {
                dp[i][j] = min(triangle[i][j] + dp[i+1][j], triangle[i][j] + dp[i+1][j+1]);
            }
        }
        
        return dp[0][0];
    }
};