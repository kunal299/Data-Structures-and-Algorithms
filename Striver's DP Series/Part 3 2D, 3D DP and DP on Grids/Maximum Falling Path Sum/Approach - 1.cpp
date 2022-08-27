/*
    Time Complexity - O(n*m)
    Space Complexity - O(n) + O(n*m)
*/

int helper(int i, int j, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    if(j<0 || j>m) return -1e9;
    if(i==0) return matrix[i][j];
    if(dp[i][j] != -1) return dp[i][j];
    
    int d = matrix[i][j] + helper(i-1, j, m, matrix, dp);
    int dl = matrix[i][j] + helper(i-1, j+1, m, matrix, dp);
    int dr = matrix[i][j] + helper(i-1, j-1, m, matrix, dp);
    
    return dp[i][j] = max(d, max(dl, dr));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> dp(n, vector<int> (m, -1));
    
    int maxi = -1e9;
    for(int j=0; j<m; j++) {9
        maxi = max(maxi, helper(n-1, j, m-1, matrix, dp));
    }
    
    return maxi;
}