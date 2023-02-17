/*
    Time Complexity - O(n*n)
    Space Complexity - O(n*n) + O(n)
*/

class Solution{
  public:
    int cutRodUtil(int idx, int n, int price[], vector<vector<int>> &dp) {
        if(idx==0) {
            return price[0]*n;
        }
        
        if(dp[idx][n] != -1) return dp[idx][n];
        
        int notTaken = cutRodUtil(idx-1, n, price, dp);
        int taken = 0;
        
        int rodLength = idx+1;
        if(n-rodLength >= 0) {
            taken = price[idx] + cutRodUtil(idx, n-rodLength, price, dp);   
        }
        
        return dp[idx][n]=max(notTaken, taken);
    }
  
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return cutRodUtil(n-1, n, price, dp);
    }
};