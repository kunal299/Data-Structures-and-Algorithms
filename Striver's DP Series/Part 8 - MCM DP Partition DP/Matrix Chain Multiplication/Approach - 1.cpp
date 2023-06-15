/*
    Time Complexity - O(N*N*N)
    Space Complexity - O(N*N) + O(N)
*/

class Solution{
public:
    int helper(int i, int j, int arr[], vector<vector<int>> &dp) {
        if(i==j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
                
        int mini = 1e9;
        for(int k=i; k<j; k++) {
            mini = min(mini, arr[i-1]*arr[k]*arr[j] + helper(i, k, arr, dp) + helper(k+1, j, arr, dp));
        }
        
        return dp[i][j]=mini;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int> (N+1, -1));
        return helper(1, N-1, arr, dp);
    }
};