/*
    Time Complexity - O(n*m)
    Space Complexity - O(n*m)
*/

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> dp(n, vector<int> (m, -1));
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            
            if(i==0) {
                dp[i][j] = matrix[i][j];
            } else {
                
                int d = matrix[i][j] + dp[i-1][j];
                int dl = -1e9, dr = -1e9;
                
                if(j+1<m) {
                    dl = matrix[i][j] + dp[i-1][j+1];
                }
                
                if(j-1>=0) {
                    dr = matrix[i][j] + dp[i-1][j-1];
                }
                
                dp[i][j] = max(d, max(dl, dr));
            }
        }
    }
    
    int maxi = -1e9;
    for(int j=0; j<m; j++) {
        maxi = max(maxi, dp[n-1][j]);
    }
    
    return maxi;
}